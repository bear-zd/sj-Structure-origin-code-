#include <bits/stdc++.h>
//1 3 6 8 9 10 0
using namespace std;
void BiInsertSort(int a[],int length)
{
    int i,j,f,l;
    int temp[length];
    temp[0] = a[0];
    f = 0 ; l = length;//≥ı ºªØ
    for(i=1;i<length;i++)
    {
        if(a[i]>a[0])
        {
            j = f;
            while(a[i]<=temp[j])
            {
                temp[j+1]=temp[j];
                j--;
            }
            temp[j+1] = a[i];
            f++;
        }
        else
        {
            j = l;
            while(a[i]>temp[j])
            {
                temp[j-1] = temp[j];
                if((++j)>=length+1)
                    break;
            }
            temp[j-1] = a[i];
            l--;
        }
    }
    for(i = 0; i<length-1-f;i++)
        a[i] = temp[++l];
    for(j = 0; j<length;j++,i++)
        a[i] = temp[j];
}
int main()
{
//int numlist[] = {1,2,3,4,5,6,7,8,9};
int numlist[] = {2,6,9,1,4,5,7,3,8};
//int numlist[9] = {9,5,1,2,4,6,8,6,3};
BiInsertSort(numlist,9);
for(int i=0;i<9;i++)
    cout<<setw(4)<<numlist[i];
return 0;
}

