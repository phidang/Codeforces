#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, a[1010];

void input() {
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
}

bool isOnLine(int a, int b, int x1, int y1, int x2, int y2) {
	int d1=abs(x1-x2);
	int d2=abs(y1-y2);
	int d3=abs(a-x1);
	int d4=abs(b-y1);
	return (d3%d1==0 && d4%d2==0);
}

void solve() {
	for (int i=2; i<=n; i++) {
		vector<pair<int,int> > secondSet;
		for (int j=2; j<=n; j++) {
			if (j!=i && !isOnLine(j, a[j], i, a[i], 1, a[1])) {
				secondSet.push_back(make_pair(j, a[j]));
			}
		}
		if (secondSet.size()==1) {
			puts("Yes");
			return;
		}
		else if (secondSet.size()==0) {
			continue;
		}
		cout<<secondSet.size()<<endl;
		cout<<i<<endl;
		bool found = true;
		for (int j=2; j<secondSet.size(); j++) {
			if (!isOnLine(secondSet[j].first, secondSet[j].second, secondSet[1].first, secondSet[1].second, secondSet[0].first, secondSet[1].second)) {
				found = false;
				break;
			}
		}
		if (found) {
			puts("Yes");
			return;
		}
	}
	puts("No");
}

int main() {
	if (debug) openfile;
	input();
	solve();
	return 0;
}