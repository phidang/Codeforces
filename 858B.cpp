#include <bits/stdc++.h>

using namespace std;

int n, m, a[110], b[110], res;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		cin>>a[i]>>b[i];
	}
	res=-1;
	for (int i=1; i<=100; i++) {
		bool isOK=true;
		for (int j=0; j<m; j++) {
			if ((a[j]/i)+(a[j]%i>0)!=b[j]) {
				isOK=false;
				break;
			}
		}
		if (isOK) {
			if (res!=-1 && res!=(n/i)+(n%i>0)) {
				res=-1;
				break;
			}
			res=(n/i)+(n%i>0);
		}
	}
	if (res!=-1) {
		cout<<res<<endl;
	}
	else cout<<res<<endl;
	return 0;
}