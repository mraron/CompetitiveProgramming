/*
 * If you're first, first use all strong picks then from the remaining always choose the largest.
 * If you're the second go with the flow when the first is picking the strong picks or if he's not capitalize on it, since by picking strong pair heroes you don't lose anything in the future (this argument is true in both cases).
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

int main() {
	IO;
	int n,m;
	cin>>n>>m;
	vector<int> p(2*n);
	for(int i=0;i<2*n;++i) cin>>p[i];
	vector<pair<int,int>> str;
	vector<bool> v(2*n);
	vector<int> muszaj(2*n, -1);
	int cnt=2*n;
	for(int i=0;i<m;++i) {
		int a,b;
		cin>>a>>b;
		str.push_back({a-1,b-1});
		//cerr<<a-1<<" "<<b-1<<"\n";
		muszaj[a-1]=b-1;
		muszaj[b-1]=a-1;
	}
	//for(auto i:muszaj) cerr<<i<<" ";
	//cerr<<"\n";
	
	int last=-1;
	
	int t;
	cin>>t;
	if(t==2) {
		cin>>last;
		last--;
		cnt--;
		v[last]=1;
	}
	
	while(cnt>0) {
		if(last!=-1 && muszaj[last]!=-1 && !v[muszaj[last]]) {
			cout<<muszaj[last]+1<<"\n";
			cnt--;
			v[muszaj[last]]=1;
		}else {
			int mx=-1, mxind=-1;
			for(auto i:str) {
				if(!v[i.first] && !v[i.second]) {
					if(mx<max(p[i.xx], p[i.yy])) {
						mx=max(p[i.xx], p[i.yy]);
						mxind=p[i.xx]>p[i.yy]?i.xx:i.yy;
					}
				}
			}
			
			if(mxind==-1) {
				int mx=-1, mxind=-1;
				for(int i=0;i<2*n;++i) {
					if(!v[i]) {
						if(p[i]>mx) {
							mx=p[i];
							mxind=i;
						}
					}
				}
				assert(mxind!=-1);
				cout<<mxind+1<<"\n";
				cnt--;
				v[mxind]=1;
			}else {
				cout<<mxind+1<<"\n";
				cnt--;
				v[mxind]=1;
			}
		}
		cout.flush();
		if(cnt==0) return 0;
		cin>>last;
		last--;
		cnt--;
		v[last]=1;
	}
		
	return 0;
}
