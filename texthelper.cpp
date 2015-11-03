#include "texthelper.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTemporaryFile>
#include <QDir>
#include <QMessageBox>
#include <QStringList>

TextHelper::TextHelper()
{
    curPath = QDir::currentPath();

}

bool TextHelper::modifyTextStr(QString filePath, QString oriStr, QString newStr)
{
    QFile file(filePath);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        oriText = stream.readAll();
        newText = oriText.replace(oriStr, newStr);
    }
    else
    {
        qDebug() << filePath << " open fail";
    }
}

QString TextHelper::readTextStr(QString filePath, QString objStr, QString typeFlag)
{
    QString resultStr;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString objLine;
        while(!stream.atEnd())
        {
            objLine = stream.readLine();
            if(objLine.contains(objStr))
            {
                if(typeFlag == "xml")
                {
                    resultStr = readXml(objLine);
                    //qDebug() << "type is xml~~";
                    break;
                }
               // qDebug() << "type is normal..";
                QStringList strlist = objLine.split("=");
                resultStr = strlist[1];
                break;
            }
        }
    }
    file.close();
    qDebug() << objStr << " : " << resultStr;
    return resultStr.trimmed();
}

QString TextHelper::readXml(QString xmlLine)
{
    QStringList strlist1 = xmlLine.split("\">");
    QString str = strlist1[1];
    QStringList strlis2 = str.split("<");
    QString resultStr = strlis2[0];
    return resultStr.trimmed();
}

