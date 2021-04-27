#include <bits/stdc++.h>
using namespace std;
#define infity -1
#define N 6
#define UNVISITED 0
#define VISITED 1
#define ALLVISITED 2

void DFS(int v , int (&NET)[N][N]);
int VISIT[N];
int FATHER[N];
void DFS(int v, int (&NET)[N][N])
{

    VISIT[v] = VISITED;
    for(int i=0 ; i < N ; i++)
    {
        if(i != v && NET[v][i]!=infity)
        {
            if(VISIT[i] == 1 && FATHER[v] != i)
            {
                 int MW = -1,VM1,VM2;
                cout << "存在环。";
                int temp = v;
                if (NET[temp][i] >MW)
                    {MW =  NET[temp][i];VM1=i;VM2=temp;}
                while (temp != i)
                {
                    cout << temp << "<-";
                    if (NET[FATHER[temp]][temp] > MW)
                        {MW =  NET[FATHER[temp]][temp];VM1=FATHER[temp];VM2=temp;}
                    temp = FATHER[temp];
                }
                cout << temp <<endl;
                NET [VM1][VM2] = infity;
                NET [VM2][VM1] = infity;
            }
        else
            if(VISIT[i] == UNVISITED)
        {
            FATHER[i] = v;
            DFS(i , NET);
        }
        }
    }
    VISIT[v] = 2;
}
int main()
{
    int net[N][N] =
   {{infity,        6,        3,        5, infity, infity},
	{       6, infity, infity,        1,         5, infity},
	{       3, infity, infity,        6, infity,         6},
	{       5,        1,        6, infity,        5,         4},
	{infity,        5, infity,        5, infity,         2},
	{infity, infity,       6,         4,         2, infity}};
    memset(VISIT , 0 , sizeof(VISIT));
    memset(FATHER , -1 ,sizeof(FATHER));
    cout << "原图："<<endl;
    for (int i = 0; i< N ;i++)
        {for (int j = 0 ; j< N;j++)
            {if (net[i][j] ==infity)
                cout << "  infity" ;
            else
                cout <<setw(8)<<net[i][j] ;
            }
        cout<< endl;}
    cout << "DFS寻找环并删除边"<<endl;
    for ( int i = 0; i< N;i++)
        if(!VISIT[i])
            DFS(i,net);

    cout << "删除后："<<endl;
    for (int i = 0; i< N ;i++)
        {for (int j = 0 ; j< N;j++)
            {if (net[i][j] ==infity)
                cout << "  infity" ;
            else
                cout <<setw(8)<<net[i][j] ;
            }
        cout<< endl;}
    cout << "最小生成树:"<<endl;
    for (int i = 0 ; i< N ;i++)
        for (int j = i ; j < N ; j++)
    {
        if (net[i][j]!=infity)
            cout << setw(4)<< i << "->" << j <<endl;
    }

}

