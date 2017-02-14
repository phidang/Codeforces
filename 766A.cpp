#include <bits/stdc++.h>

using namespace std;

string a, b;

int main() {
	freopen("input.txt","r",stdin);
	cin>>a>>b;
	if (a.length() > b.length()) {
		cout<<a.length()<<endl;
	}
	else if (a.length() < b.length()) {
		cout<<b.length()<<endl;
	}
	else if (a==b) {
		cout<<-1<<endl;
	}
	else cout<<a.length()<<endl;
	return 0;
}