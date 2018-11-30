/* *
 * Do knapsack for every query.
 * */
 
#include<bits/stdc++.h>
using namespace std;

int dp[201][21][11];

int main() {
	int n,q, cs=1;
	while(cin>>n>>q && (n+q)>0) {
		cout<<"SET "<<(cs++)<<":\n";
		vector<int> t(n);
		for(int i=0;i<n;++i) {
			cin>>t[i];
		}
		
		for(int i=0;i<q;++i) {
			int d,m;
			cin>>d>>m;
			memset(dp, 0, sizeof dp);
			dp[0][0][0]=1;
			for(int i=1;i<=n;++i) {
				for(int j=0;j<d;++j) {
					if(j==0) dp[i][j][0]=1;
					else dp[i][j][0]=0;
					
					for(int k=1;k<=m;++k) {
						dp[i][j][k]=dp[i-1][j][k]+dp[i-1][((j-t[i-1])%d+d)%d][k-1];
					}
				}
			}
			
	
			
			cout<<"QUERY "<<i+1<<": "<<dp[n][0][m]<<"\n";
		}
	}
	
	return 0;
}
