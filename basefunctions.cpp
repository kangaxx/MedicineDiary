#include "basefunctions.h"
#include <unistd.h>

basefunctions::basefunctions()
{
    //do nothing yet;
}

void basefunctions::GetSqlLink(QString FileName, QString ConnName, Connections &Conn)
{
    QString IniFileName = basefunctions::GetExePath() + "/" + ConnName;
    QFile f;
    f.setFileName(IniFileName);

    if (!f.exists())
        throw "File not exists,pls check it!";

    if (!f.open(QFile::ReadOnly))
        throw "File["+IniFileName+"] not open,pls check the it!";
    f.seek(0);
    char buf[1024];

    qint64 lineLength = f.readLine(buf,sizeof(buf));//first line is Server
    if (lineLength < 0)
        throw "Read Ini file error!";
    if (lineLength > 0)
        Conn.Server = QString::fromLatin1(buf).replace("\n","\0");

    lineLength = f.readLine(buf,sizeof(buf));//second line, UserName
    if (lineLength < 0)
        throw "Read Ini file error!";
    if (lineLength > 0)
        Conn.User = QString::fromLatin1(buf).replace("\n","\0");

    lineLength = f.readLine(buf,sizeof(buf));//third line , Password
    if (lineLength < 0)
        throw "Read Ini file error!";
    if (lineLength > 0)
        Conn.Passwd = QString::fromLatin1(buf).replace("\n","\0");


    lineLength = f.readLine(buf,sizeof(buf));//third line , Database
    if (lineLength < 0)
        throw "Read Ini file error!";
    if (lineLength > 0)
        Conn.Database = QString::fromLatin1(buf).replace("\n","\0");

    f.close();
    int t = rand();

    Conn.ConnName = ConnName;
}

QString basefunctions::GetExePath()
{
    QString Ret;
    char buf[1024] = { 0 };
    int n;

    n = readlink("/proc/self/exe" , buf , sizeof(buf));
    if( n > 0 && n < sizeof(buf))
        Ret = QString::fromLatin1(buf,n);
    else
        throw QString("Get program path error!");
}

