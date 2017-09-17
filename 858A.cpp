#include <bits/stdc++.h>

using namespace std;

int n, k;
long long res;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>k;
	res=1;
	int cnt5=0;
	while (n%5==0) {
		n/=5;
		res*=5;
		cnt5++;
	}
	int cnt2=0;
	while (n%2==0) {
		n/=2;
		res*=2;
		cnt2++;
	}
	while (cnt5<k) {
		res*=5;
		cnt5++;
	}
	while (cnt2<k) {
		res*=2;
		cnt2++;
	}
	res*=n;
	cout<<res<<endl;
	return 0;
}