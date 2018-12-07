/*
 * Number of leaves in the subtrees
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

vector<int> adj[100001];
vector<int> ans;

int dfs(int x) {
	int res=0;
	if(adj[x].empty()) res++;
	for(auto i:adj[x]) {
		res+=dfs(i);
	}
	ans.push_back(res);
	return res;
}

int main() {
	IO;
	int n;
	cin>>n;
	for(int i=2;i<=n;++i) {
		int x;
		cin>>x;
		adj[x].push_back(i);
	}
	
	dfs(1);
	sort(ans.begin(), ans.end());
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}
