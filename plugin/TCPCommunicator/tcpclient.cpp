#include "tcpclient.h"
#include "TCPCommunicatorActivator.h"
#include "OSGIEVENT.h"
TCPClient::TCPClient(QObject *parent) : QObject(parent),mclient(NULL)
{
    mclient=new QTcpSocket;
    connect(mclient,&QTcpSocket::readyRead,this,&TCPClient::tcprecieved);
    TCPCommunicatorActivator::publishsignal(this,SIGNAL(hexrecieved(QByteArray))
                                            ,OSGIEVENT::TCPHEXRECIEVED,Qt::QueuedConnection);
}

void TCPClient::connectport()
{
    if(mclient->state() != QAbstractSocket::ConnectedState)
    {
        //连接服务器
        mclient->connectToHost(IP,portnum);
        //等待连接成功
        if(!mclient->waitForConnected(-1))
        {
            qDebug() << "Connection failed!";
            return;
        }
         qDebug() << "Connection success!";
    }

}

void TCPClient::disconnectport()
{
    if(mclient->state() == QAbstractSocket::ConnectedState)
    {
        mclient->disconnectFromHost();
        qDebug() << "已断开";
    }
}

void TCPClient::send(QByteArray data)
{
    if(mclient->state() == QAbstractSocket::ConnectedState)
    {
        //发送数据
        mclient->write(data);

    }
}

void TCPClient::setport(QString port, QString ip)
{
    IP=ip;
    portnum=port.toInt();
}

void TCPClient::tcprecieved()
{
    QByteArray buffer = mclient->readAll();
    emit hexrecieved(buffer);
}
