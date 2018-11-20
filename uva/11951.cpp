/* *
 * Like in maximum maximum 2d sum I iterate on pairs of rows and calculate subrectangle sums this way. We can make a lot of cuts, so it'll be fast.
 * */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int t[101][101];

main() {
	int T, cs=1;
	cin>>T;
	while(T--) {
		int n,m,k;
		cin>>n>>m>>k;
		int ans_sz=1, ans_cost=1<<30;

		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				cin>>t[i][j];
				ans_cost=min(t[i][j], ans_cost);
			}
		}
		
		if(ans_cost>k) {
			cout<<"Case #"<<(cs++)<<": 0 0\n";
			continue ;
		}
		
		for(int i=0;i<n;++i) {
			vector<int> lst(m);
			for(int j=i;j<n;++j) {
				int w=j-i+1;
				for(int k=0;k<m;++k) lst[k]+=t[j][k];
				if(w*m<ans_sz) continue ;
				vector<int> sum(m);
				sum[0]=lst[0];
				for(int k=1;k<m;++k) sum[k]=sum[k-1]+lst[k];
			
				for(int len=max((ans_sz+w-1)/w, 1LL);len<=m;++len) {
					bool van=false;
					for(int start=0;start+len-1<m;++start) {
						int c=sum[start+len-1]-(start>0?sum[start-1]:0);

						if(c<=k && (ans_sz<(len)*w || (ans_sz==(len)*w&&ans_cost>c))) {
							ans_sz=(len)*w;
							ans_cost=c;
						}
						
						if(c<=k) van=true;
					}
					
					if(!van) break;
				}
			}
		}
		
		cout<<"Case #"<<(cs++)<<": "<<ans_sz<<" "<<ans_cost<<"\n";
	}
	return 0;
}
