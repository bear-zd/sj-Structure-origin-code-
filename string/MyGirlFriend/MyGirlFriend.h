#ifndef MYGIRLFRIEND_H
#define MYGIRLFRIEND_H
#include <bits/stdc++.h>
using namespace std;
class MyGirlFriend
{
public:
    MyGirlFriend(int age=20,string name="xxx")
    {
        Age=age;
        Name=name;
        cout<<"���������Ů����"<<name<<"!"<<endl;
    }
    virtual ~MyGirlFriend()
    {
        cout<<"��Ů����"<<Name<<"�ѱ�������";
    }
    void Date()
    {
        cout<<"����ȥԼ���"<<endl;
    }
private:
    int Age;
    string Name;
};



#endif // MYGIRLFRIEND_H

