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

protected:
    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent *event);

private:
    void preconfigureUi();
    void setupConnections();

    int _menuLeftOffset;
    void hideMenu();
    void showMenu();

    bool _isMaskUpdatedOnShow{false};
    void updateStackedWidgetMasks();

private:
    Ui::Window *ui;
};
#endif // WINDOW_H
