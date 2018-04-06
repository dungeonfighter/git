#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QListWidgetItem>
#include <QGlobal.h>
#include <QTime>
#include <QImage>
#include <Qstring>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //標籤指標
    QLabel *labelarray[8];
    //亂數時間種子
    QTime time = QTime::currentTime();



private slots:
    //void on_verticalScrollBar_valueChanged(int value);

    //void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    //void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::Widget *ui;
};








#endif // WIDGET_H
