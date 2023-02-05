#include "sendermain.h"
#include <pythonCpptcpptestActivator.h>
#include <OSGIEVENT.h>
#include <QtDebug>
sendermain::sendermain(QObject *parent) : QObject(parent),m_form(NULL)
{
    m_form=new Form;
    m_decoder=pythonCpptcpptestActivator::getService<CPYcoderservice>("CPYcoderservice");

    m_tcp1=pythonCpptcpptestActivator::getService<Tcpcommunicateservice>("Tcpcommunicateservice");
    m_tcp1->setport("8001","127.0.0.1");
    m_tcp1->connectport();

    m_tcp=m_tcp1->cloneservice();
    m_tcp->setport("8002","127.0.0.1");
    m_tcp->connectport();

    pythonCpptcpptestActivator::subscribeslot(this,SLOT(getmat(Eigen::MatrixXd))
                                            ,OSGIEVENT::MAT_GET_NOW,Qt::QueuedConnection);
    connect(m_form,SIGNAL(sig_doit()),this,SLOT(doitnow()));
    connect(m_form,SIGNAL(sig_doit2()),this,SLOT(doitnow2()));

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
    m_decoder->sendMAT(target_state,m_tcp);//允许多个接口转接，所以需要引入第二个参数：所用的接口
}

void sendermain::doitnow2()
{
    Eigen::MatrixXd target_state;
    target_state.resize(3,3);
    target_state<<1.0,  1.0,  1.0,
                 1.0,  0.0,  1.0,
                1.0,  1.0,  1.00;
    m_decoder->sendMAT(target_state,m_tcp1);
}
