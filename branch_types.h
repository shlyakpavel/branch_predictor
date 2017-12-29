#ifndef BRANCH_TYPES_H
#define BRANCH_TYPES_H
#include <QString>

enum mode { forward, jump, clever };
enum element_type{ dostuff, jumpto };

class element{
public:
    element();
    element(QString data);
    ~element();
    int curaddr;
    int pointsto;
    QString toString();
    element_type type;
};

QString nameType(element_type type);
QString formElement(int addr, element_type type, QString param);
QString loadElement(int i);
element getElementBynooom(int i);

#endif // BRANCH_TYPES_H
