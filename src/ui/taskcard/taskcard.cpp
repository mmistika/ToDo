#include "taskcard.h"
#include "./ui_taskcard.h"

TaskCard::TaskCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TaskCard)
{
    ui->setupUi(this);

    connect(ui->importantCheckBox, &QCheckBox::clicked, this, [&](bool state)
            {
        emit this->importanceChanged(state);
    });

    connect(this, &TaskCard::importanceChanged, this, [&](bool state)
            {
        qDebug() << "emitted : " << state;
    });
}

TaskCard::~TaskCard()
{
    delete ui;
}

