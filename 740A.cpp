#include <bits/stdc++.h>

using namespace std; 

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

const ll oo = 1e15;

ll a, b, c, n;

void input() {
	cin>>n>>a>>b>>c;
}

void solve() {
	ll res = oo;
	for (int k=0; k<10; k++) {
		if ((k+n)%4==0) {
			ll x = k*a;
			ll y = (k/2)*b + (k%2)*a;
			ll z = (k/3)*c + ((k%3)/2)*b + ((k%3)%2)*a;
			res = min(res, min(x, min(y, z)));
		}
	}
	cout<<res<<endl;
}

int main() {
	if (debug) openfile;
	input();
	solve();

	return 0;
}