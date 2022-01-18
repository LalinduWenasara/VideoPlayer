#include "customvwidget.h"
#include <QKeyEvent>
#include <QMouseEvent>



customVWidget::customVWidget(QWidget* parent)
    : QVideoWidget(parent)
{
}

customVWidget::~customVWidget()
{
}

void customVWidget::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Escape)
        emit exitFromFS();
}

void customVWidget::mouseDoubleClickEvent(QMouseEvent*)
{
    if (isFullScreen())
        emit useFS();
    else
        emit exitFromFS();
}
