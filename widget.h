#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
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

private:
    Ui::Widget *ui;
    QString username;
    QList<Message> historique;
};

#endif // WIDGET_H
