#include <iostream>
#include <algorithm>
#include <pair>
#include <climits>
#define lli long long int
#define m  1000000000
using namespace std;
pair<int,lli> ans[11][11]={};
pair<int,int> dim[11];
int n;
void output(int l,int r)
{
	cout<<"(";
	int tmp=ans[l][r].first;
	if(tmp==l)		 	{  cout<<"A"<<l+1<<" x "; output(l+1,r); cout<<")"; 		 }
	else if(tmp==r-1)	{  output(l,r-1); cout<<" x A"<<r+1<<")";			 		 }
	else			 	{  output(l,tmp); cout<<" x "; output(tmp+1,r); cout<<")";	 }
}
int main()
{
	int i,j,k,l;
	while(cin>>n && n)
	{	
		for(i=0;i<n;i++)cin>>dim[i].first>>dim[i].second;
		for(i=0;i<n;i++)ans[i][i]={make_pair(i,0)};
		for(i=0;i<n-1;i++)ans[i][i+1]={make_pair(i,dim[i].first*dim[i+1].first*dim[i+1].second)};
		for(i=2;i<l;i++)
		{
			for(j=0;j<l-i;j++)
			{
				k=j+i;ans[j][k]=make_pair(0,INT_MAX);
				for(l=j;l<k;l++)
				{
					if(ans[j][l].second+ans[l+1][k].second+(dim[j].first*dim[l].second*dim[k].second)<ans[j][k].second)
					{
						ans[j][k].second = ans[j][l].second + ans[l+1][k].second + (dim[j].first*dim[l].second*dim[k].second);
						ans[j][k].first=l;
					}
				}
			}
		}
		output(0,n-1);
	}
}
//megatron