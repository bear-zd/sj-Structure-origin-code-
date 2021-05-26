#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int* Countsort(int a[],int length)
{
    int *b = new int[length];
    int *c = new int[length];
    for(int i = 0 ; i<length ; i++)
        b[i]=0;
    for(int i = 0 ; i<length-1 ; i++ )
        for ( int j=i+1;j<length;j++)
            {if(a[j]<a[i])
                b[i]++;
            else
                b[j]++;}
    for(int i=0;i<length;i++)
    {
    for(int j=0;j<length;j++)
    if(b[j]==i)
    c[i] = a[j];
    }
    return c;
}
int main()
{//int numlist[] = {1,2,3,4,5,6,7,8,9};
//int numlist[] = {2,6,9,1,4,5,7,3,8};
int numlist[] = {9,5,1,2,4,6,8,6,3};
int *afterlist;
afterlist = Countsort(numlist,9);
for(int i=0;i<9;i++)
    cout<<setw(4)<<afterlist[i];
return 0;
}

