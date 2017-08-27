#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, m;
string a[1010], b[1010];

void input() {
	if (debug) openfile;
	cin>>n>>m;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	for (int i=0; i<m; i++) {
		cin>>b[i];
	}
}

void preprocess() {
	sort(a, a+n);
	sort(b, b+m);
}

int countCmString() {
	int i=0, j=0; 
	int cmStr = 0;
	while (i<n && j<m) {
		if (a[i]==b[j]) {
			cmStr++;
			i++;
			j++;
		}
		else if (a[i]<b[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	return cmStr;
}

int main() {
	input();
	preprocess();
	int cmStr = countCmString();
	if (cmStr%2) {
		m--;
	}
	n-=cmStr;
	m-=cmStr;
	if (n>m) {
		puts("YES");
	}
	else puts("NO");
	return 0;
}