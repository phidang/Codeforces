#include <bits/stdc++.h>

using namespace std;

int n, a[110];

void solve() {
	cin>>n;
	bool check=false;
	int sum = 0;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		if (a[i]!=0) check=true;
		sum += a[i];
	}
	if (!check){
		puts("NO");
		return;
	}
	int i = 0;
	while (sum==0) {
		sum-=a[i];
		i++;
	}
	puts("YES"); 
	if (i==0) {
		cout<<1<<endl;
		cout<<1<<' '<<n<<endl;
	}
	else {
		cout<<2<<endl;
		cout<<1<<' '<<i<<endl;
		cout<<i+1<<' '<<n<<endl;
	}

}

int main() {
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}