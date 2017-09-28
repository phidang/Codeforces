#include <bits/stdc++.h>

using namespace std;

const int oo=1e9+7;

int n, m, k, res, b[100010];
vector<pair<int, int> > a[100010];
bool hasStorage[100010];

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	for (int i=0; i<m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(hasStorage, false, sizeof hasStorage);
	for (int i=0; i<k; i++) {
		cin>>b[i];
		hasStorage[b[i]]=true;
	}
	res=oo;
	for (int i=0; i<k; i++) {
		for (int j=0; j<a[b[i]].size(); j++) {
			if (!hasStorage[a[b[i]][j].first]) {
				res=min(res, a[b[i]][j].second);
			}
		}
	}
	if (res==oo) 
		cout<<-1<<endl;
	else cout<<res<<endl;
	return 0;
}