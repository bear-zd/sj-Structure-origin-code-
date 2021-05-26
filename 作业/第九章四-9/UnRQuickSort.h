#include "LinkStack.h"
int Devision(int a[],int low,int high)
{
    int temp = a[low] ;
    while(low<high )
    {
        while(low<high && a[high]>=temp)
            high--;
        a[low] = a[high];
        while(low<high && a[low]<=temp)
            low++;
        a[high] = a[low];
    }
    a[low] = temp;
    return low;
}
void UnRQuickSort(int a[],int length)
{
    int low,high,mid;

    LinkStack<int> s;
    s.Push(0);s.Push(length-1);
    while(!s.IsEmpty())
    {
        s.Pop(high);s.Pop(low);
        while(high-low>2)
        {
            mid = Devision(a,low,high);
            if (high-mid>mid-low)
            {
                s.Push(mid+1);
                s.Push(high);
                high = mid - 1;
            }
            else
            {
            s.Push(low);
            s.Push(mid - 1);
            low = mid + 1;
            }
        }
        if(high - low ==1)
        {
            if(a[low] > a[high])
                Swap(a[low],a[high]);
        }
        else if(high-low==2)
        {
            if (a[low] > a[low+1])
                Swap(a[low],a[low+1]);
            if (a[low] > a[high])
                Swap(a[low],a[high]);
            if (a[low+1] > a[high])
                Swap(a[low+1],a[high]);
        }
    }
}
void Swap(int &a,int &b)
{
    int temp;
    temp = a ;
    a = b ;
    b = temp ;
}
