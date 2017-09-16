#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[26];
string s;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	cin>>s;
	for (int i=0; i<n; i++) {
		cnt[s[i]-'a']++;
	}
	for (int i=0; i<26; i++) {
		if (cnt[i]>m) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}