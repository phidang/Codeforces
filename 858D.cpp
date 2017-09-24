#include <bits/stdc++.h>

using namespace std;

int n;
string res[70010];
map<string, int> mmap;

string takeMin(string a, string b) {
	if (a=="") return b;
	if (a.length()<b.length()) 
		return a;
	return b;
}

int main() {
	freopen("input.txt","r",stdin);
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		string s;
		getline(cin, s);
		for (int j=0; j<9; j++) {
			string st = "";
			for (int k=j; k<9; k++) {
				st+=s[k];
				if (mmap.count(st) && mmap[st]!=i) {
					mmap[st]=-1;
				}
				else {
					mmap[st]=i;
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		res[i]="";
	}
	for (map<string, int>::iterator it=mmap.begin(); it!=mmap.end(); it++) {
		if (it->second!=-1) {
			res[it->second]=takeMin(res[it->second], it->first);
		}
	}
	for (int i=0; i<n; i++) {
		printf("%s\n", (res[i]).c_str());
	}
	
	return 0;
}