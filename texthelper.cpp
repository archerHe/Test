#include "texthelper.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTemporaryFile>
#include <QDir>
#include <QMessageBox>

TextHelper::TextHelper()
{

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

QString TextHelper::readTextStr(QString filePath, QString objStr)
{
    QFile file(filePath);
    QFile newFile(tmp);
    newFile.open(QIODevice::WriteOnly);
    QTextStream newStream(&newFile);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString objLine;
        while(!stream.atEnd())
        {
            objLine = stream.readLine();
            if(objLine.contains(objStr))
            {

            }
        }
    }
}

