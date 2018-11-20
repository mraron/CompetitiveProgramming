/* *
 * We could solve this problem with suffix array much faster with lcp array (or with hashing in the same complexity), but this approach is very interesting with Z array.
 * We're iterating over the suffixes from the smallest to largest and calculate Z array for every suffix. At every step we add (length of current suffix)-(maximum element in z array) to the answer, this will be correct since we've counted previously exactly (maximum element in z array) before.
 * */
#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

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

int main() {
	int T;
	cin>>T;
	while(T--) {
		string t;
		cin>>t;
		int ans=1;
		for(int i=t.size()-2;i>=0;i--) {
			string sstr=t.substr(i, t.size());
			vector<int> zar=zalgo(sstr);
			int mx=*max_element(zar.begin(), zar.end());
			ans+=zar.size()-mx;
		}
		cout<<ans<<"\n";
	}
}
