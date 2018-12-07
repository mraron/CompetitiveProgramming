/* *
 * If n<=7500 use costum bitset
 * I really liked to implement bitset.
 * else use a contribution counting approach, for x=3 we will calculate array hany3[2][2][2][100][100][100] which denotes how many rows are there such that the columns take there these values. From this array we can calculate the answer in k^3 time, so overall it's nk^3.
 * */
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ull mod=998244353;
const ull magic=932051910;

ull hany1[2][100];
ull hany2[2][2][100][100];
ull hany3[2][2][2][100][100][100];

ull hatv[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,x;
	cin>>n>>k>>x;
	hatv[0]=1;
	for(int i=1;i<1001;++i) {
		hatv[i]=(hatv[i-1]*2)%mod;
	}
	
	if(n<=7500) {
		int len=(k+63)/64;
		ll t[n][len];
		memset(t, 0, sizeof t);
		vector<ll> magics(len);
		magics[0]=1;
		for(int i=1;i<len;++i) magics[i]=(magics[i-1]*magic)%mod;
		for(int i=0;i<n;++i) {
			string akt; akt.reserve(len*64);
			cin>>akt;
			
			while(akt.size()%64!=0) {
				akt.push_back('0');
			}
			
			for(int k=0;k+63<len*64;k+=64) {
				for(int j=k, ind=0;j<k+64;j++, ind++) {
					if(akt[j]=='1') {
						t[i][k/64]|=1LL<<ind;
					}
				}
			}
		}
		
		ull ans=0;
		if(x==1) {
			for(int i=0;i<n;++i) {
				for(int j=i+1;j<n;++j) {
					ull cans=0;
					for(int l=0;l<len;++l) {
						cans=(cans+(t[i][l]^t[j][l])%mod*magics[l])%mod;
					}
					
					ans=(ans+cans)%mod;						
				}
			}
		}else if(x==2) {
			for(int i=0;i<n;++i) {
				for(int j=i+1;j<n;++j) {
					ull cans=0;
					for(int l=0;l<len;++l) {
						cans=(cans+(t[i][l]^t[j][l])%mod*magics[l])%mod;
					}
					
					ans=(ans+cans*cans)%mod;						
				}
			}
		}else {
			for(int i=0;i<n;++i) {
				for(int j=i+1;j<n;++j) {
					ull cans=0;
					for(int l=0;l<len;++l) {
						cans=(cans+(t[i][l]^t[j][l])%mod*magics[l])%mod;
					}
					
					ans=(ans+cans*cans%mod*cans)%mod;						
				}
			}
		}
		
		cout<<ans<<"\n";
	}else { //n>7500 és n*k<=300000 => k<=40
		string t[n];
		for(int i=0;i<n;++i) cin>>t[i];
		
		if(x==1) {
			for(int i=0;i<n;++i) {
				for(int j=0;j<k;++j) {
					hany1[t[i][j]-'0'][j]++;
				}
			}
			
			ull ans=0;
			for(int i=0;i<k;++i) {
				ans=(ans+hany1[0][i]*hany1[1][i]%mod*hatv[i]%mod)%mod;
			}
			
			cout<<ans<<"\n";
		}else if(x==2) {
			for(int i=0;i<n;++i) {
				for(int j=0;j<k;++j) {
					for(int l=0;l<k;++l) {
						hany2[t[i][j]-'0'][t[i][l]-'0'][j][l]++;
					}
				}
			}
			
			ull ans=0;
			
			for(int i=0;i<k;++i) {
				for(int j=0;j<k;++j) {
					ans=(ans+(hany2[0][1][i][j]*hany2[1][0][i][j]*hatv[i+j]%mod))%mod;
					ans=(ans+(hany2[0][0][i][j]*hany2[1][1][i][j]*hatv[i+j]%mod))%mod;
				}
			}
			
			cout<<ans<<"\n";
		}else {
			for(int i=0;i<n;++i) {
				for(int j=0;j<k;++j) {
					for(int l=0;l<k;++l) {
						for(int v=0;v<k;++v) {
							hany3[t[i][j]-'0'][t[i][l]-'0'][t[i][v]-'0'][j][l][v]++;
						}
					}
				}
			}

			ull ans=0;
			
			for(int i=0;i<k;++i) {
				for(int j=0;j<k;++j) {
					for(int l=0;l<k;++l) {
						ans=(ans+(hany3[1][0][0][i][j][l]*hany3[0][1][1][i][j][l]*hatv[i+j+l]%mod))%mod;
						ans=(ans+(hany3[0][0][0][i][j][l]*hany3[1][1][1][i][j][l]*hatv[i+j+l]%mod))%mod;
						ans=(ans+(hany3[1][1][0][i][j][l]*hany3[0][0][1][i][j][l]*hatv[i+j+l]%mod))%mod;
						ans=(ans+(hany3[1][0][1][i][j][l]*hany3[0][1][0][i][j][l]*hatv[i+j+l]%mod))%mod;
					}
				}
			}
			
			cout<<ans<<"\n";
		}
		
	}
	
	return 0;
}
