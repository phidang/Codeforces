#include <bits/stdc++.h>

using namespace std;

int n, a[200010], l[200010], r[200010], res[200010];
stack<int> st;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) 
		cin>>a[i];
	for (int i=0; i<n; i++) {
		while (!st.empty() && a[st.top()]>=a[i]) 
			st.pop();
		if (st.empty()) 
			l[i]=-1;
		else 
			l[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=n-1; i>=0; i--) {
		while (!st.empty() && a[st.top()]>=a[i]) 
			st.pop();
		if (st.empty()) 
			r[i]=n;
		else 
			r[i]=st.top();
		st.push(i);
	}
	memset(res, 0, sizeof res);
	for (int i=0; i<n; i++) {
		int length = r[i]-l[i]-1;
		res[length] = max(res[length], a[i]);
	}
	for (int i=n; i>0; i--) { 
		res[i]=max(res[i+1], res[i]);
	}
	for (int i=1; i<=n; i++) 
		cout<<res[i]<<' ';
	return 0;
}