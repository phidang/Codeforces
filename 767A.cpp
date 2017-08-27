#include <bits/stdc++.h>

using namespace std;

int n;
bool a[100010];

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	int p=n;
	for (int i=0; i<n; i++) {
		int x;
		cin>>x;
		a[x]=true;
		while (p>0 && a[p]==true) {
			cout<<p<<' ';
			p--;
		}
		cout<<endl;
	}
	return 0;
}