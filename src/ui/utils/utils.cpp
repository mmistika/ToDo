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

QRegion getRoundedRegion(QRect rect, int radius)
{
    if (!radius)
    {
        return QRegion(rect);
    }
    else if (radius == rect.width() / 2 and radius == rect.height() / 2)
    {
        return QRegion(rect, QRegion::Ellipse);
    }
    else
    {
        QRect hrRect = rect.marginsRemoved(QMargins(0, radius, 0, radius));
        QRect vrRect = rect.marginsRemoved(QMargins(radius, 0, radius, 0));

        int diameter = radius * 2;
        QRegion cornerTopLeft = QRegion(hrRect.x(), vrRect.y(), diameter, diameter, QRegion::Ellipse);
        QRegion cornerTopRight = cornerTopLeft.translated(vrRect.width(), 0);
        QRegion cornerBottomLeft = cornerTopLeft.translated(0, hrRect.height());
        QRegion cornerBottomRight = cornerTopRight.translated(0, hrRect.height());

        return QRegion()
               + hrRect
               + vrRect
               + cornerTopLeft
               + cornerTopRight
               + cornerBottomLeft
               + cornerBottomRight;
    }
}

}
