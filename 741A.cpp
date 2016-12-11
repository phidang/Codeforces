#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int MAX_N = 1e2 + 7;

int n, a[MAX_N];
int num[MAX_N];
bool check[MAX_N];

bool hasResult() {
	for (int i=1; i<=n; i++) {
		num[a[i]]++;
	}
	for (int i=1; i<=n; i++) {
		if (num[i]==0) {
			return false;
		}
	}
	return true;
}

int dfs(int x, int y) {
	check[x]=true;
	if (check[a[x]]==false) {
		return dfs(a[x], y+1);
	}
	else return y;
}

int lcm(int a, int b) {
	int mul = a*b;
	while (b>0) {
		a = a%b;
		swap(a, b);
	}
	return mul/a;
}

void solve() {
	if (hasResult()==false) {
		puts("-1");
		return;
	}
	int res = 1;
	for (int i=1; i<=n; i++) {
		if (check[i]==false) {
			int cycleLength = dfs(i, 1);
			if (cycleLength%2 == 0) {
				res = lcm(res, cycleLength/2);
			}
			else res = lcm(res, cycleLength);
		}
	}
	cout<<res<<endl;
}

int main() {
	if (debug) openfile;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	solve();
	return 0;
}