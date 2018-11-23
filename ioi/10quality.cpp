/*
I do binary search on the smallest median. I create a RxC matrix T that for T[i][j]=-1 if Q[i][j]<mid 0 if Q[i][j]=mid else 1 So if in some HxW subrectangle the sum is non positive we know that the solution is at most mid.
*/
#include "grader.h"
#include<iostream>
using namespace std;
typedef long long ll;
int sum[3001][3001];
int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
    
    
    ll l=0, r=2e9;
    while(l<r) {
	ll mid=(l+r)/2LL;
	//cerr<<l<<" "<<r<<"\n";
	
	for(auto& i:sum)
	for(auto& j:i) j=0;
	
	for(int i=0;i<R;++i) {
	    for(int j=0;j<C;++j) {
		if(mid==Q[i][j]) {
		    sum[i][j]=0;
		}else if(mid<Q[i][j]) {
		    sum[i][j]=1;
		}else {
		    sum[i][j]=-1;
		}
	    }
	}
	
	for(int i=0;i<R;++i) {
	    for(int j=0;j<C;++j) {
		if(i>0)sum[i][j]+=sum[i-1][j];
		if(j>0)sum[i][j]+=sum[i][j-1];
		if(i>0&&j>0)sum[i][j]-=sum[i-1][j-1];
	    }
	}
	
	bool ok=false;
	for(int i=0;i+H-1<R&&!ok;++i) {
	    for(int j=0;j+W-1<C&&!ok;++j) {
		int x=i+H-1, y=j+W-1;
		int szum=sum[x][y]-(j>0?sum[x][j-1]:0)-(i>0?sum[i-1][y]:0)+(i>0&&j>0?sum[i-1][j-1]:0);
		ok|=szum<=0;
	    }
	}
	
	if(ok) {
	    r=mid;
	}else {
	    l=mid+1;
	}
    }
    
    return l;
}
