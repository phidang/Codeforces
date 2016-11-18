#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int x, y;

void solve() {
	int edges[3];
	for (int i=0; i<3; i++) edges[i]=y;
	int cnt=0;
	while (edges[0]!=x || edges[1]!=x || edges[2]!=x) {
		sort(edges, edges+3);
		edges[0]=min(edges[1]+edges[2]-1, x);
		cnt++;
	}	
	cout<<cnt<<endl;
}

int main() {
	if (debug) openfile;
	cin>>x>>y;
	solve();
	return 0;
}