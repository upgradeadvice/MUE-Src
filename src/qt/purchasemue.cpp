#include "purchasemue.h"
#include "ui_purchasemue.h"
#include "main.h"
#ifdef ENABLE_WALLET
#include "wallet.h"
#endif
#include "clientmodel.h"

PurchaseMue::PurchaseMue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PurchaseMue)
{
    ui->setupUi(this);
}
void PurchaseMue::setModel(ClientModel *model)
{
    this->model = model;
}
PurchaseMue::~PurchaseMue()
{
    delete ui;
}
