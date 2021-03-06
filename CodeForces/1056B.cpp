/*
 * Just calculate everything in mod m then count how many such integers are there in range [1..n].              
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

ll n,m;

ll count(ll mod) {
	if(mod==0) {
		return n/m;
	}
	
	return n/m+((n%m)>=mod?1:0);
}

int main() {
	IO;
	cin>>n>>m;
	ll ans=0;
	for(int i=0;i<m;++i) {
		for(int j=0;j<m;++j) {
			if((i*i+j*j)%m==0) {
		//		cerr<<i<<" "<<j<<"\n";
				ans+=count(i)*count(j);
			}
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}
