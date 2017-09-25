#include <bits/stdc++.h>

using namespace std;

const string vow="aeiou ";

string s;

bool isVow(char c) {
	for (int i=0; i<vow.length(); i++) {
		if (c==vow[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>s;
	if (s.length()<3) {
		cout<<s<<endl;
		return 0;
	}
	cout<<s[0]<<s[1];
	char x=s[0], y=s[1];
	for (int i=2; i<s.length(); i++) {
		if (!isVow(s[i]) && !isVow(x) && !isVow(y)) {
			if (s[i]!=y || y!=x) {
				cout<<' ';
				x=y;
				y=' ';
			}
		}
		cout<<s[i];
		x=y;
		y=s[i];
	}
	return 0;
}