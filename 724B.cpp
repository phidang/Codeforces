#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int MAX_N = 30;

int n, m, a[MAX_N][MAX_N], num[MAX_N], b[MAX_N][MAX_N];

void input() {
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
}

void swapMatrix(int x, int y) {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			b[i][j]=a[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		swap(b[i][x], b[i][y]);
	}
}

bool check() {
	for (int i=1; i<=n; i++) {
		int cnt=0;
		for (int j=1; j<=m; j++) {
			if (b[i][j]!=j){
				cnt++;
			}
		}
		if (cnt>2) {
			return false;
		}
	}
	return true;
}

void solve() {
	input();
	swapMatrix(1,1);
	if (check()) {
		puts("YES");
		return;
	}
	for (int i=1; i<m; i++) {
		for (int j=i+1; j<=m; j++) {
			swapMatrix(i, j);
			if (check()) {
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}