#include <iostream>
#include <algorithm>
#define lli long long int
#define m  1000000000
using namespace std;
int main()
{
	lli l,i,j,k,ans[301][301]={};string s;
	while(cin>>s)
  {
    l=s.size();
    for(i=0;i<l;i++)ans[i][i]=1;
    for(i=2;i<l;i+=2)
      for(j=0;j<l-i;j++)
      { 
        ans[j][j+i]=0;
        for(k=j+2;k<=j+i;k+=2)
          if(s[k]==s[j]&&s[k-1]==s[j+1])ans[j][j+i]=(ans[j][j+i]+(((ans[j+1][k-1])*(ans[k][j+i]))%m))%m;
      }    
    cout<<ans[0][l-1]<<"\n";
  }
}
//megatron