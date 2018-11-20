/* *
 * Bruteforce on the first train and find a lis and lds from every train.
 * */
#include<bits/stdc++.h>
using namespace std;

vector<int> lis(vector<int>& t) {
	vector<int> top;
	vector<int> res;
	for(auto i:t) {
		auto it=lower_bound(top.begin(), top.end(), i);
		res.push_back(it-top.begin()+1);
		if(it==top.end()) top.push_back(i);
		else *it=i;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> t(n);
		for(auto& i:t) cin>>i;
		
		int ans=0;
		reverse(t.begin(), t.end());
		vector<int> li=lis(t), ld;
		for(auto& i:t) i*=-1;
		ld=lis(t);
			
		for(int i=0;i<n;++i) {
			ans=max(ans, li[i]+ld[i]-1);
		}
		
		cout<<ans<<"\n";
		
	}
	return 0;
}
