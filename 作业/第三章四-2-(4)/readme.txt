编写的函数在SortedSeqList.h文件中。为满足题目中的排序要求添加了排序函数，同时沿用沈俊老师的测试函数和部分成员函数。编写的删除边界函数为DRange，代码如下。
```
template <class ElemType>
SeqList <ElemType> & SeqList<ElemType>::DRange(int s,int t)
{int i;bool j;ElemType e;
     for(i=1;i<=length;i++)
        {if(elems[i-1]>=s&&elems[i-1]<=t) //当存在元素在(s,t)内时
            {j=true;break;}
        if(i==length+1)
            j=false;}
        if(j==false)
            cout<<"没有合适的值！"<<endl;
        else
            while(elems[i-1]<=t&&i<=length)
                {DeleteElem(i,e);}
    return *this;
}}
```
在程序中生成顺序表后键入9即可测试。