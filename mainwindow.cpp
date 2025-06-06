#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
#include <QImageReader>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    tim = new QTimer();
    tim->setInterval(100);
    connect(tim,SIGNAL(timeout()),this,SLOT(on_TimeOut()));
    tim->start();
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::processDatagrams);
    udpSocket->bind(QHostAddress::Any, 30000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString formatSignedInt(int num,int i) {
    std::ostringstream oss;
    if (num >= 0) {
        oss << '+'; // 保留正号
    }
    else if(num<0){
        oss << '-';
    }
    oss << std::setw(i) << std::setfill('0') << std::abs(num);
    return QString::fromStdString(oss.str());
}

void MainWindow::on_TimeOut()  //定时广播
{
    extern QPointF Pos_Knob;
    int x;
    int y;
    int z;
    QString targetIP = ui->targetIpEdit->text();
    quint16 targetPort = 40000;
    x=-((Pos_Knob.x()-125)/115*50);
    y=-((Pos_Knob.y()-125)/115*50);
    z=-(ui->controlSlider->value());
    QString control_code = "vx:"+formatSignedInt(y,2)+"vy:"+formatSignedInt(x,2)+"vw:"+formatSignedInt(z,3);
    //qDebug() <<"控制码： " << control_code;
    udpSocket->writeDatagram(control_code.toUtf8(), QHostAddress(targetIP), targetPort);
}

void MainWindow::processDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        QHostAddress addr;
        quint16 port;
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size(),&addr,&port);
        //qDebug()<<QString::number(port);
        if(port==50000)
        {
            QString dat = QString::fromUtf8(datagram);
            qDebug()<<"dat:"<<dat;
            QString wsd[2];
            wsd[0]=dat.mid(0,4);
            wsd[1]=dat.mid(4);
            ui->label_wd->setText(wsd[0]);
            ui->label_sd->setText(wsd[1]);
        }
        else if(port==20000)
        {
            QPixmap pixmap;
            if (pixmap.loadFromData(datagram, "JPEG")) {
                ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
            } else {
                qWarning() << "Failed to load image data!";
            }
        }
    }
}

