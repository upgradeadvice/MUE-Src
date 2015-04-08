// Copyright (c) 2009-2015 Bitcoin Developers
// Copyright (c) 2014-2015 MonetaryUnit Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "miningpage.h"
#include "ui_miningpage.h"

#include "miner.h"

#include "core.h"
#include "main.h"
#include "net.h"
#include "checkpoints.h"

#include "util.h"
#include "monetaryunitgui.h"
#include "guiutil.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include "rpcserver.h"
#include "rpcclient.h"
#include "rpcprotocol.h"

#include <boost/thread.hpp>
#include <stdio.h>

#include "ui_interface.h"
#include "../base58.h"

extern json_spirit::Value GetNetworkHashPS(int lookup, int height);

MiningPage::MiningPage(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MiningPage),
        model(0)
{
    ui->setupUi(this);
    updateUI();
    startTimer(1500);
}

MiningPage::~MiningPage()
{
    delete ui;
}

void MiningPage::setModel(WalletModel *model)
{
    this->model = model;
}

void MiningPage::updateUI()
{
}

static QString formatHashrate(int64_t n)
{
    if (n == 0)
        return "0 H/s";

    int i = (int)floor(log(n)/log(1000));
    float v = n*pow(1000.0f, -i);

    QString prefix = "";
    if (i >= 1 && i < 9)
        prefix = " kMGTPEZY"[i];

    return QString("%1 %2H/s").arg(v, 0, 'f', 2).arg(prefix);
}

void MiningPage::timerEvent(QTimerEvent *)
{
    int64_t NetworkHashrate = GetNetworkHashPS(120, -1).get_int64();
    ui->labelNethashrate->setText(formatHashrate(NetworkHashrate));
}
