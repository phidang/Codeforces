#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int MAX_N = 1e5;

int n;
int a[MAX_N], b[MAX_N];

int main() {
	if (debug) openfile;
	cin>>n;
	int sumL=0, sumR=0;
	int maxL=0, maxR=0;
	int idxL=0, idxR=0;
	for (int i=0; i<n; i++) {
		cin>>a[i]>>b[i];
		sumL+=a[i];
		sumR+=b[i];
		if (a[i]-b[i]>maxL) {
			idxL=i+1;
			maxL=a[i]-b[i];
		}
		if (b[i]-a[i]>maxR) {
			idxR=i+1;
			maxR=b[i]-a[i];
		}
	}
	if (abs(sumL+2*maxR-sumR) > abs(sumR+2*maxL-sumL)) 
		cout<<idxR<<endl;
	else cout<<idxL<<endl;
	return 0;
}