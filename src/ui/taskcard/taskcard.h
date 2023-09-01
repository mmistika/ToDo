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
    TaskCard(const QString &text,
                      bool isCompleted = 0,
                      bool isImportant = 0,
                      QWidget *parent = nullptr);
    ~TaskCard();

signals:
    void completionChanged(bool state);
    void importanceChanged(bool state);

private:
    void setupConnections();

private:
    Ui::TaskCard *ui;
};

#endif // TASKCARD_H
