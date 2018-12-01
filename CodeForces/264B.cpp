/* *
 * For every prime we have a set, then loop through numbers and do a binsearch in every of its primes divisors' sets.
 * */
#include<bits/stdc++.h>
using namespace std;
int pr[100001];
struct par {
	int first,second;
	bool operator<(const par& masik) const {
		if(first==masik.first) return second>masik.second;
		return first<masik.first;
	}
};
int main() {
	vector<int> prs;
	for(int i=2;i<100001;++i) {
		if(!pr[i]) {
			if(i<3000) {
				for(int j=i*i;j<100001;j+=i) {
					pr[j]=i;
				}
			}
			pr[i]=i;
			prs.push_back(i);
		}
	}
	
	
	int n;
	cin>>n;
	vector<int> t(n);
	for(int i=0;i<n;++i) {
		cin>>t[i];
	}
	
	map<int,int> inv;
	for(int i=0;i<(int)prs.size();++i) {
		inv[prs[i]]=i;
	}
	
	set<par> st[prs.size()];
	int ans=0;
	for(int i=0;i<n;++i) {
		vector<int> pp;
		int ti=t[i];
		while(ti>1) {
			int akt=pr[ti];
			while(ti%akt==0) {
				ti/=akt;
			}
			pp.push_back(akt);
		}
		
		int best=1;
		
		for(auto j:pp) {
			int idx=inv[j];
			if(st[idx].size()==0) continue ;
			auto it=st[idx].lower_bound(par{t[i],(int)1e9});
			if(it==st[idx].begin()) continue ;
			it--;
			best=max(best, it->second+1);
		}
		
		ans=max(best, ans);
		
		for(auto j:pp) {
			int idx=inv[j];
			pair<set<par>::iterator, bool> it2=st[idx].insert({t[i], best});
			auto it=it2.first;
			
			it++;
			
			while(it!=st[idx].end() && it->second<=best) {
				it=st[idx].erase(it);
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
