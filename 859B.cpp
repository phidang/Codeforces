#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	int x=1;
	while (x*x<n) {
		x++;
	}
	if (n-(x-1)*(x-1)<x) {
		cout<<2*x+2*(x-1)<<endl;
	}
	else {
		cout<<4*x<<endl;
	}
	return 0;
}