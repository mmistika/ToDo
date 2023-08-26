#include "utils.h"

#include <QGraphicsDropShadowEffect>

namespace ui_utils
{

void setShadow(const QColor &color, const QPoint &offset, const int &blurRadius, QWidgetList &wgtList)
{
    for (auto wgt : wgtList) { setShadow(color, offset, blurRadius, wgt); }
}

void setShadow(const QColor &color, const QPoint &offset, const int &blurRadius, QWidget *wgt)
{
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;

    shadowEffect->setColor(color);
    shadowEffect->setOffset(offset.x(), offset.y());
    shadowEffect->setBlurRadius(blurRadius);

    wgt->setGraphicsEffect(shadowEffect);
}

}
