#ifndef MAIN_WINDOW_DIALOG_H
#define MAIN_WINDOW_DIALOG_H

#include <QDialog>

namespace Ui {
class MainWindowDialog;
}

class MainWindowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindowDialog(QWidget *parent = nullptr);
    ~MainWindowDialog();

private slots:
    void on_imgBtn_clicked();

    void on_percentageBtn_clicked();

    void on_CE_Btn_clicked();

    void on_C_Btn_clicked();

    void on_DEL_Btn_clicked();

    void on_X_Btn_clicked();

    void on_X2_Btn_clicked();

    void on_rootBtn_clicked();

    void on_DivisionBtn_clicked();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_plusMinusBtn_clicked();

    void on_zeroBtn_clicked();

    void on_commaBtn_clicked();

    void on_equalsBtn_clicked();

    void on_plusBtn_clicked();

    void on_minusBtn_clicked();

    void on_moltiplicationBtn_clicked();

    void on_numbersBox_textChanged(const QString &arg1);

private:
    Ui::MainWindowDialog *ui;

    void keyPressEvent(QKeyEvent* event);
};

#endif // MAIN_WINDOW_DIALOG_H
