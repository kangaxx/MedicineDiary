#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

#include "wndmedicrecord.h" //药品入库
#include "sqlfunctions.h"
#include "basefunctions.h"

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
    try
    {
        //just demo for sql
        FSqlFactory *pTheSqlfct;
        basefunctions bf;
        Connections TheConn;
        bf.GetSqlLink(QString("system.ini"),QString("MedicineType.xml"),TheConn);
        SqlFunctions sql;


        sql.Create(XML,TheConn,&pTheSqlfct);
        if (!pTheSqlfct)
            throw "still NULL PTR";

        WndMedicRecord *pMr = new WndMedicRecord(this,pTheSqlfct);
        pMr->show();
    }
    catch(QString exception)
    {
        QMessageBox::about(this,"Error",exception);
    }
    catch(const char* exception)
    {
        QMessageBox::about(this,"Error",exception);
    }
}
