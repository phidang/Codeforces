#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
#define debug 01

string s;

bool check(string st) {
	for (int i=0; i<st.length(); i++) {
		if (st[i]==' ') continue;
		else if (st[i]=='#') return true;
		else return false;
	}
	return false;
}

string removeSpace(string st) {
	string res = "";
	for (int i=0; i<st.length(); i++) {
		if (st[i]!=' ') {
			res+=st[i];
		}
	}
	return res;
}

void solve() {
	string st = "";
	bool hasst = false;
	while (getline(cin,s)) {
		if (check(s)) {
			if (hasst)
				cout<<removeSpace(st)<<endl;
			cout<<s<<endl;
			st="";
			hasst = false;
		}
		else {
			st+=s;
			hasst = true;
		}
	}
	if (hasst) {
		cout<<removeSpace(st)<<endl;
	}
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}