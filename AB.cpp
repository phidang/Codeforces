#include <bits/stdc++.h>
#include <string>

using namespace std;

class AB {
	public: 
		string createString(int n, int k) {
			int cnt=0;
			string res="";
			for (int i=0; i<n; i++) {
				if (k>0 && n-i-1-cnt<=k) {
					k-=(n-i-1-cnt);
					cnt++;
					res+='A';
				}
				else {
					res+='B';
				}
			}
			if (k>0) res="";
			return res;
		}
};
