/*
 * Calculate bitwise end of the trams in stations.    
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
	int n;
	cin>>n;
	vector<bool> t(101, true);
	for(int i=0;i<n;++i) {
		int cnt;
		cin>>cnt;
		vector<bool> t2(101, false);
		for(int j=0;j<cnt;++j) {
			int curr;
			cin>>curr;
			t2[curr]=true;
		}
		
		for(int j=0;j<101;++j) t[j]=t[j]&t2[j];
	}
	
	for(int j=0;j<101;++j) {
		if(t[j]) cout<<j<<" ";
	}cout<<"\n";
	
	return 0;
}
