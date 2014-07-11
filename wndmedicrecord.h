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

private:
    Ui::WndMedicRecord *ui;
    FSqlFactory *m_pSqlfct;
};

#endif // WNDMEDICRECORD_H
