#include "tcpmanager.h"
#include "TCPCommunicatorActivator.h"
tcpmanager::tcpmanager(QObject *parent) : QObject(parent),m_client(NULL)
{
    m_client=new TCPClient;
    TCPCommunicatorActivator::registerservice(m_client,"Tcpcommunicateservice");
}
