#include "main_window_dialog.h"
#include "ui_main_window_dialog.h"

#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>

#include <math.h>

/* global variable used to check if the history label is hidden */
bool historyLabelVisible = false;

/* max limit of numbers to digit */
const int numbersLimit = 16;

/* take care of saving the first number */
long long int firstNumber = 0;

/* take care of saving the last selected operation before the equals */
char lastOperation;

MainWindowDialog::MainWindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowDialog) {
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* set the image to the history label */
    QPixmap pixmap("images/history_label_image.png");
    QIcon buttonIcon(pixmap);
    ui->imgBtn->setIcon(buttonIcon);
    ui->imgBtn->setIconSize(pixmap.rect().size());
    ui->imgBtn->setFixedSize(pixmap.rect().size());
    /* hide the history label */
    ui->historyLabel->setVisible(historyLabelVisible);
}

MainWindowDialog::~MainWindowDialog() {
    delete ui;
}

void MainWindowDialog::on_imgBtn_clicked() {
    historyLabelVisible = !historyLabelVisible;
    ui->historyLabel->setVisible(historyLabelVisible);
}

/* UTILITIES BUTTONS */

/* CE button */
void MainWindowDialog::on_CE_Btn_clicked() {
    ui->numbersBox->clear();
}

/* C button */
void MainWindowDialog::on_C_Btn_clicked() {
    ui->numbersBox->clear();
}

/* DEL button */
void MainWindowDialog::on_DEL_Btn_clicked() {
    ui->numbersBox->backspace();
}

/* NUMBERS */

/* 7 button */
void MainWindowDialog::on_sevenBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "7");
}

/* 8 button */
void MainWindowDialog::on_eightBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "8");
}

/* 9 button */
void MainWindowDialog::on_nineBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "9");
}

/* 4 button */
void MainWindowDialog::on_fourBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "4");
}

/* 5 button */
void MainWindowDialog::on_fiveBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "5");
}

/* 6 button */
void MainWindowDialog::on_sixBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "6");
}

/* 1 button */
void MainWindowDialog::on_oneBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "1");
}

/* 2 button */
void MainWindowDialog::on_twoBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "2");
}

/* 3 button */
void MainWindowDialog::on_threeBtn_clicked() {
    ui->numbersBox->setText(ui->numbersBox->text() + "3");
}

/* 0 button */
void MainWindowDialog::on_zeroBtn_clicked() {
    if(ui->numbersBox->text().length() != 0) {
        ui->numbersBox->setText(ui->numbersBox->text() + "0");
    }
}

/* OPERATIONS BUTTONS */

void MainWindowDialog::on_plusBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    firstNumber = ui->numbersBox->text().toLongLong();
    lastOperation = '+';
    ui->numbersBox->clear();
}

void MainWindowDialog::on_minusBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    firstNumber = ui->numbersBox->text().toLongLong();
    lastOperation = '-';
    ui->numbersBox->clear();
}

void MainWindowDialog::on_moltiplicationBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    firstNumber = ui->numbersBox->text().toLongLong();
    lastOperation = '*';
    ui->numbersBox->clear();
}

void MainWindowDialog::on_DivisionBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    firstNumber = ui->numbersBox->text().toLongLong();
    lastOperation = '/';
    ui->numbersBox->clear();
}

void MainWindowDialog::on_commaBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }
}

/* + / - */
void MainWindowDialog::on_plusMinusBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    ui->numbersBox->setText(QString::number(ui->numbersBox->text().toLongLong() * -1));
}

/* x^3 */
void MainWindowDialog::on_X3_Btn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    ui->numbersBox->setText(QString::number(pow(ui->numbersBox->text().toLongLong(), 3)));
}

/* x^2 */
void MainWindowDialog::on_X2_Btn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    ui->numbersBox->setText(QString::number(pow(ui->numbersBox->text().toLongLong(), 2)));
}

/* root */
void MainWindowDialog::on_rootBtn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    ui->numbersBox->setText(QString::number(sqrt(ui->numbersBox->text().toLongLong())));
}

/* x^y */
void MainWindowDialog::on_XY_Btn_clicked() {
    if(!ui->numbersBox->text().length()) { return; }

    firstNumber = ui->numbersBox->text().toLongLong();
    ui->numbersBox->clear();
    lastOperation = '^';
}

/* RESULT BUTTON */
void MainWindowDialog::on_equalsBtn_clicked() {
    long long int secondNumber = ui->numbersBox->text().toLongLong();

    qDebug() << firstNumber;
    qDebug() << secondNumber;

    /* check the last operation */
    switch (lastOperation) {
    case '+':
        ui->numbersBox->setText(QString::number(firstNumber + secondNumber));
        lastOperation = '.';
        break;

    case '-':
        ui->numbersBox->setText(QString::number(firstNumber - secondNumber));
        lastOperation = '.';
        break;

    case '*':
        ui->numbersBox->setText(QString::number(firstNumber * secondNumber));
        lastOperation = '.';
        break;

    case '/':
        ui->numbersBox->setText(QString::number(firstNumber / secondNumber));
        lastOperation = '.';
        break;

    case '^':
        ui->numbersBox->setText(QString::number(pow(firstNumber, ui->numbersBox->text().toInt())));
        lastOperation = '.';
        break;

    default:
        break;
    }
}

/* check if the user doesn't pass the max lengh */
void MainWindowDialog::on_numbersBox_textChanged(const QString &arg1) {
    if(arg1.length() > numbersLimit) { ui->numbersBox->backspace(); }
}

/* detect a pressed key */
void MainWindowDialog::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_1:
        ui->numbersBox->setText(ui->numbersBox->text() + "1");
        break;

    case Qt::Key_2:
        ui->numbersBox->setText(ui->numbersBox->text() + "2");
        break;

    case Qt::Key_3:
        ui->numbersBox->setText(ui->numbersBox->text() + "3");
        break;

    case Qt::Key_4:
        ui->numbersBox->setText(ui->numbersBox->text() + "4");
        break;

    case Qt::Key_5:
        ui->numbersBox->setText(ui->numbersBox->text() + "5");
        break;

    case Qt::Key_6:
        ui->numbersBox->setText(ui->numbersBox->text() + "6");
        break;

    case Qt::Key_7:
        ui->numbersBox->setText(ui->numbersBox->text() + "7");
        break;

    case Qt::Key_8:
        ui->numbersBox->setText(ui->numbersBox->text() + "8");
        break;

    case Qt::Key_9:
        ui->numbersBox->setText(ui->numbersBox->text() + "9");
        break;

    case Qt::Key_0:
        if(ui->numbersBox->text().length() != 0) {
            ui->numbersBox->setText(ui->numbersBox->text() + "0");
        }
        break;

    case Qt::Key_Backspace:
        ui->numbersBox->backspace();
        break;

    case Qt::Key_Plus:
        on_plusBtn_clicked();
        break;

    case Qt::Key_Minus:
        on_minusBtn_clicked();
        break;

    case Qt::Key_multiply:
        on_moltiplicationBtn_clicked();
        break;

    case Qt::Key_Slash:
        on_DivisionBtn_clicked();
        break;

    default:
        break;
    }
}
