#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[50001];

#define gc getchar_unlocked

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

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n=getint<int>();
	
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		a[i]=getint<int>();
	}
	
	fill(dist, dist+50001, 1LL<<50);
	
	dist[0]=0;

	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,0});
	
	while(!pq.empty()){
		pair<ll,int> tp=pq.top();
		pq.pop();
		
		if(dist[tp.second]<tp.first) continue ;
				
		for(int i=n-1;i>=0;--i) {
			int nxt=(tp.second+a[i])%a[0];
			int val=tp.first+a[i];
			
			if(dist[nxt]>val) {
				dist[nxt]=val;
				pq.push({val, nxt});
			}
		}
	}
	
	int m=getint<int>();	
	for(int i=0;i<m;++i) {
		int b=getint<int>();
		if(b>=dist[b%a[0]]) {
			puts("TAK");
		}else puts("NIE");
	}
	
	return 0;	
}
