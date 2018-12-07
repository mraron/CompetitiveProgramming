/* *
 * Bruteforce on the count of "a" digits.
 * */

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,b,n;
const ll mod=1e9+7;

ll fastpow(ll a,ll b) {
	if(b==0) return 1;
	ll fele=fastpow(a, b/2);
	ll ans=(fele*fele)%mod;
	if(b&1) ans=(ans*a)%mod;
	
	return ans;
}

int main() {
	ll fact[(int)1e6+1];
	fact[0]=1;
	for(int i=1;i<=(int)1e6;++i) {
		fact[i]=fact[i-1]*i%mod;
	}
	
	cin>>a>>b>>n;
	
	ll ans=0;
		
	for(int i=0;i<=n;++i) {
		ll val=i*a+(n-i)*b; bool ok=true;
		
		while(val>0) {
			ok&=(val%10==a || val%10==b);
			val/=10;
		}
		
		if(ok) {
			ans+=fact[n]*fastpow(fact[i], mod-2)%mod*fastpow(fact[n-i], mod-2)%mod;
			ans%=mod;
		}
	}	
	
	cout<<ans<<"\n";
	return 0;
}
