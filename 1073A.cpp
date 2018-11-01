#include <bits/stdc++.h>

using namespace std;

#define debug 01
#define openfile {freopen("input.txt","r",stdin);}

string s;
int n, cnt[26];

bool isValid(int len) {
	for (int i=0; i<26; i++) {
		if (cnt[i]>(len/2)) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin>>n;
	cin>>s;
	for (int i=0; i<n; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j=i; j<n; j++) {
			cnt[s[j]-'a']++;
			if (isValid(j-i+1)) {
				puts("YES");
				for (int k=i; k<=j; k++) {
					cout<<s[k];
				}
				return;
			}
		}
	}
	puts("NO");
	return;
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}