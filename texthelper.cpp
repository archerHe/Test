#include "texthelper.h"


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
        qDebug() << "modifyTextStr: " << " open file fail";
        return false;
    }
    return true;
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

                    break;
                }

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

bool TextHelper::modifyXml(QString filePath, QString attr, QString newStr)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        return false;
    }
    file.close();

    QDomNode n = doc.firstChild();
    while(!n.isNull())
    {
        if(n.isElement())
        {
            QDomElement e = n.toElement();
            QDomNodeList nodeList = e.childNodes();
            for(int i = 0; i < nodeList.count(); i++)
            {
                QDomNode node = nodeList.at(i);
                if(node.isElement())
                {
                    if(node.toElement().attribute("name") == attr)
                    {
                        node.toElement().firstChild().setNodeValue(newStr);
                    }
                }
            }
        }
       n = n.nextSibling();
    }
    QFile f(filePath);
    if(!f.open(QIODevice::WriteOnly))
    {
        return false;
    }
    QTextStream out(&file);
    doc.save(out, 4, QDomNode::EncodingFromTextStream);
    f.close();
}



