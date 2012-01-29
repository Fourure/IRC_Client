#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>

class Message
{
public:
    Message(QString user,QString mess);
    QString toString();

private:
    QString mess;
    QString user;
};

#endif // MESSAGE_H
