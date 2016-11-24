#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n;
string s;

void solve() {
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (s[i]=='A') {
			cnt++;
		}
	}
	if (cnt>n-cnt) {
		puts("Anton");
	}
	else if (cnt<n-cnt) {
		puts("Danik");
	}
	else {
		puts("Friendship");
	}
}


int main() {
	if (debug) openfile;
	cin>>n;
	cin>>s;
	solve();
	return 0;
}