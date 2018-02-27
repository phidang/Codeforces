#include <bits/stdc++.h>

using namespace std;


int n, root[26];
string s1,s2;

void input() {
	cin>>n>>s1>>s2;
}

void prepare() {
	for (int i=0; i<26; i++) {
		root[i]=i;
	}
}

int getRoot(int x) {
	while (x!=root[x]) {
		x = root[x];
	}
	return x;
}

void solve() {
	prepare();
	for (int i=0; i<n; i++) {
		int u = s1[i]-'a';
		int v = s2[i]-'a';
		int r1 = getRoot(u);
		int r2 = getRoot(v);
		if (r1!=r2) {
			root[r1] = r2;
		}
	}
}

void output() {
	int cnt=0;
	for (int i=0; i<26; i++) {
		if (root[i]!=i) {
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for (int i=0; i<26; i++) {
		if (root[i]!=i) {
			cout<<char(i+'a')<<' '<<char(root[i]+'a')<<endl;
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);
	input();
	solve();
	output();	
	return 0;
}