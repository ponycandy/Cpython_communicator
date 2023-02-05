#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <service/Tcpcommunicateservice.h>
class TCPClient : public QObject,public Tcpcommunicateservice
{
    Q_OBJECT
public:
    explicit TCPClient(QObject *parent = nullptr);
    QTcpSocket *mclient;

    void connectport() override;
    void disconnectport() override;
    void send(QByteArray data) override;
    void setport(QString port, QString ip) override;
    Tcpcommunicateservice* cloneservice() override;

    QString IP;
    int portnum;

signals:
    void hexrecieved(QByteArray data);
public slots:
    void tcprecieved();
};

#endif // TCPCLIENT_H
