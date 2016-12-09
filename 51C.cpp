#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int MAX_N = 2e5 + 7;
const double eps = 1e-7;

int n, a[MAX_N];

void input() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
}

bool check(double d) {
	int cnt = 1;
	double x = a[0];
	for (int i=1; i<n; i++) {
		if (a[i]-x>2*d) {
			cnt++;
			x=a[i];
			if (cnt>3) return false;
		}
	}
	return true;
}

bool isCornerCase() {
	if (n==1) {
		cout<<0<<endl;
		for (int i=0; i<3; i++) 
			cout<<a[0]<<' ';
		return true;
	}
	if (n==2) {
		cout<<0<<endl;
		cout<<a[0]<<' ';
		for (int i=0; i<2; i++) 
			cout<<a[1]<<' ';
		return true;
	}
	return false;
}

void solve() {
	if (isCornerCase()) {
		return;
	}
	sort(a, a+n);
	double l=0, r=a[n-1]-a[0], res=0;
	while (l+eps<r) {
		double mid = (l+r)/2;
		if (check(mid)) {
			res = mid;
			r = mid;
		}
		else l=mid;
	}
	printf("%.6f\n", res); 
	int cnt = 1;
	double x = a[0];
	for (int i=1; i<n; i++) {
		if (a[i]-x>2*res) {
			printf("%.6f ", (a[i-1]+x)/2);
			x = a[i];
			cnt++;
		}
	}
	printf("%.6f ", (a[n-1]+x)/2);
	while (cnt<3) {
		printf("%.6f ", (a[n-1]+x)/2);
		cnt++;
	}
}

int main() {
	if (debug) openfile;
	input();
	solve();
	return 0;
}