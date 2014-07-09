#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

#include "wndmedicrecord.h" //药品入库

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ActMedInput_triggered()
{
    QMessageBox::about(this,"Hello","Hello , let's go get it work!");
    WndMedicRecord *pMr = new WndMedicRecord(this);
    pMr->show();
}
