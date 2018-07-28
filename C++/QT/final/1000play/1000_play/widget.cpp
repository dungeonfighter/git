#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showimage()));
    setWindowTitle("心臟病播放器");
    logo.load(":/lo/logo.jpg");
}

Widget::~Widget()
{
    delete ui;
}

QImage Widget::water(QImage &test)
{
    int gray ,r,g,b,temx,temy;
    int cirx=43;//圓心大略座標
    int ciry=39;

    for(int i=0;i<logo.height();i++){
        for(int j=0;j<logo.width();j++){
            gray=qGray(logo.pixel(j,i));
            temx=(cirx-j)*(cirx-j);//計算距離平方和
            temy=(ciry-i)*(ciry-i);
            if(sqrt(temx+temy)>29 && gray>235)continue;//圓外且接近白色的點不處理
            else{
                r=qRed(logo.pixel(j,i));
                g=qGreen(logo.pixel(j,i));
                b=qBlue(logo.pixel(j,i));
                test.setPixel(j+test.width()-logo.width(),i,qRgb(r,g,b));//浮水印在右上
            }
        }
    }

    return test;
}

void Widget::on_pushButton_6_clicked()
{
    //開啟目的資料夾
    const QString folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    if(!folderPath.isEmpty())
    {
        QDir dir(folderPath);
        QStringList filter;
        //只讀取JPG檔
        filter << QLatin1String("*.jpg");
        dir.setNameFilters(filter);
        //讀所有符合條件的圖片檔名
        filelistinfo = dir.entryInfoList();
        QString imageFile = filelistinfo[count].absoluteFilePath();
        QImage test(imageFile);
        water(test);
        ui->label->setPixmap(QPixmap::fromImage(test));
        ui->label_2->setText(QString::number(filelistinfo.count())+"張");
    }
}

void Widget::showimage(){


    QString imageFile = filelistinfo[count].absoluteFilePath();
    QImage test(imageFile);
    water(test);
    ui->label->setPixmap(QPixmap::fromImage(test));
    if(doublestatus){//倒轉兩倍
        if(count>0){
            count--;
        }
        else {
            count=0;
            timer->stop();
            startstatus=false;
            ui->pushButton_2->setText("開始");
        }
    }
    else {
    if(count>=filelistinfo.count()-1&&repeatstatus==true)count=0;//重播
    else if(count>=filelistinfo.count()-1&&repeatstatus==false){//沒有重播，停住
        count=filelistinfo.count()-1;
        timer->stop();
        ui->pushButton_2->setText("開始");
        startstatus=false;//結束狀態
    }
    else count++;
    }
}

void Widget::on_pushButton_2_clicked()
{
    doublestatus=false;
    startstatus=!startstatus;
    if(startstatus){
        if(repeatstatus==false&&count==filelistinfo.count()-1)count=0;
        timer->start(33);
        ui->pushButton_2->setText("暫停");
    }
    else {
        timer->stop();
        ui->pushButton_2->setText("開始");
    }
}

void Widget::on_pushButton_4_clicked()
{
    timer->start(33);
    doublestatus=false;
    count=0;
    ui->pushButton_2->setText("暫停");
}

void Widget::on_pushButton_3_clicked()
{
    //快轉
    doublestatus=false;
    timer->start(16);
}

void Widget::on_pushButton_clicked()
{
    doublestatus=true;
    startstatus=true;
    timer->start(16);
    ui->pushButton_2->setText("暫停");
}

void Widget::on_pushButton_5_clicked()
{
    timer->start(33);
    repeatstatus=!repeatstatus;
    if(repeatstatus)ui->pushButton_5->setText("關閉重複撥放");
    else ui->pushButton_5->setText("開啟重複撥放");
}
