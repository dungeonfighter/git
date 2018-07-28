#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileInfo>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QFileInfoList filelistinfo;
    QTimer *timer=new QTimer;
    bool status=false;
    int count=0;
    QImage logo;
    bool startstatus=false;
    bool doublestatus=false;
    bool repeatstatus=true;
    QImage water(QImage &test);
private slots:
    void on_pushButton_6_clicked();
    void showimage();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
