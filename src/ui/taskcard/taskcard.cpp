#include "taskcard.h"
#include "./ui_taskcard.h"

TaskCard::TaskCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TaskCard)
{
    ui->setupUi(this);
}

TaskCard::~TaskCard()
{
    delete ui;
}
