#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, has[52], cnt;
string s;
bool check[52];

void init() {
	memset(check, false, sizeof(check));
	for (int i=0; i<n; i++) {
		if (s[i]>=97) {
			check[26+s[i]-97]=true;
		}
		else check[s[i]-65]=true;
	}
	cnt = 0;
	for (int i=0; i<52; i++) 
		if (check[i]) 
			cnt++;
}

void solve() {
	memset(has, 0, sizeof(has));
	int l=0, r=0, c=1;
	has[s[0]]=1;
	int res = s.length();
	while (l<=r && r<s.length()) {
		if (c<cnt) {
			r++;
			if (has[s[r]]==0) 
				c++;
			has[s[r]]++;
		}
		else {
			res = min(res, r-l+1);
			if (has[s[l]]==1)
				c--;
			has[s[l]]--;
			l++;
		}
	}
	cout<<res<<endl;
}

int main() {
	if (debug) openfile;
	cin>>n>>s;
	init();
	solve();
	return 0;
}