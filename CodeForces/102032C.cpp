/*
If there's a 0 then we're done. Else try to create 0 greedily if n>m then choose columns else rows until we have a zero.             
*/

//Noszály Áron 11o Debreceni Fazekas Mihály Gimnázium

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

int st[1001][1001];
int t[1001][1001];
int x[1001], y[1001];
int orig[1001][1001];

int main() {
	IO;
	int n,m;
	
	cin>>n>>m;
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			cin>>st[i][j];
		}
	}
	
	bool ok=true;
	int nx=-1, ny=-1;
	
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			cin>>t[i][j];
			t[i][j]-=st[i][j];
			ok&=t[i][j]>=0;
			if(t[i][j]==0) {
				nx=i;
				ny=j;
			}
			orig[i][j]=t[i][j];
		}
	}

	if(!ok) {
		cout<<"-1\n";
		return 0;
	}
	
	if(nx==-1) {
		if(n<=m) {
			int mn=1e9;
			for(int i=0;i<m;++i) {
				mn=min(t[0][i], mn);
			}
			x[0]+=mn;
			for(int i=0;i<m;++i) {
				t[0][i]-=mn;
				if(t[0][i]==0) {
					nx=0;
					ny=i;
				}
			}
		}else {
			int mn=1e9;
			for(int i=0;i<n;++i) {
				mn=min(t[i][0], mn);
			}
			y[0]+=mn;
			for(int i=0;i<n;++i) {
				t[i][0]-=mn;
				if(t[i][0]==0) {
					nx=i;
					ny=0;
				}
			}
		}
	}
		
	for(int i=0;i<n;++i) {
		x[i]+=t[i][ny];
	}
	
	for(int i=0;i<m;++i) {
		y[i]+=t[nx][i];
	}
	
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			ok&=x[i]+y[j]==orig[i][j];
		}
	}
	
	if(!ok) {
		cout<<"-1\n";
		return 0;
	}
	
	
	int cnt=0;
	for(int i=0;i<n;++i) {
		if(x[i]>0) cnt++;
	}
	for(int i=0;i<m;++i) {
		if(y[i]>0) cnt++;
	}
	
	cout<<cnt<<"\n";
	
	for(int i=0;i<n;++i) {
		if(x[i]>0) cout<<"R "<<i+1<<" "<<x[i]<<"\n";
	}
	for(int i=0;i<m;++i) {
		if(y[i]>0) cout<<"C "<<i+1<<" "<<y[i]<<"\n";
	}
	
	return 0;
}
