
#ifndef TCPCOMMUNICATESERVICE_H
#define TCPCOMMUNICATESERVICE_H

#include <QObject>
class Tcpcommunicateservice
{
public:
    virtual ~Tcpcommunicateservice(){}
    virtual void setport(QString port,QString ip)=0;
    virtual void connectport()=0;
    virtual void disconnectport()=0;
    virtual void send(QByteArray data)=0;

};
#define Tcpcommunicateservice_iid "Tcpcommunicateservice"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(Tcpcommunicateservice,Tcpcommunicateservice_iid  )
QT_END_NAMESPACE

#endif

