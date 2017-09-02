#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt", "r", stdin);}
#define debug 01

string a, b;
int n, resMax;

int main() {
	if (debug) openfile;
	cin>>n>>a>>b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i=0, j=0; 
	while (i<n && j<n) {
		if (a[i]<=b[j]) {
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	cout<<n-i<<endl;
	i=0, j=0; 
	resMax=0;
	while (i<n && j<n) {
		if (a[i]<b[j]) {
			i++;
			j++;
			resMax++;
		}
		else {
			j++;
		}
	}
	cout<<resMax<<endl;
	return 0;
}