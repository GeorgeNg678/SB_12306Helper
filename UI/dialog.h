#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTextStream>
#include <QFile>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    int first_time_setup();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void save_checkbox_state(int arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
