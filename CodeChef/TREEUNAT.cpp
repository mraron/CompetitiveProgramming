/*
We can always have a solution with at most 2 difference. We try to make a solution with less. If there're two different markers we can't do better than 1 (so if all of them are same the solution is 0).
So we try to construct a solution with 1 difference. We can use a tree dp solution where we actually have for every vertex the possible number of markers of different colours in it's subtree in a set (if the vertex is 0 color, if the vertex is 1 color, if the vertex is 2 color all separated).
It turns out that it's very fast if we just merge this sets.
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

vector<int> adj[101];

struct ans {
	set<array<int, 3>> res[3];
};

int a[3];

int b[101];
ans calc(int x) {
	b[x]=1;
	
	ans res;
	res.res[0].insert({1,0,0});
	res.res[1].insert({0,1,0});
	res.res[2].insert({0,0,1});
	
	for(auto i:adj[x]) {
		if(b[i]) continue ;
		
		set<array<int,3>> ujres[3];
		
		auto masik=calc(i);
		
		for(auto j:masik.res[0]) {
			for(auto k:res.res[1]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
					ujres[1].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}
			for(auto k:res.res[0]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
					ujres[0].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}	
		}
		
		for(auto j:masik.res[1]) {
			for(auto k:res.res[1]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
					ujres[1].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}
			for(auto k:res.res[0]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
					ujres[0].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}	
			for(auto k:res.res[2]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
					ujres[2].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}
		}
		
		for(auto j:masik.res[2]) {
			for(auto k:res.res[1]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
				ujres[1].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}
			for(auto k:res.res[2]) {
				if(j[0]+k[0]<=a[0] && j[1]+k[1]<=a[1] && j[2]+k[2]<=a[2])
				ujres[2].insert({j[0]+k[0], j[1]+k[1], j[2]+k[2]});
			}	
		}
		
		res.res[0].swap(ujres[0]);
		res.res[1].swap(ujres[1]);
		res.res[2].swap(ujres[2]);
		
	}

	return res;
}

int main() {
	IO;
	
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		a[0]=a[1]=a[2]=0;
		for(int i=0;i<n;++i) {
			int x;
			cin>>x;
			a[x]++;
		}
		
		for(auto& i:adj) i.clear();
		
		for(int i=1;i<n;++i) {
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		memset(b, 0, sizeof b);
		if(a[0]==n || a[1]==n || a[2]==n) {
			cout<<"0\n";
		}else {
			auto res=calc(1);
			
			bool ok=res.res[0].count({a[0], a[1], a[2]})||res.res[1].count({a[0], a[1], a[2]})||res.res[2].count({a[0], a[1], a[2]});
			cout<<(ok?"1":"2")<<"\n";
		}
		
	}
	
	return 0;
}
