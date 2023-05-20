#include "SomeClass.h"
#include <QDebug>
#include <QDateTime>

SomeClass::SomeClass()
{
    strToVoid["printDate"] = &SomeClass::printDate;
    strToVoid["printTime"] = &SomeClass::printTime;

    strToStr["s1"] = &SomeClass::strFunc1;
    strToStr["s2"] = &SomeClass::strFunc2;

    strToInt["hour"] = &SomeClass::getHour;
    strToInt["minute"] = &SomeClass::getMinute;
    strToInt["second"] = &SomeClass::getSecond;
    strToInt["UnixSeconds"] = &SomeClass::getUnixSecond;

    intToStr[0]  = &SomeClass::handleZero;
    intToStr[1]  = &SomeClass::handlePositive;
    intToStr[-1] = &SomeClass::handleNegative;

}

void SomeClass::printDate()
{
    qInfo() << Q_FUNC_INFO << QDateTime::currentDateTime().date();
}
void SomeClass::printTime()
{
    qInfo() << Q_FUNC_INFO << QDateTime::currentDateTime().time();
}
void SomeClass::voidFuncDefault()
{
    qInfo() << Q_FUNC_INFO << "void Default resp";
}

QString SomeClass::strFunc1(QString inp)
{
    qInfo() << Q_FUNC_INFO ;
    return inp + "str Func 1 called";
}
QString SomeClass::strFunc2(QString inp)
{
    qInfo() << Q_FUNC_INFO ;
    return inp + "str Func 2 called";
}
QString SomeClass::strFuncDefault(QString inp)
{
    qInfo() << Q_FUNC_INFO << "str Default resp";
    return inp + "str Default resp";
}

int SomeClass::getHour()
{
    qInfo() << Q_FUNC_INFO ;
    return QDateTime::currentDateTime().time().hour();
}

int SomeClass::getMinute()
{
    qInfo() << Q_FUNC_INFO ;
    return QDateTime::currentDateTime().time().minute();
}

int SomeClass::getSecond()
{
    qInfo() << Q_FUNC_INFO ;
    return QDateTime::currentDateTime().time().second();
}

int SomeClass::getUnixSecond()
{
    qInfo() << Q_FUNC_INFO ;
    return QDateTime::currentDateTime().toSecsSinceEpoch();
}

int SomeClass::badTimeRequest()
{
    qInfo() << Q_FUNC_INFO ;
    return -1;
}

QString SomeClass::handlePositive(int request)
{
    qInfo() << Q_FUNC_INFO << "Number is Positive" << request;
    return "Number is Positive" ;

}
QString SomeClass::handleNegative(int request)
{
    qInfo() << Q_FUNC_INFO << "Number is Negative" << request;
    return "Number is Negative" ;
}
QString SomeClass::handleZero(int request)
{
    qInfo() << Q_FUNC_INFO << "Number is zero" << request;
    return "Number is Zero" ;
}

QString SomeClass::handleDefaultNum(int request)
{
    qInfo() << Q_FUNC_INFO << "Default Num handler" << request;
    return "Default Handler for: " + QString::number(request) ;
}

QString SomeClass::callerStrStr(QString request)
{
    return (this->*(strToStr.value(request,&SomeClass::strFuncDefault)))(request);
    return (this->*strToStr[request])(request);
}

void SomeClass::callerStrVoid(QString request)
{
    return (this->*(strToVoid.value(request,&SomeClass::voidFuncDefault) ))();
    return (this->*strToVoid[request])();
}


int SomeClass::callerStrInt(QString request)
{
    return (this->*(strToInt.value(request,&SomeClass::badTimeRequest) ))();
    return (this->*strToInt[request])();
}

QString SomeClass::callerIntStr(int request)
{
    return (this->*(intToStr.value(request,&SomeClass::handleDefaultNum)))(request);
}

