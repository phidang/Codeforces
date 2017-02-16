#include <bits/stdc++.h>

using namespace std;

int a[100010], n;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a, a+n);
	for (int i=0; i<n-2; i++) {
		if (a[i]+a[i+1]>a[i+2]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}