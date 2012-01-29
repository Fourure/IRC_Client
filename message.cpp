#include "message.h"

Message::Message(QString user, QString mess) : mess(mess), user(user)
{
}

QString Message::toString(){
    QString ret;
    ret.append(user).append(" : ").append(mess);
    return ret;
}
