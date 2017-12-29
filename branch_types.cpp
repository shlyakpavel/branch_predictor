#include "branch_types.h"
#include <QString>
#include <QStringList>
#include <QDateTime>
element_type getType(QString element){
    QString cmd = element.split("    ").at(1);
    if (cmd == "Do some stuff") return dostuff;
    else return jumpto;
}

QString element::toString(){
    QString typestr;
    if (type==jumpto) typestr="Jump to"; else typestr="Do some stuff";
    return QString::number(curaddr).append("    ").append(typestr).append("    ").append(QString::number(pointsto));
}

element::element(QString data){
    QStringList args = data.split("    ");
    curaddr=args.at(0).toInt();
    if (args.at(1)=="Jump to") type=jumpto; else type=dostuff;
    pointsto=args.at(2).toInt();
}

element::element(){
    curaddr=0;
    pointsto=0;
}

element::~element(){

}

element getElementBynooom(int i){
    qsrand (QDateTime::currentMSecsSinceEpoch()+i);
    element el;
    el.curaddr=i;
    el.type=static_cast<element_type>(qrand() % 2);
    el.pointsto=qrand() % 10;
    return el;
}
