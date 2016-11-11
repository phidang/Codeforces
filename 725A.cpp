#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n;
string s;

int main() {
	if (debug) openfile;
	cin>>n>>s;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (s[i]=='>') break;
		cnt++;
	}
	for (int i=n-1; i>=0; i--) {
		if (s[i]=='<') break;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}