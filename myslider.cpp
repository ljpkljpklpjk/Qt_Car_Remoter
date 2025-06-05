#include "myslider.h"
#include <QMouseEvent>
#include <QDebug>

int slider_value;

MySlider::MySlider(QWidget *parent):QSlider (parent)
{

}

MySlider::~MySlider()
{

}

void MySlider::mousePressEvent(QMouseEvent *ev)
{
    int currentX = ev->pos().x();
    double per = currentX *1.0 /this->width();
    int value = per*(this->maximum() - this->minimum()) + this->minimum();
    //qDebug() << value;
    this->setValue(value);
    QSlider::mousePressEvent(ev);
}

//void MySlider::mouseReleaseEvent(QMouseEvent *)
//{
//    int value=0.5*(this->maximum() - this->minimum()) + this->minimum();
//    this->setValue(value);
//}
