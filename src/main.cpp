#include <QApplication>
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow mainWindow;
    Ui::MainWindowForm mwf;
    mwf.setupUi(&mainWindow);
    mainWindow.show();
    return a.exec();
}