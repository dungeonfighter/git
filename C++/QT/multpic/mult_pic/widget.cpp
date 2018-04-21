#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(dos()));
    myImages.append(QImage(":/pics/1.jpg"));
    myImages.append(QImage(":/pics/2.jpg"));
    myImages.append(QImage(":/pics/3.jpg"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::dos(){

    if(a>=3)a=0;
    ui->label_2->setGeometry(90,60,myImages[a].width(),myImages[a].height());
    ui->label_2->setPixmap(QPixmap::fromImage(myImages[a]));
    ui->label->setText(QString::number(a));
    a++;

}

void Widget::on_pushButton_clicked()
{
    status=!status;
    if(status){
        timer->start(1000);
        ui->pushButton->setText("暫停");
    }
    else{
        timer->stop();
        ui->pushButton->setText("開始");
    }


}
