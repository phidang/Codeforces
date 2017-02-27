#include <bits/stdc++.h>

using namespace std;

string s[5];

bool check() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<2; j++) {
			bool c = true;
			for (int k=0; k<3; k++) {
				if (s[i][j+k]!='x') {
					c = false;
					break;
				}
			}
			if (c) return true;
		}
	}
	for (int i=0; i<4; i++) {
		for (int j=0; j<2; j++) {
			bool c = true;
			for (int k=0; k<3; k++) {
				if (s[j+k][i]!='x') {
					c = false;
					break;
				}
			}
			if (c) return true;
		}
	}
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			bool c = true;
			for (int k=0; k<3; k++) {
				if (s[i+k][j+k]!='x') {
					c = false;
					break;
				}
			}
			if (c) return true;
		}
	}
	for (int i=0; i<2; i++) {
		for (int j=2; j<4; j++) {
			bool c = true;
			for (int k=0; k<3; k++) {
				if (s[i+k][j-k]!='x') {
					c = false;
					break;
				}
			}
			if (c) return true;
		}
	}
	return false;
}

void solve() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (s[i][j]=='.') {
				s[i][j]='x';
				if (check()) {
					puts("YES");
					return;
				}
				s[i][j]='.';
			}
		}
	}
	puts("NO");
}

int main() {
	freopen("input.txt","r",stdin);
	for (int i=0; i<4; i++) {
		cin>>s[i];
	}
	solve();
	return 0;
}