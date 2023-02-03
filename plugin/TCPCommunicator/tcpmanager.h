#ifndef TCPMANAGER_H
#define TCPMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <tcpclient.h>
class tcpmanager : public QObject
{
    Q_OBJECT
public:
    explicit tcpmanager(QObject *parent = nullptr);
    TCPClient *m_client;
signals:

};

#endif // TCPMANAGER_H
