#ifndef TASKCARD_H
#define TASKCARD_H

#include <QFrame>

namespace Ui {
class TaskCard;
}

class TaskCard : public QFrame
{
    Q_OBJECT

public:
    explicit TaskCard(QWidget *parent = nullptr);
    ~TaskCard();

signals:
    void completionChanged(bool state);
    void importanceChanged(bool state);

private:
    Ui::TaskCard *ui;
};

#endif // TASKCARD_H
