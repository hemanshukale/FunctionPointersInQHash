#include <QCoreApplication>
#include "SomeClass.h"
#include <QDebug>
#include <QHash>

SomeClass *sC ;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sC = new SomeClass;

    qInfo() << sC->callerStrStr("s1");
    qInfo() << sC->callerStrStr("s2");
    qInfo() << sC->callerStrStr("s3");

    sC->callerStrVoid("printDate");
    sC->callerStrVoid("printTime");
    sC->callerStrVoid("printDateTime");

    qInfo() << sC->callerStrInt("hour");
    qInfo() << sC->callerStrInt("minute");
    qInfo() << sC->callerStrInt("second");
    qInfo() << sC->callerStrInt("UnixSeconds");
    qInfo() << sC->callerStrInt("UnixMiliSeconds");

    qInfo() << sC->callerIntStr(-1);
    qInfo() << sC->callerIntStr(0);
    qInfo() << sC->callerIntStr(1);
    qInfo() << sC->callerIntStr(100);
    qInfo() << sC->callerIntStr(-2);

    return a.exec();
}
