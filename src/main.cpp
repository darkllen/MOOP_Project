//
// Created by Lemonderon on 02.10.2020.
//

#include <QApplication>
#include <QStyleFactory>
#include <QMainWindow>

#include "ui/ATMForm.h"

#include <QWebChannel>

void webChannelTesting(ATMForm &form) {
    auto *webClass = new WebClass();
    auto *channel = new QWebChannel();
    channel->registerObject("webobj", webClass);
    form.getWebPage().setWebChannel(channel);
    form.getWebPage().setHtml(
            "<html>"
            "<script src=\"qrc:///qtwebchannel/qwebchannel.js\"></script>"
            "<p>This is some text</p>"
            "<script type=\"text/javascript\">\n"
            "    document.addEventListener(\"DOMContentLoaded\", function () {"
            "       var updateattribute = function(text)\n"
            "         {\n"
            "             console.log(\"Text from SIGNAL\" + text);\n"
            "         }\n"
            "       new QWebChannel(qt.webChannelTransport,\n"
            "         function(channel){\n"
            "             var webobj = channel.objects.webobj;\n"
            "             console.log(\"webobj = \" + webobj);"
            "             window.foo = webobj;\n"
            "             webobj.someattributeChanged.connect(updateattribute);\n"
            "         });"
            "       console.log(\"window.foo=\" + window.foo);"
            "       window.foo.jscallme();"
            "   });"
            "</script>"
            "</html>");

    // Sending SIGNAL to js in the webpage
    webClass->setsomeattribute("hello");
}

int main(int argc, char *argv[]) {
    QApplication qtApp(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    QMainWindow mw;
    ATMForm form(&mw);
    mw.show();

    webChannelTesting(form);

    return QApplication::exec();
}