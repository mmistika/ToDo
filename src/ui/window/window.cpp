#include "window.h"
#include "./ui_window.h"

#include "../utils/utils.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    preconfigureUi();
    setupConnections();
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

    ui_utils::setShadow(QColor(99, 99, 99, 51),
              QPoint(0, 1),
              8,
              widgetList);

    // Add search icon for search QLineEdit
    ui->searchMenuLineEdit->addAction(QIcon(":/icons/search.svg"),
                                      QLineEdit::LeadingPosition);

    // Change clear icon of search QLineEdit
    ui->searchMenuLineEdit->findChild<QAction*>("_q_qlineeditclearaction")
        ->setIcon(QIcon(":/icons/clear.svg"));

    // Hide unnecessary buttons on start
    ui->backMenuButton->setVisible(false);
    ui->showMenuButton->setVisible(false);
}

void Window::setupConnections()
{
    connect(ui->hideMenuButton, &QPushButton::clicked, this, &Window::hideMenu);
    connect(ui->showMenuButton, &QPushButton::clicked, this, &Window::showMenu);
}

void Window::hideMenu()
{
    QMargins margins = ui->windowContentFrame->layout()->contentsMargins();

    _menuLeftOffset = margins.left();
    ui->windowContentFrame->layout()->setContentsMargins(0,
                                                         margins.top(),
                                                         margins.right(),
                                                         margins.bottom()
                                                         );
    ui->menuContainer->setVisible(false);
    ui->showMenuButton->setVisible(true);
}

void Window::showMenu()
{
    QMargins margins = ui->windowContentFrame->layout()->contentsMargins();

    ui->windowContentFrame->layout()->setContentsMargins(_menuLeftOffset,
                                                         margins.top(),
                                                         margins.right(),
                                                         margins.bottom()
                                                         );
    ui->menuContainer->setVisible(true);
    ui->showMenuButton->setVisible(false);
}
