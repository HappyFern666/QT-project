#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Schedule.h"
#include <QtWidgets>
#include <QtUiTools/QUiLoader>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Add_Schedule_clicked()
{
    QString uiFilePath = QDir::currentPath() + "/Add_Schedule.ui";
    QUiLoader loader;
    QFile file(uiFilePath);
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Failed to open UI file";
        return;
    }
    file.open(QFile::ReadOnly);
    QWidget * widget = loader.load(&file, this);
    file.close();

    QDialog *dialog = qobject_cast<QDialog*>(widget);
    if (!dialog) {
        qDebug() << "Failed to cast widget to QDialog";
        return;
    }

    // Find the QLineEdit widget for text input
    QLineEdit *lineEdit = dialog->findChild<QLineEdit*>("Enter_Task_Name");
    if (lineEdit) {
        // Get the text inputted by the user
        lineEdit->setPlaceholderText("Enter text here");
        QString userInput = lineEdit->text();
        qDebug() << "User input: " << userInput;
    }


}

