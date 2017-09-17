#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	int k;
	cin>>k;
	int last = 0;
	for (int i=0; i<k; i++) {
		int r;
		cin>>r;
		last=max(last, r);
	}
	cout<<max(0, last-25)<<endl;
	return 0;
}