#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showRGB_YUV(QPoint &pos);
protected:
    void mouseDoubleClickEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void onMouseEvent(const QString &eventName,const QPoint &pos);
    QImage *test;

};

#endif // MAINWINDOW_H
