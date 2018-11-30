/*
The given definition means that we either need to find the largest star graph or a triangle. First we find the vertex with the largest degree. If this largest degree is >=3 or <=1 we're done and we found a suitable star graph. Else try to find a triangle.
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

int n,m;
vector<int> adj[10001];
int main() {
	IO;
	int T;
	cin>>T;
	
	while(T--) {
		cin>>n>>m;
		for(int i=1;i<=n;++i) {
			adj[i].clear();
		}
		
		int mx=0;
		vector<int> ezek;
		vector<pair<int,int>> lst;
		for(int i=0;i<m;++i) {
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			lst.push_back({min(a,b), max(a,b)});
			if(mx<(int)adj[a].size()) {
				mx=adj[a].size();
				ezek={a};
			}else if(mx==(int)adj[a].size()) {
				ezek.push_back(a);
			}
			
			if(mx<(int)adj[b].size()) {
				mx=adj[b].size();
				ezek={b};
			}else if(mx==(int)adj[b].size()) {
				ezek.push_back(b);
			}
		}
		
		if(mx>=3 || mx<=1) {
			cout<<mx<<"\n";
		}else {
			bool van=false;
			for(auto i:ezek) {
				if(van) break ;
				
				auto it=lower_bound(all(lst), make_pair(min(adj[i][0],adj[i][1]), max(adj[i][0],adj[i][1])));
				if(it!=lst.end() && *it==make_pair(min(adj[i][0],adj[i][1]), max(adj[i][0],adj[i][1]))) {
					van=true;
				}
			}
			
			if(van) cout<<"3\n";
			else cout<<mx<<"\n";
		}
		 
	}
	return 0;
}
