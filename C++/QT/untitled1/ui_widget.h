/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QScrollBar *verticalScrollBar;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QScrollBar *verticalScrollBar_2;
    QScrollBar *verticalScrollBar_3;
    QScrollBar *verticalScrollBar_4;
    QScrollBar *verticalScrollBar_5;
    QScrollBar *verticalScrollBar_6;
    QScrollBar *verticalScrollBar_7;
    QScrollBar *verticalScrollBar_8;
    QListWidget *listWidget;
    QLabel *label_9;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(711, 443);
        verticalScrollBar = new QScrollBar(Widget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(90, 100, 17, 71));
        verticalScrollBar->setMinimum(1);
        verticalScrollBar->setMaximum(99);
        verticalScrollBar->setOrientation(Qt::Vertical);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 110, 47, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 110, 47, 12));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 110, 47, 12));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 110, 47, 12));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 110, 47, 12));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 110, 47, 12));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(500, 110, 47, 12));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(580, 110, 47, 12));
        verticalScrollBar_2 = new QScrollBar(Widget);
        verticalScrollBar_2->setObjectName(QStringLiteral("verticalScrollBar_2"));
        verticalScrollBar_2->setGeometry(QRect(170, 100, 16, 71));
        verticalScrollBar_2->setMaximum(99);
        verticalScrollBar_2->setOrientation(Qt::Vertical);
        verticalScrollBar_3 = new QScrollBar(Widget);
        verticalScrollBar_3->setObjectName(QStringLiteral("verticalScrollBar_3"));
        verticalScrollBar_3->setGeometry(QRect(250, 100, 16, 71));
        verticalScrollBar_3->setMaximum(99);
        verticalScrollBar_3->setOrientation(Qt::Vertical);
        verticalScrollBar_4 = new QScrollBar(Widget);
        verticalScrollBar_4->setObjectName(QStringLiteral("verticalScrollBar_4"));
        verticalScrollBar_4->setGeometry(QRect(330, 100, 16, 71));
        verticalScrollBar_4->setMaximum(99);
        verticalScrollBar_4->setOrientation(Qt::Vertical);
        verticalScrollBar_5 = new QScrollBar(Widget);
        verticalScrollBar_5->setObjectName(QStringLiteral("verticalScrollBar_5"));
        verticalScrollBar_5->setGeometry(QRect(400, 100, 16, 71));
        verticalScrollBar_5->setOrientation(Qt::Vertical);
        verticalScrollBar_6 = new QScrollBar(Widget);
        verticalScrollBar_6->setObjectName(QStringLiteral("verticalScrollBar_6"));
        verticalScrollBar_6->setGeometry(QRect(480, 100, 16, 71));
        verticalScrollBar_6->setOrientation(Qt::Vertical);
        verticalScrollBar_7 = new QScrollBar(Widget);
        verticalScrollBar_7->setObjectName(QStringLiteral("verticalScrollBar_7"));
        verticalScrollBar_7->setGeometry(QRect(560, 100, 16, 71));
        verticalScrollBar_7->setOrientation(Qt::Vertical);
        verticalScrollBar_8 = new QScrollBar(Widget);
        verticalScrollBar_8->setObjectName(QStringLiteral("verticalScrollBar_8"));
        verticalScrollBar_8->setGeometry(QRect(630, 100, 16, 71));
        verticalScrollBar_8->setOrientation(Qt::Vertical);
        listWidget = new QListWidget(Widget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 10, 61, 61));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 280, 47, 21));
        label_9->setScaledContents(true);

        retranslateUi(Widget);
        QObject::connect(verticalScrollBar, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_3, SIGNAL(valueChanged(int)), label_3, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_2, SIGNAL(valueChanged(int)), label_2, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_4, SIGNAL(valueChanged(int)), label_4, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_5, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_6, SIGNAL(valueChanged(int)), label_6, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_7, SIGNAL(valueChanged(int)), label_7, SLOT(setNum(int)));
        QObject::connect(verticalScrollBar_8, SIGNAL(valueChanged(int)), label_8, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "\351\205\215\346\226\2711", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "\351\205\215\346\226\2712", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "\351\205\215\346\226\2713", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
