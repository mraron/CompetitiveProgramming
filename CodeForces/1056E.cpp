/*
 * In contest I felt that we have a small number of states but instead of giving in to this feeling I rushed and made a stupid sol with Z algorithm.
 * This solution is somewhat a mixture of the official and mine, so it uses hashing and Z algo to check substring equality xd Also because of this problem I've created a rolling hash template in templates.            
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

vector<int> zalgo(string& str) {
	vector<int> z(sz(str));
	int L=0, R=0;
	for(int i=1;i<sz(str);++i) {
		if(i>R) {
			L=i;R=i;
			while(R<sz(str) && str[R]==str[R-L]) R++;
			z[i]=R-L;
			R--;
		}else {
			if(z[i-L]+i<R) {
				z[i]=z[i-L];
			}else {
				L=i;
				while(R<sz(str) && str[R]==str[R-L]) R++;
				z[i]=R-L;
				R--;
			}
		}
	}
	
	return z;
}

ll fastpow(ll a, ll b, ll mod) {
	if(b==0) return 1;
	ll fele=fastpow(a,b/2,mod);
	ll ans=(fele*fele)%mod;
	if(b&1) ans=(ans*a)%mod;
	return ans;
}

struct rolling_hash { 
	vector<ll> lst;
	vector<ll> hatv;
	
	ll p;
	ll mod; 

	rolling_hash(string& t, ll p_, ll mod_) {
		lst.resize(sz(t));
		hatv.resize(sz(t));
		
		p=p_;
		mod=mod_;
		
		ll curr=p;
		
		lst[0]=t[0]%mod;
		hatv[0]=1;
		for(int i=1;i<sz(t);++i) {
			lst[i]=(lst[i-1]+curr*t[i])%mod;
			hatv[i]=curr;
			curr=(curr*p)%mod;
		}
	}
	
	ll base_hash(ll l, ll r) { //mod should be prime for this
		ll hsh=(lst[r]-(l>0?lst[l-1]:0)+mod);
		return (hsh*fastpow(hatv[l], mod-2, mod))%mod;
	}
	
	bool probably_equal(ll l1, ll r1, ll l2, ll r2) {				
		if(r1-l1!=r2-l2) return false;

		if(l1>l2) {
			swap(l1, l2);
			swap(r1, r2);
		}
				
		ll egyik=(lst[r2]-(l2>0?lst[l2-1]:0)+mod), masik=(lst[r1]-(l1>0?lst[l1-1]:0)+mod);
		return (egyik-(masik*hatv[l2-l1]))%mod==0; //WATCH OUT FOR THIS KIND OF ERROR!!
	}
};

int main() {
	IO;
	string a,b;
	cin>>a>>b;
	int e=0, n=0;
	for(auto i:a) if(i=='0') n++; else e++;
	

	rolling_hash r1(b, 53, 1e9+7);
	
	vector<int> z=zalgo(b);
	int res=0;
	for(int i=1;i<=1000000;++i) {
		if((int)b.size()<=i*n) break ;
		if(((int)b.size()-i*n)%e==0) {
			int j=((int)b.size()-i*n)/e;
			
			bool ok=true;
			int ind=(a[0]=='1'?j:i);
			int ref=-1;
			for(int k=1;k<(int)a.size()&&ok;++k) {
				if(a[k]!=a[0]) {
					if(ref==-1) ref=ind;
					else {
						ok&=r1.probably_equal(ref, ref+(a[k]=='1'?j:i)-1, ind, ind+(a[k]=='1'?j:i)-1);
					}
				}else {
					ok&=z[ind]>=(a[0]=='1'?j:i);
				}
				ind+=(a[k]=='1'?j:i);
			}
			
			if(i==j) {
				bool van=false;
				for(int k=0;k<i&&!van;++k) {
					van|=b[k]!=b[ref+k];
				}
				
				ok&=van;
			}
			
			res+=ok;
			
		}
	}
	
	cout<<res<<"\n";
	return 0;
}
