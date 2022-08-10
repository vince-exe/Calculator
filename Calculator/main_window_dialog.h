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

private:
    Ui::MainWindowDialog *ui;
};

#endif // MAIN_WINDOW_DIALOG_H
