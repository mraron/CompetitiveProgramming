/*
Just bruteforce using the appropriate ds (array of vectors).
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

vector<int> idx[200001];

int main() {
	IO;
	int n;
	cin>>n;
	vector<int> t(n);
	for(int i=0;i<n;++i) {
		cin>>t[i];
	}
	vector<pair<int,int>> lst;
	lst.push_back({t[0], 1});
	for(int i=1;i<n;++i) {
		if(lst.back().xx==t[i]) lst.back().yy++;
		else lst.push_back({t[i], 1});
	}
	/*for(auto i:lst) {
		cerr<<i.first<<" "<<i.second<<"\n";
	}*/
	
	int ans=0, ansind=0;
	
	for(int i=0;i<sz(lst);++i) {
		idx[lst[i].first].push_back(i);
	}
	
	for(int i=1;i<=200000;++i) {
		if(idx[i].empty()) continue ;
		int cans=lst.size();
		for(auto j:idx[i]) {
			cans--;
			if(j-1>=0 && j+1<sz(lst)) {
				if(lst[j-1].xx==lst[j+1].xx) cans--;
			}
		}
	
		if(cans>=ans) {
			ans=cans;
			ansind=i;
		}
	}
	
	cout<<ans<<" "<<ansind<<"\n";
	
	return 0;
}
