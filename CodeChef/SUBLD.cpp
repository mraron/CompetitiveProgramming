/*
This function is not precisely increasing but almost, so we can do binary search and then examine a large enough interval around what've found.
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

ll hatv[20];

ll cnt(ll x) {
	ll ans=1;
	while(x>0) {
		stringstream ss;
		ss<<x;
		string s=ss.str();
		ll leading=s[0]-'0';
		ll nullak=s.size()-1;
		ll le=(x-leading*hatv[nullak])/leading;
		
		ans+=le+1;
		x-=(le+1)*leading;
	}
	return ans;
}

int main() {
	IO;
	hatv[0]=1;
	for(int i=1;i<20;++i) {
		hatv[i]=hatv[i-1]*10;
	}
	
	int T;
	cin>>T;
	while(T--) {
		ll k;
		cin>>k;
		ll x=0; 
		for(ll i=62;i>=0;i--) {
			ll akt=x+(1LL<<i);
			if(cnt(akt)<k) {
				x=akt;
			}
		}
		ll ans=-1;
		for(ll i=x-100;i<=x+100;++i) {
			if(i<0) continue ;
			if(cnt(i)==k) {
				ans=i;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
