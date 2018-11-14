#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dist[50001];

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

int a[50001];
main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n=getint<int>();
	
	for(int i=0;i<n;i++) {
		a[i]=getint<int>();
	}
	
	fill(dist, dist+50001, 2*int(1e9));
	
	dist[0]=0;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,0});
	
	while(!pq.empty()){
		int tpfirst=pq.top().first;
		int tpsecond=pq.top().second;
		pq.pop();
		
		if(dist[tpsecond]<tpfirst) continue ;
				
		for(int i=0;i<n;++i) {
			int nxt=(tpsecond+a[i])%a[0];
			int val=tpfirst+a[i];
			
			if(val<=1000000000 && dist[nxt]>val) {
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
