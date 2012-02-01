#include "widget.h"
#include "ui_widget.h"

#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readFortune()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_send_clicked()
{
    Message m(username, ui->lineEdit->text());
    historique << m;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out << (quint16)0;
    out << m.toString();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    blockSize = 0;
    tcpSocket->write(block);

    ui->lineEdit->clear();
}

void Widget::on_pushButton_Connect_clicked()
{
    if(!ui->lineEdit_Username->text().isEmpty()){
        username = ui->lineEdit_Username->text();
        ui->stackedWidget->setCurrentIndex(0);

        blockSize = 0;
        tcpSocket->abort();
        tcpSocket->connectToHost("Localhost",58425);
    }
}

void Widget::readFortune()
 {
     QDataStream in(tcpSocket);
     in.setVersion(QDataStream::Qt_4_0);

     if (blockSize == 0) {
         if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
             return;

         in >> blockSize;
     }

     if (tcpSocket->bytesAvailable() < blockSize)
         return;
     //QString nextFortune;
       in >> currentFortune;

       //currentFortune = nextFortune;
       ui->textEdit->append(currentFortune);
       ui->pushButton_send->setEnabled(true);
       blockSize = 0;
 }

void Widget::displayError(QAbstractSocket::SocketError socketError)
 {
     switch (socketError) {
     case QAbstractSocket::RemoteHostClosedError:
         break;
     case QAbstractSocket::HostNotFoundError:
         QMessageBox::information(this, tr("Fortune Client"),
                                  tr("The host was not found. Please check the "
                                     "host name and port settings."));
         break;
     case QAbstractSocket::ConnectionRefusedError:
         QMessageBox::information(this, tr("Fortune Client"),
                                  tr("The connection was refused by the peer. "
                                     "Make sure the fortune server is running, "
                                     "and check that the host name and port "
                                     "settings are correct."));
         break;
     default:
         QMessageBox::information(this, tr("Fortune Client"),
                                  tr("The following error occurred: %1.")
                                  .arg(tcpSocket->errorString()));
     }
 }
