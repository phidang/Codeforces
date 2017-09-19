#include <bits/stdc++.h>

using namespace std;

struct Visitor{
	int c, p, idx;
};

int n, k, sum;
Visitor a[1010];
pair<int, bool> r[1010];
vector<pair<int, int> > res;

bool cmp(const Visitor &a, const Visitor &b) {
	return a.p>b.p;
}

void solve() {
	sort(a, a+n, cmp);
	res.clear();
	sum=0;
	for (int i=0; i<n; i++) {
		int goodIdx = -1;
		for (int j=0; j<k; j++) {
			if (a[i].c<=r[j].first && r[j].second) {
				if (goodIdx==-1 || r[goodIdx].first>r[j].first) {
					goodIdx=j;
				}
			}
		}
		if (goodIdx!=-1) {
			res.push_back(make_pair(a[i].idx, goodIdx+1));
			r[goodIdx].second = false;
			sum+=a[i].p;
		}
	}
	cout<<res.size()<<' '<<sum<<endl;
	for (int i=0; i<res.size(); i++) {
		cout<<res[i].first<<' '<<res[i].second<<endl;
	}
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i].c>>a[i].p;
		a[i].idx = i+1;
	}
	cin>>k;
	for (int i=0; i<k; i++) {
		cin>>r[i].first;
		r[i].second = true;
	}
	solve();
	return 0;
}