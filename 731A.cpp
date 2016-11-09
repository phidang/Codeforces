#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt", "r", stdin);}
#define debug 01

string s;
int sum;

int main() {
	if (debug) openfile;
	cin>>s;
	int current = 0;
	sum = 0;
	for (int i=0; i<s.length(); i++) {
		int pos = s[i]-97;
		sum += min((pos-current+26)%26, (26-pos+current)%26);
		current = s[i]-97;
	}
	cout<<sum<<endl;
	return 0;
}