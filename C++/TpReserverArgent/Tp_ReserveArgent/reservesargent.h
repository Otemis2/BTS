#ifndef RESERVESARGENT_H
#define RESERVESARGENT_H

class reservesArgent
{
protected:
    float solde;
public:
    reservesArgent();
    ~reservesArgent();
    float getSolde();
    void crediter(float money);
    void debiter(float money);
};

#endif // RESERVESARGENT_H
