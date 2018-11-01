#include <bits/stdc++.h>

using namespace std;

#define debug 01
#define openfile {freopen("input.txt","r",stdin);}

const long long modulo = 998244353LL;

int n, m;
string a, b;
long long finalSum, coeff, num1_b;

int main() {
	if (debug) openfile;
	cin>>n>>m;
	cin>>a>>b;
	num1_b = 0;
	for (int i=0; i<m; i++) {
		if (b[i]=='1') {
			num1_b++;
		}
	}
	coeff = 1;
	finalSum = 0;
	for (int i=n-1,j=m-1; i>=0 && j>=0; i--,j--) {
		if (a[i]=='1') {
			finalSum = (finalSum + (coeff * num1_b) % modulo) % modulo;
		}
		if (b[j]=='1') {
			num1_b--;
		}
		coeff = (coeff*2) % modulo;
	}
	cout<<finalSum<<endl;
	return 0;
}

