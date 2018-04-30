#include<iostream>
#include<map>

using namespace std;

map<int,map<int,int> >dp;

int solve(map<int,map<int,int> >mat,int n,int m, int x,int y)
{
	//int res = 0;
	
	if(x<0 || y>m || x>n || y<0)
	return 0;
	
	if(dp[x][y] != 0)
	{
		return dp[x][y];
		//return res;
	}
	
	return dp[x][y] = max(max(solve(mat,n,m,x+1,y) + mat[x][y],solve(mat,n,m,x+1,y-1) + mat[x][y]),solve(mat,n,m,x+1,y+1) + mat[x][y]);
	//res+= dp[x][y];
	
	//return res;
}

int main()
{
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		dp.clear();
		int n,m,x;
		cin>>n>>m;
		
		map<int,map<int,int> >mat;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>mat[i][j];
				//mat[i][j] = x;
			}
		}
		
		int pg=0;
		for(int i=0;i<m;i++)
		pg = max(solve(mat,n,m,0,i), pg);
		
		cout<<pg<<endl;
	}
}
