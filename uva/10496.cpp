/* *
 * Use bitmask dp.
 * */
#include<bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
int X,Y,x,y;
int n;
vector<pair<int,int>> p;
int dp[10][1<<10];

int masksz(int mask) {
	int sz=0;
	for(int j=0;j<n;++j) sz+=((1<<j)&mask)!=0;
	return sz;
}

int calc(int i, int mask) {	
	if(dp[i][mask]!=-1) return dp[i][mask];
	if(masksz(mask)==n) return abs(p[i].xx-x)+abs(p[i].yy-y);
	int ans=1e9;
	for(int j=0;j<n;++j) {
		if(((1<<j)&(mask))==0) {
			ans=min(ans,calc(j, mask|(1<<j))+abs(p[j].xx-p[i].xx)+abs(p[j].yy-p[i].yy));
		} 
	}
	return dp[i][mask]=ans;
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		memset(dp, -1, sizeof dp);
		cin>>X>>Y>>x>>y>>n;
		p.resize(n);
		for(int i=0;i<n;++i) {
			cin>>p[i].xx>>p[i].yy;
		}
		
		int ans=1e9;
		for(int i=0;i<n;++i) {
			int cans=calc(i, 1<<i)+abs(x-p[i].xx)+abs(y-p[i].yy);
			if(ans>cans) {
				ans=cans;
			}
		}
		
		cout<<"The shortest path has length "<<ans<<"\n";
	}
}
