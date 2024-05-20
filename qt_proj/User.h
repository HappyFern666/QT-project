#ifndef USER_H
#define USER_H

#include <QString>

class User {
private:
    QString Id;
    QString Password;
public:
    QString & setId();
    QString & setPassword();
};

#endif // USER_H
