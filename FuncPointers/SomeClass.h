#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>
#include <QHash>
#include <QString>


class SomeClass : public QObject
{
    Q_OBJECT

public:
    SomeClass();
    QString callerStrStr(QString request);
    void callerStrVoid(QString request);
    int callerStrInt(QString request);
    QString callerIntStr(int inp);


private :
    typedef void (SomeClass::*voidFunctionPtr)();
    typedef QString (SomeClass::*QStringFunctionPtr)(QString);
    typedef int (SomeClass::*QStringIntFunctionPtr)();
    typedef QString (SomeClass::*IntFunctionPtr)(int);


    QHash<QString,voidFunctionPtr> strToVoid;
    QHash<QString,QStringFunctionPtr> strToStr;
    QHash<QString,QStringIntFunctionPtr> strToInt;
    QHash<int, IntFunctionPtr> intToStr;

    void printDate();
    void printTime();
    void voidFuncDefault();

    QString strFunc1(QString inp);
    QString strFunc2(QString inp);
    QString strFuncDefault(QString inp);

    int getHour();
    int getMinute();
    int getSecond();
    int getUnixSecond();
    int badTimeRequest();

    QString handlePositive(int inp);
    QString handleNegative(int inp);
    QString handleZero(int inp);
    QString handleDefaultNum(int inp);

};

#endif // SOMECLASS_H
