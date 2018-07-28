#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include "BitField.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QImage srcimg;//合照原圖
    QLabel *labelarray[8];
    QList<QImage> myImages;
    QImage kuas;//校徽原圖
    QImage w;//縮放後和原圖一樣大的校徽
    QImage G;//隱藏後的影像
    QList<QImage> kuasImages;
    void slice();
    void water();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
