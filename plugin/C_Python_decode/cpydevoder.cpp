#include "cpydevoder.h"
#include "C_Python_decodeActivator.h"
#include "OSGIEVENT.h"
#include "defines/CpyDefines.h"
CPyDevoder::CPyDevoder(QObject *parent) : QObject(parent)
{
    C_Python_decodeActivator::subscribeslot(this,SLOT(datarecieved(QByteArray))
                                            ,OSGIEVENT::TCPHEXRECIEVED,Qt::QueuedConnection);
    qRegisterMetaType<Eigen::MatrixXd>("Eigen::MatrixXd");
    C_Python_decodeActivator::publishsignal(this,SIGNAL(matrecieved(Eigen::MatrixXd))
                                            ,OSGIEVENT::MAT_GET_NOW,Qt::QueuedConnection);
    m_service=C_Python_decodeActivator::getService<Tcpcommunicateservice>("Tcpcommunicateservice");
    C_Python_decodeActivator::registerservice(this,"CPYcoderservice");

}

void CPyDevoder::parse(const char *data, CPYDATA::mat_trans &PTtopic)
{
    const char* ptData = data;
    int offset;

    memcpy((void *)&PTtopic.header,(void *)(ptData),  2);
    offset =2;
    ptData += offset;

    memcpy((void *)&PTtopic.rows,(void *)(ptData),  4);
    offset =4;
    ptData += offset;

    memcpy((void *)&PTtopic.cols,(void *)(ptData),  4);
    offset =4;
    ptData += offset;

    offset=8;
    double element=0;
    for(int i=0;i<PTtopic.rows;i++)
    {
        CPYDATA::one_line onelinemat;

        for(int j=0;j<PTtopic.cols;j++)
        {

            memcpy((void *)&element,(void *)(ptData),  8);
            onelinemat.online.insert(j,element);
            ptData += offset;
        }
        PTtopic.whole_mat.append(onelinemat);
    }

}

Eigen::MatrixXd CPyDevoder::make_mat(CPYDATA::mat_trans &PTtopic)
{
    Eigen::MatrixXd targetmat;
    targetmat.resize(PTtopic.rows,PTtopic.cols);
    targetmat.setZero();
    for(int i=0;i<PTtopic.rows;i++)
    {

        for(int j=0;j<PTtopic.cols;j++)
        {

            targetmat(i,j)=PTtopic.whole_mat[i].online[j];
        }
    }
    return targetmat;
}

void CPyDevoder::sendMAT(Eigen::MatrixXd mat)
{
    CPYDATA::mat_trans matsend;
    matsend.rows=mat.rows();
    matsend.cols=mat.rows();
    matsend.header=0xaadd;

    for(int i=0;i<matsend.rows;i++)
    {
        CPYDATA::one_line onelinemat;
        for(int j=0;j<matsend.cols;j++)
        {
            onelinemat.online.insert(j,mat(i,j));
        }
        matsend.whole_mat.append(onelinemat);
    }

    QByteArray sendingdata;//应用层到协议层
    execute(matsend,sendingdata);
    m_service->send(sendingdata);
}
void CPyDevoder::execute( CPYDATA::mat_trans ptopic, QByteArray &sending_data)
{
    const char* ptData = m_preassigned_mat;
    int offset,size;

    size=0;
    offset=2;
    memcpy((void *)(ptData), (void *)&ptopic, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (CPYDATA::mat_trans::rows);
    memcpy((void *)(ptData), (void *)&ptopic.rows, offset);
    ptData += offset;
    size+=offset;

    offset=sizeof (CPYDATA::mat_trans::cols);
    memcpy((void *)(ptData), (void *)&ptopic.cols, offset);
    ptData += offset;
    size+=offset;

    offset=8;
    double element=0;
    for(int i=0;i<ptopic.rows;i++)
    {
        for(int j=0;j<ptopic.cols;j++)
        {
            element=ptopic.whole_mat[i].online[j];
            memcpy((void *)(ptData), (void *)&element, offset);
            ptData += offset;
            size+=offset;
        }
    }

    sending_data.setRawData(m_preassigned_mat,size);
}
void CPyDevoder::datarecieved(QByteArray data)
{
    int size=data.size();
    quint8* ptCache=(quint8*)data.data();
    if((ptCache[0]==0xdd) && (ptCache[1]==0xaa)) //for matrix transport
    {
        CPYDATA::mat_trans  m_mat;
        parse((const char*)data,m_mat);
        Eigen::MatrixXd targetmat=make_mat(m_mat);
        emit matrecieved(targetmat);
    }

}
