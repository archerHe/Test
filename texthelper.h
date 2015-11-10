#ifndef TEXTHELPER_H
#define TEXTHELPER_H
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QTemporaryFile>
#include <QDir>
#include <QMessageBox>
#include <QStringList>
#include <QtXml>

class TextHelper
{
public:
    TextHelper();
    bool modifyTextStr(QString filePath, QString oriStr, QString newStr);
    QString readTextStr(QString filePath, QString objStr, QString typeFlag);
    QString readXml(QString xmlLine);
    bool modifyXml(QString filePath, QString attr, QString newStr);


private:
    QString oriText;
    QString newText;
    QString curPath;

};

#endif // TEXTHELPER_H
