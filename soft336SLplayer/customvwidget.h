#ifndef CUSTOMVWIDGET_H
#define CUSTOMVWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QVideoWidget>

class customVWidget : public QVideoWidget
{
    Q_OBJECT
public:
    customVWidget(QWidget* parent = 0);
    ~customVWidget();
signals:
    void exitFromFS();
    void useFS();
protected:
    void keyPressEvent(QKeyEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);
};

#endif // CUSTOMVWIDGET_H
