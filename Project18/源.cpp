//陈旭升好帅
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cstdlib> 
#define N 7//凸多边形边数+1
#define maxn 100
//int w[][N] = { { 0,2,2,3,1,4 },{ 2,0,1,5,2,3 },{ 2,1,0,2,1,4 },{ 3,5,2,0,6,2 },{ 1,2,1,6,0,1 },{ 4,3,4,2,1,0 } };//凸多边形的权  
using namespace std;
int MinweightTriangulation(int n, int(*t)[maxn], int(*s)[maxn],int (*w)[maxn]);
void trace_back(int i, int j, int(*s)[maxn]);
int Weight(int a, int b, int c,int (*w)[maxn]);
int main()
{
	int s[maxn][maxn], t[maxn][maxn],w[maxn][maxn];
	int n;
	cout<<"请输入顶点的个数：";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>w[i][j];
			if((i+1)%n==0)
			{
				cout<<endl;
			}
		} 
	}
	cout << "多边形的最优三角剖分为:" << MinweightTriangulation(N - 1, t, s,w) << endl;
	cout << "最有三角结构为：" << endl;
	trace_back(1, 5, s);
	return 0;
}
int MinweightTriangulation(int n, int(*t)[N], int(*s)[N],int (*w)[maxn])
{
	for (int i = 1; i <= n; i++)
	{
		t[i][i] = 0;
	}
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			t[i][j] = t[i + 1][j] + Weight(i - 1, i, j,w);
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int u = t[i][k] + t[k + 1][j] + Weight(i - 1, k, j,w);
				if (u < t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
	return t[1][N - 2];
}
void trace_back(int i, int j, int(*s)[N])
{
	if (i == j)  return;
	trace_back(i, s[i][j], s);
	trace_back(s[i][j] + 1, j, s);
	cout << "三角剖分顶点：V" << i - 1 << ",V" << j << ",V" << s[i][j] << endl;
}
int Weight(int a, int b, int c,int (*w)[maxn])
{
	return w[a][b] + w[b][c] + w[a][c];
	cout<<"傻逼"<<endl;
}
