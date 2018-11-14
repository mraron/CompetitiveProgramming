/*
ID: noszaly1
TASK: {TASK}
LANG: C++11               
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
#define int ll

const int mod=1e9+7;
template<typename T> 
T fastpow(T x, int a) {
	if(a==0) return 1;
	if(a==1) return x;
	
	T fele=fastpow(x, a/2);
	T ans=(fele*fele)%mod;
	
	if(a&1) ans=(ans*x)%mod;
	
	return ans;
}

main() {
	IO;
	int n,q;
	cin>>n>>q;
	int t[n];
	for(int i=0;i<n;++i) {
		char c;
		cin>>c;
		t[i]=c-'0';
	}
	for(int i=1;i<n;++i) t[i]+=t[i-1];
	
	for(int i=0;i<q;++i) {
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		int eg=t[b]-(a>0?t[a-1]:0);
		int nu=b-a+1-eg;
		//cerr<<eg<<" "<<nu<<"\n";
		cout<<((fastpow<ll>(2LL, eg)-1)*(fastpow<ll>(2LL, nu)))%mod<<"\n";
	}
	
	return 0;
}
