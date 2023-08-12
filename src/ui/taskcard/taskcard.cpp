#include "taskcard.h"
#include "./ui_taskcard.h"

TaskCard::TaskCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TaskCard)
{
    ui->setupUi(this);

    connect(ui->checkBox, &QCheckBox::clicked, this, [&](bool state)
            {
                emit this->completionChanged(state);
            });

    connect(ui->importantCheckBox, &QCheckBox::clicked, this, [&](bool state)
            {
                emit this->importanceChanged(state);
            });
}

TaskCard::~TaskCard()
{
    delete ui;
}

