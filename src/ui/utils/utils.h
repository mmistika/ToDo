#ifndef UTILS_H
#define UTILS_H

#include <QWidget>

namespace ui_utils
{

void setShadow(const QColor &color, const QPoint &offset, const int &blurRadius, QWidget *wgt);
void setShadow(const QColor &color, const QPoint &offset, const int &blurRadius, QWidgetList &wgtList);

}

#endif // UTILS_H
