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

int TextHelper::readCam(QString camType, QString dtsPath)
{
    QFile   *dtsFile =  new QFile(dtsPath);
    int camera_id = 0;
    QTextStream ts(dtsFile);
    if(!dtsFile->open(QIODevice::ReadOnly))
        return -1;
    if(camType == "back")
    {
        QString strLine;
        while(!ts.atEnd())
        {
            strLine = ts.readLine();
            QString s = "camera" + QString::number(camera_id, 10);
            if(strLine.contains(s) && strLine.contains(":"))
            {
                strLine = ts.readLine();
                if(strLine.contains("//"))
                {
                    strLine = ts.readLine();
                    QStringList strlist1 = strLine.split(",");
                    QString str2 = strlist1[1];
                    QStringList strlist2 = str2.split("-");
                    qDebug() << strlist2[0] << " camera_id: " << camera_id;
                    return camera_id;
                }
                camera_id++;
            }
        }
    }
    if(camType == "front")
    {
        camera_id = 6;
        QString strLine;
        while(!ts.atEnd())
        {
            strLine = ts.readLine();
            QString s = "camera" + QString::number(camera_id, 10);
            if(strLine.contains(s) && strLine.contains(":"))
            {

                strLine = ts.readLine();
                qDebug() << strLine;

                if(strLine.contains("compatible") || strLine.contains("//"))
                {
                    if(strLine.contains("//"))
                    {
                        strLine = ts.readLine();
                    }

                    QStringList strlist1 = strLine.split(",");
                    QString str2 = strlist1[1];
                    QStringList strlist2 = str2.split("-");
                    qDebug() << strlist2[0] << "camera_id: " << camera_id;
                    return camera_id - 6;
                }
                camera_id++;
            }

        }

    }
    dtsFile->close();
}

void TextHelper::writeCam(int preCamId, int curCamId, QString dtsPath)
{
    if(preCamId == curCamId)
        return;
    disableCam(preCamId, dtsPath);
    enableCam(curCamId, dtsPath);
}

int TextHelper::disableCam(int camId, QString dtsPath)
{
    //QString dtsPath;
    QFile   *dtsFile =  new QFile(dtsPath);
    QFile   *newDtsFile = new QFile(QDir::currentPath() + "/tmp/Sofia3GR-tablet.dts");
    QTextStream newDts(newDtsFile);
    QTextStream dtsOld(dtsFile);
    QString strLine;
    if(!dtsFile->open(QIODevice::ReadOnly))
    {
        return -1;
    }
    newDtsFile->open(QIODevice::WriteOnly);
    while(!dtsOld.atEnd())
    {
        strLine = dtsOld.readLine();
        if(strLine.contains("camera" + QString::number(camId, 10)) && strLine.contains(":"))
        {
               newDts << strLine << "\n";
               newDts << "\t\tstatus = \"disabled\";\n";
               strLine = dtsOld.readLine();
               continue;
        }
        newDts << strLine << "\n";

    }
    dtsFile->close();
    newDtsFile->flush();
    newDtsFile->close();
    dtsFile->remove();
    newDtsFile->copy(dtsPath);
    return camId;
}

int TextHelper::enableCam(int camId, QString dtsPath)
{
    //QString dtsPath;
    QFile   *dtsFile =  new QFile(dtsPath);
    QFile   *newDtsFile = new QFile(QDir::currentPath() + "/tmp/Sofia3GR-tablet.dts");
    QTextStream newDts(newDtsFile);
    QTextStream dtsOld(dtsFile);
    QString strLine;
    if(!dtsFile->open(QIODevice::ReadOnly))
    {
        return -1;
    }
    newDtsFile->open(QIODevice::WriteOnly);
    while(!dtsOld.atEnd())
    {
        strLine = dtsOld.readLine();
        if(strLine.contains("camera" + QString::number(camId, 10)) && strLine.contains(":"))
        {
               newDts << strLine << "\n";
               newDts << "\t\t//status = \"disabled\";\n";
               strLine = dtsOld.readLine();
               continue;
        }
        newDts << strLine << "\n";

    }
    dtsFile->close();
    newDtsFile->flush();
    newDtsFile->close();
    dtsFile->remove();
    newDtsFile->copy(dtsPath);
    return camId;
}



