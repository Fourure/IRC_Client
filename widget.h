#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QTcpSocket>
#include <QMessageBox>
#include "message.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_Connect_clicked();

    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    Ui::Widget *ui;
    QString username;
    QList<Message> historique;

    QTcpSocket *tcpSocket;
    QString currentFortune;
    quint16 blockSize;
};

#endif // WIDGET_H
