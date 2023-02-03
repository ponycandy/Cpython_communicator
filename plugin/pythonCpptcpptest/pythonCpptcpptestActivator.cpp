#include "pythonCpptcpptestActivator.h"


pythonCpptcpptestActivator* pythonCpptcpptestActivator::m_instance=Q_NULLPTR;
PluginContext* pythonCpptcpptestActivator::m_CONTEXT=Q_NULLPTR;
pythonCpptcpptestActivator::pythonCpptcpptestActivator(QObject *parent) : QObject(parent),mains(NULL)
{
    m_instance=this;
}
void pythonCpptcpptestActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void pythonCpptcpptestActivator::start()
{
    mains=new sendermain;
}
void pythonCpptcpptestActivator::stop()
{
delete this;

}
