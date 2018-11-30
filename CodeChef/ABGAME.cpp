/*
First notice that it's basically a NIM game plus you have some heaps that are either A's or B's, let's denote |A| and |B| as the number of stones in heaps that are owned by only A and B respectively. If |A| > |B| A can always win, if |A| < |B| B can always win (these are easy to see), otherwise if |A| = |B| it's a standard NIM game.
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
		string t;
		cin>>t;
		vector<int> nim, ua, ub;
		for(int i=0;i<(int)t.size();++i) {
			if(t[i]!='.') {
				int j=i+1;
				while(j<(int)t.size() && t[j]=='.') {
					j++;
				}
				
				if(j==(int)t.size() || t[i]==t[j]) {
					if(t[i]=='A') ua.push_back(j-i-1);
					else ub.push_back(j-i-1);
				}else {
					nim.push_back(j-i-1);
				}
				
				i=j;
			}
		}
		
		int sa=0, sb=0;
		for(auto i:ua) sa+=i;
		for(auto i:ub) sb+=i;
		
		if(sa>sb) {
			cout<<"A\n";
		}else if(sa<sb) {
			cout<<"B\n";
		}else {
			int val=0;
			for(auto i:nim) val^=i;
			cout<<(val==0?"B":"A")<<"\n";
		}
	}
	
	return 0;
}
