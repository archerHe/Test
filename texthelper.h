#ifndef TEXTHELPER_H
#define TEXTHELPER_H
#include <QFile>
#include <QString>

class TextHelper
{
public:
    TextHelper();
    bool modifyTextStr(QString filePath, QString oriStr, QString newStr);
    QString readTextStr(QString filePath, QString objStr);

private:
    QString oriText;
    QString newText;
};

#endif // TEXTHELPER_H
