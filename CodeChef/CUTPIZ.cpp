/*
First we find the smallest angle between two cuts then, let's denote it by alpha. If we have a cut at angle beta, then we should have a cut at beta+alpha too, we do this until every cut has a cut alpha away.
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
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> t(n);
		for(int i=0;i<n;++i) {
			cin>>t[i];
		}
		
		sort(t.begin(), t.end());
		
		int mi=1<<30;
		
		for(int i=0;i+1<n;++i) {
			mi=min(mi, t[i+1]-t[i]);
		}
		
		mi=min(mi, 360-(t[1]-t[0]));
		
		vector<bool> akt(360);
		for(auto i:t) {
			akt[i]=true;
		}

		mi=min(mi, 360-(t[1]-t[0]));
		
		int ans=0;
		vector<bool> previ;
		do {
			previ=akt;
			for(int i=0;i<360;++i) {
				if(akt[i]) {
					if(!akt[(i+mi)%360]) {
						akt[(i+mi)%360]=true;
						ans++;
					}
				}
			}
		}while(previ!=akt);
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
