#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QWidget>
#include <QPointF>

class Joystick : public QWidget
{
    Q_OBJECT

public:
    explicit Joystick(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

signals:
    void positionChanged(float x, float y);  // x, y 在 [-1, 1] 范围内

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPointF centerPos;
    QPointF knobPos;
    bool dragging = false;
    float radius;

    QPointF limitToCircle(const QPointF &point, float maxRadius);
    void updateKnobPosition(const QPoint &pos);
    void emitNormalizedPosition();
};

#endif // JOYSTICK_H
