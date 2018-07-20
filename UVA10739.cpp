#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,j,k,t,l,ans[1000][1000]={}; string s;
	cin>>t;
	for(n=1;n<=t;n++)
	{
		cin>>s;
		l=s.size();
		for(i=0;i<l;i++)ans[i][i]=0;
		for(i=0;i<l-1;i++)ans[i][i+1]=((s[i]==s[i+1])?0:1);
		for(i=2;i<l;i++)for(j=0;j<l-i;j++)
		{
			k=j+i;
			ans[j][k]=min(min(ans[j][k-1],ans[j+1][k])+1,ans[j+1][k-1]+((s[j]==s[k])?0:1));
		}	
		cout<<"Case "<<n<<": "<<ans[0][l-1]<<"\n";		
	}
}