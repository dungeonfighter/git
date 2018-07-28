#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QFileDialog>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test=new QImage(":/pics/100_100.png");
    ui->label_2->setPixmap(QPixmap::fromImage(QImage(":/pics/100_100.png")));
    ui->pushButton->hide();
    setWindowTitle("RGB轉YUV與滑鼠測試");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRGB_YUV(QPoint &pos)
{
    if((20<=pos.x()&& pos.x()<120) && 110<=pos.y()&& pos.y()<210 ){
        QColor rgb=QColor(test->pixel(pos.x()-20,pos.y()-110));
        ui->lineEdit_2->setText(QString::number(rgb.red()));
        ui->lineEdit_3->setText(QString::number(rgb.green()));
        ui->lineEdit_4->setText(QString::number(rgb.blue()));
        double y=0.299*rgb.red()+0.587*rgb.green()+0.114*rgb.blue();
        double u=-0.169*rgb.red()-0.331*rgb.green()+0.5*rgb.blue()+128;
        double v=0.5*rgb.red()-0.419*rgb.green()-0.081*rgb.blue()+128;
        ui->lineEdit_5->setText(QString::number(y));
        ui->lineEdit_6->setText(QString::number(u));
        ui->lineEdit_7->setText(QString::number(v));
    }
    else{
        ui->lineEdit_2->setText("0");
        ui->lineEdit_3->setText("0");
        ui->lineEdit_4->setText("0");
        ui->lineEdit_5->setText("0");
        ui->lineEdit_6->setText("0");
        ui->lineEdit_7->setText("0");
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    onMouseEvent("DoubleClick",event->pos());
    QWidget::mouseDoubleClickEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    onMouseEvent("Move",event->pos());
    QWidget::mouseMoveEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    onMouseEvent("Press",event->pos());
    QPoint index= QPoint(event->pos().x(),event->pos().y());
    showRGB_YUV(index);
    QWidget::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    onMouseEvent("Release",event->pos());
    QWidget::mouseReleaseEvent(event);
}

void MainWindow::onMouseEvent(const QString &eventName,const QPoint &pos)
{
    ui->lineEdit->setText(eventName);
    ui->xPosSpinBox->setValue(pos.x());
    ui->yPosSpinBox->setValue(pos.y());

}

void MainWindow::on_pushButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
                            this,
                            "Select one or more files to open",
                            "/home",
                            "Images (*.png *.xpm *.jpg)");
    ui->label_5->setText(files[0]);

}
