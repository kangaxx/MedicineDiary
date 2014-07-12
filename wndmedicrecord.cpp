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

WndMedicRecord::WndMedicRecord(QWidget *parent, FSqlFactory *Sqlfct):
    QDialog(parent),
    m_pSqlfct(Sqlfct),
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

void WndMedicRecord::on_btnTest_clicked()
{
    try
    {
        LiField FieldCmd,FieldResult;
        LiDataContext dc;
        dc.SetTableName("MedicineType");
        FieldCmd.SetName("Cmd");
        FieldCmd.SetValue(QString("cmd"));
        FieldResult.SetName("result");
        FieldResult.SetValue(QString("result"));

        dc.AddField(&FieldCmd);
        dc.AddField(&FieldResult);
        if (m_pSqlfct == NULL)
            QMessageBox::about(this,"error","sqlfct is null!");
        ISqlQuery *qry;
        qry = this->m_pSqlfct->sqlQryFct();
        qry->DoInsert(dc);
    }
    catch(QString exception)
    {
        QMessageBox::about(this,"error",exception);
    }
    catch(const char* exception)
    {
        QMessageBox::about(this,"error",exception);
    }
}
