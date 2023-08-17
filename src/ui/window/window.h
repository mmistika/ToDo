#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private:
    void preconfigureUi();
    void setupConnections();

    void setShadow(const QColor &color, const QPoint &offset, const int &blurRadius, QWidget *wgt);
    void setShadow(const QColor &color, const QPoint &offset, const int &blurRadius, QWidgetList &wgtList);

    int _menuLeftOffset;
    void hideMenu();
    void showMenu();

private:
    Ui::Window *ui;
};
#endif // WINDOW_H
