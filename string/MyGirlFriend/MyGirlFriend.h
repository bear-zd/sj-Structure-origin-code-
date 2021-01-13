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
        cout<<"你好我是你女朋友"<<name<<"!"<<endl;
    }
    virtual ~MyGirlFriend()
    {
        cout<<"你女朋友"<<Name<<"已被析构！";
    }
    void Date()
    {
        cout<<"我们去约会吧"<<endl;
    }
private:
    int Age;
    string Name;
};



#endif // MYGIRLFRIEND_H

