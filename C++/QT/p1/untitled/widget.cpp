#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFileinfo>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    file=QFileDialog::getOpenFileName(this,"選擇圖檔");//選擇圖片
    QFileInfo info(file);//取檔案資訊
    srcimg.load(file);//讀到的檔案存QImage
    ui->lineEdit->setText(info.fileName());//取檔案名稱並顯示
    setWindowTitle(info.fileName());//設定視窗名稱
    ui->label->setGeometry(90,60,srcimg.width(),srcimg.height());
    ui->label->setPixmap(QPixmap::fromImage(srcimg));
    if(!srcimg.isNull()){
        QMessageBox::information(this,("Hello"),info.fileName());//訊息框
    }

}

void Widget::on_pushButton_2_clicked()
{
    //如果圖片存在，做灰階化
    if(!srcimg.isNull()){
        for(int i=0 ; i<srcimg.height();i++){
            for(int j=0 ; j<srcimg.width();j++){
                int r=qRed(srcimg.pixel(j,i));
                int g=qGreen(srcimg.pixel(j,i));
                int b=qBlue(srcimg.pixel(j,i));
                int gray=(r+g+b)/3;
                srcimg.setPixel(j,i,qRgb(gray,gray,gray));
            }
        }
        ui->label->setPixmap(QPixmap::fromImage(srcimg));

    }
}
