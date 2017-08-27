#include <bits/stdc++.h>

using namespace std;

set<int> se[3];
int n, m, p[200010], a[200010], b[200010];

void solve() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>p[i];
	}
	for (int i=0; i<n; i++) {
		cin>>a[i];
		se[a[i]-1].insert(p[i]);
	}
	for (int i=0; i<n; i++) {
		cin>>b[i];
		se[b[i]-1].insert(p[i]);
	}
	cin>>m;		
	for (int i=0; i<m; i++) {
		int x;
		cin>>x;
		if (se[x-1].empty()) {
			cout<<-1<<' ';
		}
		else {
			int res = *se[x-1].begin();
			cout<<res<<' ';
			for (int i=0; i<3; i++) {
				if (!se[i].empty()) {
					set<int>::iterator it = se[i].find(res);
					if (it != se[i].end())
						se[i].erase(it);	
				}
			}
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}