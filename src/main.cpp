#include <QApplication>
#include <QStyleFactory>
#include <QDebug>
#include <QWebEngineSettings>

#include "ui_mainwindow.h"

void setLooks(QMainWindow &m, QApplication &a, Ui::MainWindowForm &mwf);
void configureUI(QApplication &, QMainWindow &);

int main(int argc, char *argv[]) {
    QApplication qtApp(argc, argv);
    QMainWindow mw;
    configureUI(qtApp, mw);
    mw.show();
    return QApplication::exec();
}

void configureUI(QApplication & qtApp, QMainWindow & mw) {
    Ui::MainWindowForm mwf;
    mwf.setupUi(&mw);

    mw.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    setLooks(mw, qtApp, mwf);
}

void setLooks(QMainWindow &m, QApplication &a, Ui::MainWindowForm &mwf) {
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    QPixmap background(":/green_background.png");
    background = background.scaled(m.size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    m.setPalette(palette);

    mwf.display->settings()->setAttribute(QWebEngineSettings::ShowScrollBars, false);
    mwf.display->load(QUrl("http://127.0.0.1"));

    // mwf.display->setStyleSheet(" border-image: url(:/blue_screen.png) 0 0 0 0 stretch stretch; border-width: 0px;");
}