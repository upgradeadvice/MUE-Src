// Copyright (c) 2009-2015 Bitcoin Developers
// Copyright (c) 2014-2015 MonetaryUnit Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "monetaryunitunits.h"

#include <QStringList>

MonetaryUnitUnits::MonetaryUnitUnits(QObject *parent):
        QAbstractListModel(parent),
        unitlist(availableUnits())
{
}

QList<MonetaryUnitUnits::Unit> MonetaryUnitUnits::availableUnits()
{
    QList<MonetaryUnitUnits::Unit> unitlist;
    unitlist.append(MUE);
    unitlist.append(cMUE);
    unitlist.append(mMUE);
    return unitlist;
}

bool MonetaryUnitUnits::valid(int unit)
{
    switch(unit)
    {
    case MUE:
    case cMUE:
    case mMUE:
        return true;
    default:
        return false;
    }
}

QString MonetaryUnitUnits::name(int unit)
{
    switch(unit)
    {
    case MUE: return QString("MUE");
    case cMUE: return QString("cMUE");
    case mMUE: return QString::fromUtf8("mMUE");
    default: return QString("???");
    }
}

QString MonetaryUnitUnits::description(int unit)
{
    switch(unit)
    {
    case MUE: return QString("MonetaryUnits");
    case cMUE: return QString("Centum-MonetaryUnits (1 / 100)");
    case mMUE: return QString("Milli-MonetaryUnits (1 / 1,000)");
    default: return QString("???");
    }
}

qint64 MonetaryUnitUnits::factor(int unit)
{
    switch(unit)
    {
    case MUE:  return 100000;
    case cMUE: return 1000;
    case mMUE: return 100;
    default:   return 100000;
    }
}

qint64 MonetaryUnitUnits::maxAmount(int unit)
{
    switch(unit)
    {
    case MUE:  return Q_INT64_C(210000000);
    case cMUE: return Q_INT64_C(21000000000);
    case mMUE: return Q_INT64_C(210000000000);
    default:   return 0;
    }
}

int MonetaryUnitUnits::amountDigits(int unit)
{
    switch(unit)
    {
    case MUE: return 17; // trillions (# digits, without commas)
    case cMUE: return 19; // *100
    case mMUE: return 20; // *1,000
    }
}

int MonetaryUnitUnits::decimals(int unit)
{
    switch(unit)
    {
    case MUE: return 8;
    case cMUE: return 3;
    case mMUE: return 2;
    default: return 0;
    }
}

QString MonetaryUnitUnits::format(int unit, qint64 n, bool fPlus)
{
    // Note: not using straight sprintf here because we do NOT want
    // localized number formatting.
    if(!valid(unit))
        return QString(); // Refuse to format invalid unit
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);
    qint64 n_abs = (n > 0 ? n : -n);
    qint64 quotient = n_abs / coin;
    qint64 remainder = n_abs % coin;
    QString quotient_str = QString::number(quotient);
    QString remainder_str = QString::number(remainder).rightJustified(num_decimals, '0');

    // Right-trim excess zeros after the decimal point
    int nTrim = 0;
    for (int i = remainder_str.size()-1; i>=2 && (remainder_str.at(i) == '0'); --i)
        ++nTrim;
    remainder_str.chop(nTrim);

    if (n < 0)
        quotient_str.insert(0, '-');
    else if (fPlus && n > 0)
        quotient_str.insert(0, '+');
    return quotient_str + QString(".") + remainder_str;
}

QString MonetaryUnitUnits::formatWithUnit(int unit, qint64 amount, bool plussign)
{
    return format(unit, amount, plussign) + QString(" ") + name(unit);
}

bool MonetaryUnitUnits::parse(int unit, const QString &value, qint64 *val_out)
{
    if(!valid(unit) || value.isEmpty())
        return false; // Refuse to parse invalid unit or empty string
    int num_decimals = decimals(unit);
    QStringList parts = value.split(".");

    if(parts.size() > 2)
    {
        return false; // More than one dot
    }
    QString whole = parts[0];
    QString decimals;

    if(parts.size() > 1)
    {
        decimals = parts[1];
    }
    if(decimals.size() > num_decimals)
    {
        return false; // Exceeds max precision
    }
    bool ok = false;
    QString str = whole + decimals.leftJustified(num_decimals, '0');

    if(str.size() > 18)
    {
        return false; // Longer numbers will exceed 63 bits
    }
    qint64 retvalue = str.toLongLong(&ok);
    if(val_out)
    {
        *val_out = retvalue;
    }
    return ok;
}

int MonetaryUnitUnits::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return unitlist.size();
}

QVariant MonetaryUnitUnits::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= 0 && row < unitlist.size())
    {
        Unit unit = unitlist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(name(unit));
        case Qt::ToolTipRole:
            return QVariant(description(unit));
        case UnitRole:
            return QVariant(static_cast<int>(unit));
        }
    }
    return QVariant();
}
