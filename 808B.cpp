#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, a[200010];
double res;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	ll sum = 0;
	for (int i=0; i<k; i++) {
		sum += a[i];
	}
	res = sum;
	for (int i=k; i<n; i++) {
		sum = sum+a[i]-a[i-k];
		res += sum;
	}
	res = (double)res/(n-k+1);
	printf("%.6f", res);
	return 0;
}