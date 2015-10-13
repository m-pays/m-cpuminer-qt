#include "poolparse.h"

PoolParse::PoolParse(QObject *parent) :
    QObject(parent)
{
}

QString PoolParse::getURL(QString poolName, QString apiKey)
{
    QString url;

    if (poolName == "pom.m-hash.com")
        url = "http://pom.m-hash.com/index.php?page=api&action=getuserstatus&api_key=";
    else if (poolName == "suprnova.cc")
        url = "https://xmg.suprnova.cc/index.php?page=api&action=getuserstatus&api_key=";
    else if (poolName == "suchpool.pw")
        url = "https://www.suchpool.pw/xmg/index.php?page=api&action=getuserstatus&api_key=";
    else if (poolName == "-")
        url = "-";

    url.append(apiKey);

    return url;
}

QString PoolParse::parseData(QString poolName, QVariantMap apidata)
{
    QString message;
    double hashrate = -1;

    QVariantMap userStatus, userData;

    if (poolName == "pom.m-hash.com")
    {
        userStatus = apidata.value("getuserstatus").toMap();
        userData = userStatus.value("data").toMap();
        hashrate = userStatus.value("hashrate").toDouble();
    }
    else if (poolName == "-")
    {
    }

    if (hashrate != -1)
    {
        QString totalString = QString("<b>Pool hashrate:</b><br/>%1 kh/s<br/><br/>").arg(hashrate);
        message.append(totalString);
    }

    return message;
}
