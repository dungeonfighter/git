#include "widget.h"
#include "ui_widget.h"
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QThread::sleep(3);//強制延遲3秒
    setWindowTitle("連播影像 1103105339 曾文輝");
    connect(timer, SIGNAL(timeout()), this, SLOT(showimage()));
    myImages.append(QImage(":/pics/1.jpg"));//存放圖片進List
    myImages.append(QImage(":/pics/2.jpg"));
    myImages.append(QImage(":/pics/3.jpg"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::showimage(){
    //連播影像
    if(a>=myImages.count())a=0;
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
