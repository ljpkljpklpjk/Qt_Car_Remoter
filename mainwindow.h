#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTimer>
#include <QPointF>
#include <QBitArray>
#include <QLabel>
#include <QPixmap>
#include <iostream>
#include <sstream>
#include <iomanip>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TimeOut();
    void processDatagrams();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    QTimer *tim;
};
#endif // MAINWINDOW_H
