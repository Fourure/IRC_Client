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
    ui->textEdit->setText(ui->textEdit->toPlainText().append(ui->lineEdit->text()));
    ui->lineEdit->clear();
}

void Widget::on_pushButton_Connect_clicked()
{
    if(!ui->lineEdit_Username->text().isEmpty()){
        username = ui->lineEdit_Username->text();
        ui->stackedWidget->setCurrentIndex(0);
    }

    //Test git : push avec Qt creator
}
