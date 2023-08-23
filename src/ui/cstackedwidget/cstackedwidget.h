#ifndef CSTACKEDWIDGET_H
#define CSTACKEDWIDGET_H

#include <QStackedWidget>

class QStackedLayout;

class CStackedWidget : public QStackedWidget
{
    Q_OBJECT

public:
    enum StackingMode {
        StackOne,
        StackAll
    };

public:
    CStackedWidget(StackingMode stackingMode);

    void setStackingMode(StackingMode stackingMode);

    void setTopMost(QWidget *page);
    void setTopMost(int index);
    void removeTopMost();

    void raisePage(QWidget *page);
    void raisePage(int index);

private:
    QStackedLayout *_layout{nullptr};

    QWidget *_topMostPage{nullptr};
};

#endif // CSTACKEDWIDGET_H
