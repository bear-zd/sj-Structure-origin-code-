#include "bits/stdc++.h"
using namespace std;
void Frequency(const string b);
int main()
{
    char a[1000];
    cin>>a;
    Frequency(a);
    return 0;
}
void Frequency(const string b)
{
    int num[128];
    for(int i=0; i<128; num[i++]=0);
    for(int i=0; i<b.length(); i++)
        num[b[i]]++;
    for(int i=0; i<128; i++)
        if(num[i]!=0)
            printf("%c:%d\n",i,num[i]);
    return ;
}
