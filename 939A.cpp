#include <bits/stdc++.h>

using namespace std;

int n, a[5010];

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for (int i=1; i<=n; i++) {
		if (a[a[a[i]]]==i) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}