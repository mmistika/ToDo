#include "cstackedwidget.h"

#include <QStackedLayout>

CStackedWidget::CStackedWidget(StackingMode stackingMode)
{
    _layout = static_cast<QStackedLayout*>(layout());
    setStackingMode(stackingMode);
}

void CStackedWidget::setStackingMode(StackingMode stackingMode)
{
    _layout->setStackingMode(static_cast<QStackedLayout::StackingMode>(stackingMode));
}

void CStackedWidget::setTopMost(QWidget *page)
{
    int index = indexOf(page);
    if (index != -1 and page != _topMostPage)
    {
        _topMostPage = page;
        _topMostPage->raise();
    }
}

void CStackedWidget::setTopMost(int index)
{
    setTopMost(widget(index));
}

void CStackedWidget::removeTopMost()
{
    _topMostPage = nullptr;
}

void CStackedWidget::raisePage(QWidget *page)
{
    int index = indexOf(page);
    if (index != -1 and index != currentIndex())
    {
        if (_topMostPage) page->stackUnder(_topMostPage);
        else page->raise();
    }
}

void CStackedWidget::raisePage(int index)
{
    QWidget *wgt = widget(index);
    if (wgt) raisePage(wgt);
}
