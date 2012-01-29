#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
};

#endif // WIDGET_H
