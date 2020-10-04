//
// Created by kuchm on 04.10.2020.
//

#ifndef MOOP_ATM_PROJECT_WEBCLASS_H
#define MOOP_ATM_PROJECT_WEBCLASS_H


#include <QtCore/QObject>
#include <QMessageBox>

class WebClass : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString someattribute MEMBER m_someattribute)
public slots:
    void jscallme()
    {
        QMessageBox::information(NULL,"jscallme","I'm called by js!");
    }
    void setsomeattribute(QString attr)
    {
        m_someattribute=attr;
        emit someattributeChanged(m_someattribute);
    }
signals:
    void someattributeChanged(QString & attr);
//    void someattributeChanged(const QString & attr);

private:
    QString m_someattribute;
};

#endif //MOOP_ATM_PROJECT_WEBCLASS_H
