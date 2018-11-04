#include <bits/stdc++.h>

using namespace std;

#define debug 01
#define openfile {freopen("input.txt","r",stdin);}

const int MAXN=1e5+7;

int n, k, a[MAXN];

void solve() {
	cin>>n>>k;
	int sum=0;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	int duration = sum/k;
	if ((duration*k)!=sum) {
		puts("No");
		return;
	}
	int currentSum = 0;
	for (int i=0; i<n; i++) {
		currentSum+=a[i];
		if (currentSum>duration) {
			puts("No");
			return;
		}
		else if (currentSum==duration) {
			currentSum=0;
		}
	}	
	puts("Yes");
	currentSum=0;
	int num=0;
	for (int i=0; i<n; i++) {
		currentSum+=a[i];
		num++;
		if (currentSum==duration) {
			cout<<num<<' ';
			currentSum=0;
			num=0;
		}
	}
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}