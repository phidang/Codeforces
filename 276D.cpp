#include <bits/stdc++.h>

using namespace std;

long long l, r;

int main() {
	freopen("input.txt","r",stdin);
	cin>>l>>r;
	if (l==r) {
		cout<<0<<endl;
		return 0;
	}
	long long x=1;
	while (x<=r) {
		x*=2;
	}
	x/=2;
	long long y=x;
	while (y>0 && x<=l || x>r) {
		if (x<=l) 
			x+=y;
		else x-=y;
		y/=2;
	}
	cout<<(x^(x-1))<<endl;
	return 0;
}