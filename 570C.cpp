#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, m;
string s;

int main() {
	if (debug) openfile;
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for (int i=1; i<n; i++) {
		if (s[i-1]=='.' && s[i]=='.') cnt++;
	}
	for (int i=0; i<m; i++) {
		int x;
		char c;
		cin>>x>>c;
		x--;
		if (c=='.') {
			if (s[x]!='.') {
				if (x>0 && s[x-1]=='.') cnt++;
				if (x<n-1 && s[x+1]=='.') cnt++;
			}
		}
		else {
			if (s[x]=='.') {
				if (x>0 && s[x-1]=='.')  cnt--;
				if (x<n-1 && s[x+1]=='.') cnt--;
			}
		}
		s[x]=c;
		cout<<cnt<<endl;
	}
	return 0;
}