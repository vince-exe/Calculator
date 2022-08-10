#include "main_window_dialog.h"
#include "ui_main_window_dialog.h"

#include <QLabel>
#include <QPixmap>

MainWindowDialog::MainWindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowDialog) {
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* set the image to the history label */
    QPixmap pixmap("images/history_label_image.png");
    ui->imageLabel->setPixmap(pixmap);
    ui->imageLabel->show();
}

MainWindowDialog::~MainWindowDialog() {
    delete ui;
}
