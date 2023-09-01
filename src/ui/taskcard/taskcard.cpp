#include "taskcard.h"
#include "./ui_taskcard.h"

TaskCard::TaskCard(const QString &text,
                   bool isCompleted,
                   bool isImportant,
                   QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TaskCard)
{
    ui->setupUi(this);

    ui->checkBox->setChecked(isCompleted);
    ui->importantCheckBox->setChecked(isImportant);

    ui->text->setText(text);
}

TaskCard::~TaskCard()
{
    delete ui;
}

void TaskCard::setupConnections()
{
    connect(ui->checkBox, &QCheckBox::clicked, this, [&](bool state)
            {
                emit this->completionChanged(state);
            });

    connect(ui->importantCheckBox, &QCheckBox::clicked, this, [&](bool state)
            {
                emit this->importanceChanged(state);
            });
}
