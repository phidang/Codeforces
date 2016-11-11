#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

const int MAX_N = 1e5;
const ll oo = 1e16+7;

int n, c[MAX_N];
ll dp[2][MAX_N];
string s[MAX_N], revS[MAX_N];

void input() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>c[i];
	}
	for (int i=0; i<n; i++) {
		cin>>s[i];
	}
}

void init() {
	for (int i=0; i<n; i++) {
		revS[i]="";
		for (int j=s[i].length()-1; j>=0; j--) {
			revS[i]+=s[i][j];
		}
	}
	dp[0][0]=0;
	dp[1][0]=c[0];
}

void solve() {
	init();
	for (int i=1; i<n; i++) {
		dp[0][i]=dp[1][i]=oo;
		if (s[i]>=s[i-1]) {
			dp[0][i]=dp[0][i-1];
		}
		if (s[i]>=revS[i-1]) {
			dp[0][i]=min(dp[0][i], dp[1][i-1]);
		}
		if (revS[i]>=s[i-1]) {
			dp[1][i]=dp[0][i-1]+c[i];
		}
		if (revS[i]>=revS[i-1]) {
			dp[1][i]=min(dp[1][i], dp[1][i-1]+c[i]);
		}
	}
	ll res = min(dp[0][n-1],dp[1][n-1]);
	if (res==oo) puts("-1");
	else cout<<res<<endl;
}

int main(){ 
	if (debug) openfile;
	input();
	solve();
	return 0;
}