#pragma once
//do not declare pragma pack(1) here
//it will cause system crash
//do remember that pragma pack(4) is in default
#include <stdint.h>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include <QObject>
#include <QColor>
#include <QPointF>
#include <QString>
#include <QImage>
#include <QSharedPointer>

namespace CPYDATA {

#pragma pack(push,1)
typedef struct _one_line
{
    QVector<double> online;
}one_line;
#pragma pack(pop)

#pragma pack(push,1)
typedef  struct   _mat_trans{
    short   header;
    int rows;
    int cols;
    QVector<one_line> whole_mat;
}mat_trans;
#pragma pack(pop)
}


Q_DECLARE_METATYPE(CPYDATA::one_line);
Q_DECLARE_METATYPE(CPYDATA::mat_trans);


