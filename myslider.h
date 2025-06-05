#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QObject>
#include <QSlider>

class MySlider : public QSlider
{
public:
    MySlider(QWidget *parent = nullptr);
    ~MySlider();
    void mousePressEvent(QMouseEvent *ev);
    //void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // MYSLIDER_H
