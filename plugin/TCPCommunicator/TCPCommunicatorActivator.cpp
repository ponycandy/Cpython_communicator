#include "TCPCommunicatorActivator.h"


TCPCommunicatorActivator* TCPCommunicatorActivator::m_instance=Q_NULLPTR;
PluginContext* TCPCommunicatorActivator::m_CONTEXT=Q_NULLPTR;
TCPCommunicatorActivator::TCPCommunicatorActivator(QObject *parent) : QObject(parent),m_manager(NULL)
{
    m_instance=this;
}
void TCPCommunicatorActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void TCPCommunicatorActivator::start()
{
    m_manager=new tcpmanager;
}
void TCPCommunicatorActivator::stop()
{
delete this;

}
