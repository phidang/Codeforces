#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

string s;
int cnt[26], q;

bool check(int c) {
	int sum=0, zero=0;
	for (int i=0; i<26; i++) {
		if (cnt[i]>1)
			return false;
		else if (cnt[i]==0) {
			zero++;
		}
	}
	if (c == zero)
		return true;
	return false;
}

void output(int x) {
	memset(cnt, 0, sizeof(cnt));
	for (int i=x; i<x+26; i++) {
		if (s[i]!='?') {
			cnt[s[i]-'A']++;
		}
	}
	for (int i=x; i<x+26; i++) {
		if (s[i]=='?') {
			for (int j=0; j<26; j++) {
				if (cnt[j]==0) {
					s[i]=char(j+'A');
					cnt[j]++;
					break;
				}
			}
		}
	}	
	for (int i=0; i<s.length(); i++) {
		if (s[i]=='?') {
			s[i]='A';
		}
	}
	cout<<s<<endl;
}

void solve() {
	for (int i=0; i<26; i++) {
		if (s[i]=='?')
			q++;
		else cnt[s[i]-'A']++;
	}
	if (check(q)) {
		output(0);
		return;
	}
	for (int i=26; i<s.length(); i++) {
		if (s[i]=='?')
			q++;
		else cnt[s[i]-'A']++;
		if (s[i-26]=='?') 
			q--;
		else cnt[s[i-26]-'A']--;
		if (check(q)) {
			output(i-26+1);
			return;
		}
	}
	puts("-1");
}

int main() {
	if (debug) openfile;
	cin>>s;
	if (s.length()<26) {
		puts("-1");
		return 0;
	}
	solve();
	return 0;
}