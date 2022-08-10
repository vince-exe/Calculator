#include "main_window_dialog.h".h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindowDialog w;
    w.show();

    return a.exec();
}
