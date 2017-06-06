/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QLabel *label_10;
    QLineEdit *lineEdit_8;
    QWidget *tab_3;
    QTextEdit *textEdit_3;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(858, 597);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 841, 561));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 90, 113, 21));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 113, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 60, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 60, 16));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 130, 113, 32));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(180, 30, 231, 111));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 10, 81, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 150, 60, 16));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 170, 231, 21));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 200, 113, 32));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(180, 30, 231, 111));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 40, 113, 21));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 220, 113, 32));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 150, 60, 16));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 70, 91, 16));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 10, 81, 16));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 20, 91, 16));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 200, 113, 32));
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(20, 90, 113, 21));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(180, 170, 231, 21));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 120, 91, 16));
        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(20, 140, 113, 21));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 170, 91, 16));
        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(20, 190, 113, 21));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        textEdit_3 = new QTextEdit(tab_3);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(180, 30, 231, 111));
        lineEdit_9 = new QLineEdit(tab_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(20, 40, 113, 21));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 130, 113, 32));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 150, 60, 16));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 70, 60, 16));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(180, 10, 81, 16));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 20, 60, 16));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 200, 113, 32));
        lineEdit_10 = new QLineEdit(tab_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(20, 90, 113, 21));
        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(180, 170, 231, 21));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SocketDebugger", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\232\204\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "TCP Sever", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\232\204\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "TCP Client", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\232\204\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "UDP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
