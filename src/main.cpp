#include <QApplication>
#include <QStyleFactory>
#include <QDebug>
#include "ui_mainwindow.h"

void setLooks(QMainWindow& m, QApplication& a, Ui::MainWindowForm& mwf);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow mainWindow;
    Ui::MainWindowForm mwf;
    mwf.setupUi(&mainWindow);

    setLooks(mainWindow, a, mwf);

    mainWindow.show();
    return a.exec();
}


void setLooks(QMainWindow& m, QApplication& a, Ui::MainWindowForm& mwf){
    m.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    a.setStyle(QStyleFactory::create("Fusion"));

    QPixmap bkgnd(":/green_background.png");
    bkgnd = bkgnd.scaled(m.size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    m.setPalette(palette);

    mwf.display->setStyleSheet(" border-image: url(:/blue_screen.png) 0 0 0 0 stretch stretch; border-width: 0px;");
}