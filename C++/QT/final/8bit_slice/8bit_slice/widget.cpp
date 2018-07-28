#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFileinfo>
#include <QtMath>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("位元切割");
    labelarray[0]=ui->label_2;
    labelarray[1]=ui->label_3;
    labelarray[2]=ui->label_4;
    labelarray[3]=ui->label_5;
    labelarray[4]=ui->label_6;
    labelarray[5]=ui->label_7;
    labelarray[6]=ui->label_8;
    labelarray[7]=ui->label_9;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString file=QFileDialog::getOpenFileName(this,"選擇圖檔");//選擇圖片
    srcimg.load(file);//讀到的檔案存QImage
    graysrc.load(file);
    for(int i=0 ; i<srcimg.height();i++){
        for(int j=0 ; j<srcimg.width();j++){
            int r=qRed(srcimg.pixel(j,i));
            int g=qGreen(srcimg.pixel(j,i));
            int b=qBlue(srcimg.pixel(j,i));
            int gray=(r+g+b)/3;
            graysrc.setPixel(j,i,qRgb(gray,gray,gray));
        }
    }

    ui->label->setGeometry(30,80,srcimg.width(),srcimg.height());
    ui->label->setPixmap(QPixmap::fromImage(srcimg));
    ui->label_10->setPixmap(QPixmap::fromImage(graysrc));
    QSize imageSize = QSize(srcimg.width(), srcimg.height());
    for(int i=0;i<=7;++i){
        myImages.append(QImage(imageSize, QImage::Format_Mono));
    }
    slice();
}

void Widget::slice()
{
    int i, j;
    MyByte Byte;
    bool bitPix;

    for(j=0; j<srcimg.height(); j++){
       for(i=0; i<srcimg.width(); i++){
           Byte.byte = qGray(srcimg.pixel(i, j));//0~255

           bitPix = (Byte.bit.bit0 == 1) ? 1: 0;
           myImages[0].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit1 == 1) ? 1: 0;
           myImages[1].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit2 == 1) ? 1: 0;
           myImages[2].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit3 == 1) ? 1: 0;
           myImages[3].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit4 == 1) ? 1: 0;
           myImages[4].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit5 == 1) ? 1: 0;
           myImages[5].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit6 == 1) ? 1: 0;
           myImages[6].setPixel(i, j, bitPix);

           bitPix = (Byte.bit.bit7 == 1) ? 1: 0;
           myImages[7].setPixel(i, j, bitPix);
       }
    }
    for(int i=0;i<=7;++i)labelarray[i]->setPixmap(QPixmap::fromImage(myImages[i]));
}
