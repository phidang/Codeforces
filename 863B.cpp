#include <bits/stdc++.h>

using namespace std;

int n, a[110], res;

int calc(int x, int y) {
	int e=-1;
	int sum=0;
	for (int i=0; i<2*n; i++) {
		if (i!=x && i!=y) {
			if (e==-1) e=a[i];
			else {
				sum+=(a[i]-e);
				e=-1;
			}
		}
	}
	return sum;
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<2*n; i++) {
		cin>>a[i];
	}
	sort(a, a+2*n);
	res=a[2*n-1]-a[0];
	for (int i=0; i<2*n-1; i++) {
		for (int j=i+1; j<2*n; j++) {
			res=min(res, calc(i,j));
		}
	}
	cout<<res<<endl;
	return 0;
}