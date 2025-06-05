#include "joystick.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>

QPointF Pos_Knob;

Joystick::Joystick(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(250, 250);
    centerPos = QPointF(width() / 2, height() / 2);
    knobPos = centerPos;
    Pos_Knob=knobPos;
}

QSize Joystick::minimumSizeHint() const
{
    return QSize(250, 250);
}

QSize Joystick::sizeHint() const
{
    return QSize(250, 250);
}

void Joystick::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    radius = qMin(width(), height()) / 2 - 10;
    centerPos = QPointF(width() / 2, height() / 2);

    // Draw outer circle
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(200, 200, 200));
    painter.drawEllipse(centerPos, radius, radius);

    // Draw knob
    painter.setBrush(QColor(100, 100, 255));
    painter.drawEllipse(knobPos, radius / 4, radius / 4);
}

void Joystick::mousePressEvent(QMouseEvent *event)
{
    if (QLineF(event->pos(), knobPos).length() <= radius / 2) {
        dragging = true;
        updateKnobPosition(event->pos());
    }
    //qDebug() <<"摇杆坐标： " << knobPos.x()<< knobPos.y();
    Pos_Knob=knobPos;
}

void Joystick::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging) {
        updateKnobPosition(event->pos());
    }
    //qDebug() <<"摇杆坐标： " << knobPos.x()<< knobPos.y();
    Pos_Knob=knobPos;
}

void Joystick::mouseReleaseEvent(QMouseEvent *)
{
    dragging = false;
    knobPos = centerPos;
    update();
    emit positionChanged(0.0f, 0.0f);
    //qDebug() <<"摇杆坐标： " << knobPos.x()<< knobPos.y();
    Pos_Knob=knobPos;
}

void Joystick::updateKnobPosition(const QPoint &pos)
{
    QPointF offset = pos - centerPos;
    offset = limitToCircle(offset, radius);
    knobPos = centerPos + offset;
    update();
    emitNormalizedPosition();
}

QPointF Joystick::limitToCircle(const QPointF &point, float maxRadius)
{
    float length = std::sqrt(point.x() * point.x() + point.y() * point.y());
    if (length > maxRadius)
        return point * (maxRadius / length);
    return point;
}

void Joystick::emitNormalizedPosition()
{
    QPointF delta = knobPos - centerPos;
    float normX = delta.x() / radius;
    float normY = delta.y() / radius;
    emit positionChanged(normX, normY);
}
