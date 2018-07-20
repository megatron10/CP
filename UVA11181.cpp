#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int i,n,r;
double prob[21]={},comp[21]={};
double solve(int i=0,int s=0,double p=1.0)
{
	if(i==n && r==s)return p;
	if(s>r || n-i<r-s)return 0;
	double p1;
	comp[i]+= p1=solve(i+1,s+1,p*(prob[i]));
	return p1+solve(i+1,s,p*(1-prob[i]));
}
int main()
{
	int t=1;
	while(cin>>n>>r && n|r)
	{
		for(i=0;i<n;i++){cin>>prob[i];comp[i]=0.0;}
		double tmp=solve(0,0);
		cout<<"Case "<<(t++)<<":\n";
		for(i=0;i<n;i++)printf("%.6lf\n",(comp[i]/tmp));
	}
}