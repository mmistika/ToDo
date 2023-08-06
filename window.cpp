#include "window.h"
#include "./ui_window.h"

#include <QGraphicsDropShadowEffect>


Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    preconfigureUi();
}

Window::~Window()
{
    delete ui;
}

void Window::preconfigureUi()
{
    QWidgetList widgetList
    {
        ui->menuContainer,
        ui->searchMenuLineEdit,
        ui->hideMenuButton,
        ui->backMenuButton,
        ui->showMenuButton,
        ui->resetTagButton
    };

    setShadow(widgetList);
}

void Window::setShadow(QWidgetList &wgtList)
{
    for (auto wgt : wgtList) { setShadow(wgt); }
}

void Window::setShadow(QWidget *&wgt)
{
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;

    shadowEffect->setColor(QColor(99, 99, 99, 51));
    shadowEffect->setOffset(0, 1);
    shadowEffect->setBlurRadius(8);
    shadowEffect->setXOffset(0);

    wgt->setGraphicsEffect(shadowEffect);
}

