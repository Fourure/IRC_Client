#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_send_clicked()
{
    Message m(username, ui->lineEdit->text());
    historique << m;
    ui->textEdit->append(m.toString());
    ui->lineEdit->clear();
}

void Widget::on_pushButton_Connect_clicked()
{
    if(!ui->lineEdit_Username->text().isEmpty()){
        username = ui->lineEdit_Username->text();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

//Test git V2
