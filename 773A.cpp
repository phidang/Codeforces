#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const char vowels[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};

string s;

int main() {
	if (debug) openfile;
	cin>>s;
	int idx = -1, minAbi = 0;
	for (int i=0; i<(int)s.length(); i++) {
		for (int j=0; j<6; j++) {
			if (s[i]==vowels[j]) {
				minAbi = max(minAbi, i-idx);
				idx = i;
				break;
			}
		}
	}
	minAbi = max(minAbi, (int)s.length() - idx);
	cout<<minAbi<<endl;
	return 0;
}
