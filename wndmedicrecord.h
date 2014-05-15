#ifndef WNDMEDICRECORD_H
#define WNDMEDICRECORD_H

#include <QDialog>

namespace Ui {
class WndMedicRecord;
}

class WndMedicRecord : public QDialog
{
    Q_OBJECT

public:
    explicit WndMedicRecord(QWidget *parent = 0);
    ~WndMedicRecord();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::WndMedicRecord *ui;
};

#endif // WNDMEDICRECORD_H
