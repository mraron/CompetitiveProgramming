/* *
 * Use mask dp, dp[i][mask] => the last used was i and we have used them in masks already.
 * */
#include<bits/stdc++.h>
using namespace std;

int n;
int x[8], y[8];

double dp[8][1<<8];
int par[8][1<<8];

int masksz(int mask) {
	int sz=0;
	for(int j=0;j<n;++j) sz+=((1<<j)&mask)!=0;
	return sz;
}

double calc(int i, int mask) {
	if(masksz(mask)==n) return 0.0;
	
	double ans=1e9;
	
	for(int j=0;j<n;++j) {
		if(((1<<j)&mask)==0) {
			double cans=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))+calc(j, mask|(1<<j))+16;
			if(ans>cans) {
				ans=cans;
				par[i][mask]=j;
			}
			
		}
	}
	
	return ans;
}

int main() {
	cout<<fixed<<setprecision(2);
	int cs=1;
	while(cin>>n && n>0) {
		for(int i=0;i<n;++i) {
			cin>>x[i]>>y[i];
		}
		
		double ans=1e9; int ind=-1;
		for(int i=0;i<n;++i) {
			double cans=calc(i, 1<<i);
			if(cans<ans) {
				ans=cans;
				ind=i;
			}
		}
		
		cout<<"**********************************************************\n";
		cout<<"Network #"<<(cs++)<<"\n";
		int mask=1<<ind;
		int last=ind;
		while(masksz(mask)<n) {
			int nxt=par[last][mask];
			cout<<"Cable requirement to connect ("<<x[last]<<","<<y[last]<<") to ("<<x[nxt]<<","<<y[nxt]<<") is "<<sqrt((x[last]-x[nxt])*(x[last]-x[nxt])+(y[last]-y[nxt])*(y[last]-y[nxt]))+16<<" feet.\n";
			mask|=1<<nxt;
			last=nxt;
		}
		cout<<"Number of feet of cable required is "<<ans<<".\n";
		
	}
}
