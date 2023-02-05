#ifndef CPYDEVODER_H
#define CPYDEVODER_H

#include <QObject>
#include <defines/CpyDefines.h>
#include <Eigen/Core>
#include <service/CPYcoderservice.h>
#include <service/Tcpcommunicateservice.h>
class CPyDevoder : public QObject,public CPYcoderservice
{
    Q_OBJECT
public:
    explicit CPyDevoder(QObject *parent = nullptr);
    void parse(const char *data, CPYDATA::mat_trans &PTtopic);
    Eigen::MatrixXd make_mat(CPYDATA::mat_trans &PTtopic);
    void sendMAT(Eigen::MatrixXd mat,Tcpcommunicateservice * usingservice) override;
    void execute( CPYDATA::mat_trans ptopic, QByteArray &sending_data);
    Tcpcommunicateservice *m_service;
    char m_preassigned_mat[4000];//最大允许值,也就是一次最多传输五百个左右元素
signals:
    void matrecieved(Eigen::MatrixXd mat);
public slots:
    void datarecieved(QByteArray data);
};

#endif // CPYDEVODER_H
