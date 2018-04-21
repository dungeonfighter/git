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
    int a=0;
    bool status=false;

private slots:
    void dos();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer=new QTimer;
    QList<QImage> myImages;

};

#endif // WIDGET_H
