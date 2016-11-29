#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int a[3];

int main() {
	if (debug) openfile;
	cin>>a[0]>>a[1]>>a[2];	
	sort(a, a+3);
	cout<<a[2]-a[0]<<endl;
	return 0;
}