#include <bits/stdc++.h>
#include "UnRQuickSort.h"
using namespace std;
int main()
{
//int numlist[] = {1,2,3,4,5,6,7,8,9};
int numlist[] = {2,6,9,1,4,5,7,3,8};
//int numlist[9] = {9,5,1,2,4,6,8,6,3};
UnRQuickSort(numlist,9);
for(int i=0;i<9;i++)
    cout<<setw(4)<<numlist[i];
return 0;
}
