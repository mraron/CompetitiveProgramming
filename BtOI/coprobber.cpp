#include "coprobber.h"
#include <bits/stdc++.h>
using namespace std;

const int COP=0, ROB=1;

int deg[501][501][2];
int ans[501][501];

int start(int N, bool A[MAX_N][MAX_N]) {
	for(int c=0;c<N;++c) {
		for(int r=0;r<N;++r) {
			deg[c][r][COP]=1;
			deg[c][r][ROB]=count(A[r], A[r]+N, true);
		}
	}
	
	queue<array<int, 3>> q;
	for(int i=0;i<N;++i) {
		deg[i][i][COP]=deg[i][i][ROB]=0;
		q.push({i,i,0});
		q.push({i,i,1});
	}
	
	int cnt=0;
	while(!q.empty()) {
		auto fr=q.front();
		q.pop();
		cnt++;
		
		if(fr[2]==COP) {
			for(int i=0;i<N;++i) {
				if(A[i][fr[1]] && deg[fr[0]][i][ROB]) {
					deg[fr[0]][i][ROB]--;
					if(deg[fr[0]][i][ROB]==0) {
						q.push({fr[0], i, ROB});
					}
				}
			}
		}else {
			for(int i=0;i<N;++i) {
				if((fr[0]==i||A[i][fr[0]]) && deg[i][fr[1]][COP]) {
					deg[i][fr[1]][COP]--;
					if(deg[i][fr[1]][COP]==0) {
						ans[i][fr[1]]=fr[0];
						q.push({i, fr[1], COP});
					}
				}
			}
		}
	}

    return (cnt==2*N*N?0:-1);
}

int akt=0;
int nextMove(int R)
{
    return akt=ans[akt][R];
}
