#include "C_Python_decodeActivator.h"


C_Python_decodeActivator* C_Python_decodeActivator::m_instance=Q_NULLPTR;
PluginContext* C_Python_decodeActivator::m_CONTEXT=Q_NULLPTR;
C_Python_decodeActivator::C_Python_decodeActivator(QObject *parent) : QObject(parent),m_decode(NULL)
{
    m_instance=this;
}
void C_Python_decodeActivator::init(PluginContext *CONTEXT)
{
    m_CONTEXT=CONTEXT;
}
void C_Python_decodeActivator::start()
{
    m_decode=new CPyDevoder;
}
void C_Python_decodeActivator::stop()
{
delete this;

}
