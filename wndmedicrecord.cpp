#include "wndmedicrecord.h"
#include "ui_wndmedicrecord.h"
#include "qmessagebox.h"
#include "sqlfunctions.h"
WndMedicRecord::WndMedicRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WndMedicRecord)
{
    ui->setupUi(this);
}

WndMedicRecord::~WndMedicRecord()
{
    delete ui;
}

void WndMedicRecord::on_buttonBox_accepted()
{
    QMessageBox::about(this,"Accept","Accept and close");


}
