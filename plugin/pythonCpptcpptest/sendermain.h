#ifndef SENDERMAIN_H
#define SENDERMAIN_H

#include <QObject>
#include <service/Tcpcommunicateservice.h>
#include <service/CPYcoderservice.h>
#include <Eigen/Core>
#include "form.h"
class sendermain : public QObject
{
    Q_OBJECT
public:
    explicit sendermain(QObject *parent = nullptr);
    CPYcoderservice *m_decoder;
    Tcpcommunicateservice *m_tcp;
    Form *m_form;
signals:

public slots:
   void getmat(Eigen::MatrixXd mat);
   void doitnow();

};

#endif // SENDERMAIN_H
