// Copyright (c) 2009-2015 Bitcoin Developers
// Copyright (c) 2014-2015 MonetaryUnit Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MONETARYUNITADDRESSVALIDATOR_H
#define MONETARYUNITADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class MonetaryUnitAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MonetaryUnitAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** MonetaryUnit address widget validator, checks for a valid monetaryunit address.
 */
class MonetaryUnitAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MonetaryUnitAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // MONETARYUNITADDRESSVALIDATOR_H
