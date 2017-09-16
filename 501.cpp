#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[100010];
vector<pair<int, int> > res;
queue<pair<int, int> > qu;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		int x, y;
		cin>>x>>y;
		a[i].first = x;
		a[i].second = y;
		if (x==1) {
			qu.push(make_pair(i, y));
		}
	}
	while (!qu.empty()) {
		pair<int, int> u = qu.front();
		qu.pop();
		if (a[u.second].first == 0) {
			continue;
		}
		res.push_back(make_pair(u.first, u.second));
		a[u.first].first --;
		a[u.second].second ^= u.first;
		a[u.second].first--;
		if (a[u.second].first == 1) {
			qu.push(make_pair(u.second, a[u.second].second));
		}
	}
	cout<<res.size()<<endl;
	for (int i=0; i<res.size(); i++) {
		cout<<res[i].first<<' '<<res[i].second<<endl;
	}
	return 0;
}