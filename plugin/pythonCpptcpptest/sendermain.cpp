#include "sendermain.h"
#include <pythonCpptcpptestActivator.h>
#include <OSGIEVENT.h>
#include <QtDebug>
sendermain::sendermain(QObject *parent) : QObject(parent),m_form(NULL)
{
    m_form=new Form;
    m_decoder=pythonCpptcpptestActivator::getService<CPYcoderservice>("CPYcoderservice");
    m_tcp=pythonCpptcpptestActivator::getService<Tcpcommunicateservice>("Tcpcommunicateservice");
    m_tcp->setport("8001","127.0.0.1");
    m_tcp->connectport();
    pythonCpptcpptestActivator::subscribeslot(this,SLOT(getmat(Eigen::MatrixXd))
                                            ,OSGIEVENT::MAT_GET_NOW,Qt::QueuedConnection);
    connect(m_form,SIGNAL(sig_doit()),this,SLOT(doitnow()));
    m_form->show();
}

void sendermain::getmat(Eigen::MatrixXd mat)
{
    qDebug()<<"mat get!!";
}

void sendermain::doitnow()
{
    Eigen::MatrixXd target_state;
    target_state.resize(3,3);
    target_state<<13.0,  0.0,  3.0,
                 3.0,  0.0,  0.0,
                0.0,  13.0,  0.00;
    m_decoder->sendMAT(target_state);
}
