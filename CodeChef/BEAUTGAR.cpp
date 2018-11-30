/*
First if we have a string with length two it's trivial. Else the string's length is larger or equal than 3. If we have 3 adjecent chars with the same color it's not possible. 
Then we list all the places i such that t[i]=t[i+1]. If we have no such places we're done. If we have only one such place it's impossible. Else we can just simulate the reversing the string (also we could do something with more insight, it'll be only possible if we have 2 such positions and they're not the same character).
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
		if(t.size()==2) {
			if(t[0]!=t[1]) {
				cout<<"yes\n";
			}else {
				cout<<"no\n";
			}
		}else {
			bool ok=true;
			for(int i=0;i<(int)t.size();++i) {
				if(t[i]==t[(i+1)%t.size()] && t[(i+1)%t.size()]==t[(i+2)%t.size()]) {
					ok=false;
				}
			}
			
			if(ok) {
				vector<bool> itt(t.size());
				vector<int> lul;
				for(int i=0;i<t.size();++i) {
					if(t[i]==t[(i+1)%t.size()]) {
						itt[i]=true;
						lul.push_back(i);
					}
				}
				
				if(lul.size()==1) {
					cout<<"no\n";
				}else if(lul.size()==0) {
					cout<<"yes\n";
				}else {
					for(int i=lul[0]+1, j=lul[1];i<j;i++, j--) swap(t[i], t[j]);
					ok=true;
					for(int i=0;i<(int)t.size();++i) {
						if(t[i]==t[(i+1)%t.size()]) {
							ok=false;
						}
					}
					
					cout<<(ok?"yes":"no")<<"\n";


				}
				
			}else {
				cout<<"no\n";
			}
		}
	}
	return 0;
}
