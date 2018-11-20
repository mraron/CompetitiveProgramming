/* *
 * Simple LIS and LDS with n^2 dp.
 * One thing: I should watch out to initialize values like lis and lds correctly because if n==1 it'll be wrong.
 * */
#include<bits/stdc++.h>
using namespace std;
int main() {
	int T, cs=1;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> h(n), w(n);
		for(auto& i:h) cin>>i;
		for(auto& i:w) cin>>i;
		
		long long dp0[n], dp1[n];
		dp0[0]=w[0];
		dp1[0]=w[0];
		
		long long lis=dp0[0], lds=dp1[0];
		for(int i=1;i<n;++i) {
			dp0[i]=w[i];
			dp1[i]=w[i];
			for(int j=0;j<i;++j) {
				if(h[j]<h[i]) {
					dp0[i]=max(dp0[i], dp0[j]+w[i]);
				}
				
				if(h[j]>h[i]) {
					dp1[i]=max(dp1[i], dp1[j]+w[i]);
				}
			}
			
			lis=max(dp0[i], lis);
			lds=max(dp1[i], lds);
		}
		
		if(lis>=lds) {
			printf("Case %d. Increasing (%lld). Decreasing (%lld).\n", cs++, lis, lds);
		}else {
			printf("Case %d. Decreasing (%lld). Increasing (%lld).\n", cs++, lds, lis);
		}
	}
	return 0;
}
