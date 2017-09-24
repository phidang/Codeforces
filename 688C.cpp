#include <bits/stdc++.h>

using namespace std;

vector<int> a[100010], g[3];
int visited[100010];
bool res;
int n, m;

void dfs(int x, int idx) {
	if (!res) return;
	visited[x]=idx;
	g[idx].push_back(x);
	int newIdx = (idx%2)+1;
	for (int i=0; i<a[x].size(); i++) {
		if (visited[a[x][i]]==0) {
			dfs(a[x][i], newIdx);
		}
		else {
			if (visited[a[x][i]]!=newIdx) {
				res=false;
				return;
			}
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, 0, sizeof visited);
	res=true;
	for (int i=1; i<=n; i++) {
		if (!visited[i] && a[i].size()>0) {
			dfs(i, 1);
		}
	}
	if (!res) {
		puts("-1");
		return 0;
	}
	for (int i=1; i<3; i++) {
		cout<<g[i].size()<<endl;
		for (int j=0; j<g[i].size(); j++) {
			cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}