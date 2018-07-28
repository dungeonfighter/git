#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QImage>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int a=0;//記數
    bool status=false;//開始或暫停狀態

private slots:
    void showimage();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer=new QTimer;
    QList<QImage> myImages;//儲存多張影像，類似vector

};

#endif // WIDGET_H
