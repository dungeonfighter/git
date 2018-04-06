#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("1103105339 曾文輝");//設定視窗標題

    //初始化，用陣列儲存Label
    labelarray[0]=ui->label;
    labelarray[1]=ui->label_2;
    labelarray[2]=ui->label_3;
    labelarray[3]=ui->label_4;
    labelarray[4]=ui->label_5;
    labelarray[5]=ui->label_6;
    labelarray[6]=ui->label_7;
    labelarray[7]=ui->label_8;
    //初始化亂數種子
    qsrand((uint)time.msec());

    //讀圖片
    QString url = R"(\untitled1\debug\bo.png)";
    //這也行 QString url = "/untitled1/debug/bo.png";
    QPixmap img(url);
    //取圖長寬
    int w=img.width();
    int h=img.height();
    //給標籤圖示並設定位置與大小
    ui->label_9->setGeometry(150,220,w,h);
    ui->label_9->setPixmap(img);
}

Widget::~Widget()
{
    delete ui;
}

//當改變項目時，得到選取項目時的index
void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    int ran;//儲存隨機產生的數
    //根據選到的配方(index)給予Label初始值
    if(currentRow==0){
        for(int i=0;i<8;++i){
            labelarray[i]->setText(QString::number(12+2*i));
        }
    }
    else if(currentRow==1){
        for(int i=0;i<8;++i){
            ran=qrand()%20+6;
            labelarray[i]->setText(QString::number(ran));
        }
    }
    else if(currentRow==2){
        for(int i=0;i<8;++i){
            labelarray[i]->setText(QString::number(56));
        }
    }

}
