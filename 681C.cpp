#include <bits/stdc++.h>

using namespace std;

int n;
multiset<int> mSet;
vector<pair<string, int> > res;

void performInsertion(int num) {
	res.push_back(make_pair("insert", num));
	mSet.insert(num);
}

void performRemoving() {
	if (mSet.empty()) {
		res.push_back(make_pair("insert", 1));
	}
	else {
		mSet.erase(mSet.begin());
	}
	res.push_back(make_pair("removeMin", 0));
	
} 

void performGetmin(int num) {
	multiset<int>::iterator it = mSet.begin();
	while (!mSet.empty() && *it < num) {
		res.push_back(make_pair("removeMin", 0));
		mSet.erase(it);
		it = mSet.begin();
	}
	if (mSet.empty() || *it>num) {
		res.push_back(make_pair("insert", num));
		mSet.insert(num);
	}
	res.push_back(make_pair("getMin", num));
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		string s;
		int num;
		cin>>s;
		if (s=="insert") {
			scanf("%d", &num);
			performInsertion(num);
		}
		else if (s=="removeMin") {
			performRemoving();
		}
		else {
			scanf("%d", &num);			
			performGetmin(num);
		}
	}
	cout<<res.size()<<endl;
	for (int i=0; i<res.size(); i++) {
		if (res[i].first == "removeMin") {
			puts("removeMin");
		}
		else
			printf("%s %d\n", res[i].first.c_str(), res[i].second);
			// cout<<res[i].first<<' '<<res[i].second<<endl;
	}
	return 0;
}