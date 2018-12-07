/*
Notice that we should use only v's and some partial then the rest will be 0 (this can be proven but can be seen intuitively), then just use dp.
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

ll dp[1001][2][1001][3];
ll n,s,v;
vector<ll> t;

ll kicsi;

ll calc(int i, bool volt, int j, int typ) {
	
	if(i==0) {
		return ((j==0&&volt)?0:1LL<<60);
	}
	if(dp[i][volt][j][typ]!=-1) return dp[i][volt][j][typ];
	
	ll ans=1LL<<60;
	ll last=-1;
	if(typ==2) last=v;
	if(typ==1) last=kicsi;
	if(typ==0) last=0;
	
	if(!volt) {
		ans=min(ans, calc(i-1, true, j, 1)+t[i-1]*kicsi*last);
	}
	
	if(j>0) {
		ans=min(ans, calc(i-1, volt, j-1, 2)+t[i-1]*v*last);
	}
	
	ans=min(ans, calc(i-1, volt, j, 0));
	return dp[i][volt][j][typ]=ans;
}

int main() {
	IO;
	
	cin>>n>>s>>v;
	if(s==0) {
		cout<<"0\n";
		return 0;
	}
	t.resize(n-1);
	for(int i=0;i<n-1;++i) cin>>t[i];
	
	memset(dp, -1, sizeof dp);
	ll cnt;
	if(s%v==0) {
		kicsi=v;
		cnt=s/v-1;
	}else {
		cnt=s/v;
		kicsi=s%v;
	}
	
	ll ans=1LL<<60;
	
	ans=min(ans, calc(n-1, false, cnt, 0));
	ans=min(ans, calc(n-1, true, cnt, 1));
	if(cnt>0) ans=min(ans, calc(n-1, false, cnt-1, 2));
	cout<<ans<<"\n";
	
	return 0;
}
