/* *
 * Coordinate compression + Fenwick: Let's denote L[i]=f(1,i,a_i) and R[i]=f(i,n,a_i) we want to find the number of such pairs that L[i]>R[j] and i<j we sweep from right to left and at every step we get the sum in fenwick from 1 to L[i]-1 and then increase idx R[i] by 1.
 * */
#include<bits/stdc++.h>
using namespace std;

#define xx first
#define yy second

const int MAXN=1e6+1;

int cnt[MAXN], cnt2[MAXN], t[MAXN], L[MAXN];
pair<int,int> s[MAXN];
int ind=0;
struct fenwick {
	int arr[MAXN];
	
	fenwick() {memset(arr,0,sizeof arr);}
	
	void incr(int x, int by) {
		for(;x<MAXN;x+=(x&(-x))) {
			arr[x]+=by;
		}
	} 
	
	int sum(int x) {
		int sum=0;
		for(;x>0;x-=(x&(-x))) {
			sum+=arr[x];
		}
		
		return sum;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;++i) {
		scanf("%d", &t[i]);
		s[ind++]={t[i], i};
	}
	
	sort(s, s+n);
	
	int x=1;
	t[s[0].yy]=x;
	for(int i=1;i<n;++i) {
		if(s[i].xx!=s[i-1].xx) {
			x++;
		}
		
		t[s[i].yy]=x;
	}
	
	for(int i=0;i<n;i++) {
		cnt2[t[i]]++;
		L[i]=cnt2[t[i]];	
	}
	
	fenwick fw;
	long long ans=0;
	for(int i=n-1;i>=0;i--) {
		cnt[t[i]]++;
		ans+=fw.sum(L[i]-1);
		fw.incr(cnt[t[i]], 1);
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
