#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, res, numA, numB, num;
vector<int> a[3];

void solve() {
	res = num = 0;
	cin>>n;
	for (int i=0; i<n; i++) {
		string s;
		int x;
		cin>>s>>x;
		if (s=="11") {
			res+=x;
			num++;
		}
		else if (s=="10") a[0].push_back(x);
		else if (s=="01") a[1].push_back(x);
		else a[2].push_back(x);
	}
	for (int i=0; i<3; i++) {
		sort(a[i].begin(), a[i].end());
	}
	int l=a[0].size()-1;
	int k=a[1].size()-1;
	while (l>=0 && k>=0) {
		res+=a[0][l] + a[1][k];
		l--, k--;
	}
	int i=a[2].size()-1;
	while (num>0) {
		if (i>=0) {
			if (l>=0) {
				if (a[0][l]>a[2][i]) {
					res+=a[0][l];
					l--;
				}
				else {
					res+=a[2][i];
					i--;
				}
			}
			else if (k>=0) {
				if (a[1][k]>a[2][i]) {
					res+=a[1][k];
					k--;
				}
				else {
					res+=a[2][i];
					i--;
				}
			}
			else {
				res+=a[2][i];
				i--;
			}
		}
		else if (l>=0) {
			res+=a[0][l];
			l--;
		}
		else if (k>=0) {
			res+=a[1][k];
			k--;
		}
		else break;
		num--;
	}
	cout<<res<<endl;
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}