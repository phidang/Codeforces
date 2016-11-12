#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

const string mmap = "fedabc";
string s;
ll n;

ll convInt(string st){ 
	ll res = 0;
	for (int i=0; i<st.length()-1; i++) {
		res = res*10 + (st[i]-48);
	}
	return res;
}

int main() {
	if (debug) openfile;
	cin>>s;
	char seat = s[s.length()-1];
	n = convInt(s)-1;
	ll res = (n/4)*16;
	n%=4;
	res+=(n%2==1)+(n%2)*6;
	for (int i=0; i<6; i++) {
		if (seat==mmap[i]) {
			res+=i+1;
			break;
		}
	}
	cout<<res<<endl;
	return 0;
}