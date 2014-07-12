#ifndef WNDMEDICRECORD_H
#define WNDMEDICRECORD_H

#include <QDialog>

#include "sqlfunctions.h"

namespace Ui {
class WndMedicRecord;
}

class WndMedicRecord : public QDialog
{
    Q_OBJECT

public:
    explicit WndMedicRecord(QWidget *parent = 0);
    WndMedicRecord(QWidget *parent=0,FSqlFactory *Sqlfct=0);
    ~WndMedicRecord();

private slots:
    void on_buttonBox_accepted();

    void on_btnTest_clicked();

private:
    Ui::WndMedicRecord *ui;
    FSqlFactory *m_pSqlfct=0;
};

#endif // WNDMEDICRECORD_H
