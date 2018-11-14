/*
ID: noszaly1
TASK: {TASK}
LANG: C++11               
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
	if(n==1) {
		cout<<"1 0\n";
		return 0;
	}
	vector<int> ps;
	int fos=1;
	for(int i=2;i<=1000000 && n>1;++i) {
		int cnt=0;
		while(n%i==0) {
			cnt++;
			n/=i;
		}
		
		if(cnt>0) {
			ps.push_back(cnt);
			fos*=i;
		}
	}
	
	int mx=*max_element(all(ps));
	int i;
	for(i=0;(1<<i)<mx;++i);
	
	bool van_kisebb=false;
	for(auto j:ps) {
		if((1<<i)>j) van_kisebb=true;
	}
	
	cout<<fos<<" "<<(van_kisebb?1+i:i)<<"\n";;
	
	return 0;
}
