// Copyright (c) 2009-2015 Bitcoin Developers
// Copyright (c) 2014-2015 MonetaryUnit Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MININGPAGE_H
#define MININGPAGE_H

#include <QDialog>
#include <memory>

#include "walletmodel.h"

class WalletModel;

namespace Ui {
    class MiningPage;
}

class MiningPage : public QDialog
{
    Q_OBJECT

public:
    explicit MiningPage(QWidget *parent = 0);
    ~MiningPage();

    void setModel(WalletModel *model);

    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
    */
    QWidget *setupTabChain(QWidget *prev);

private:
    Ui::MiningPage *ui;
    WalletModel *model;
    std::auto_ptr<WalletModel::UnlockContext> unlockContext;
    bool hasMiningprivkey;

    void restartMining(bool fGenerate);
    void timerEvent(QTimerEvent *event);
    void updateUI();

private slots:

    void changeNumberOfCores(int i);
    void switchMining();
};

#endif // MININGPAGE_H
