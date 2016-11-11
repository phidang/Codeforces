#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

ll b, d, s;

int main(){ 
	if (debug) openfile;
	cin>>b>>d>>s;
	ll nb, nd, ns, res;
	nd = max(d, max(b-1, s-1));
	ns = max(s, max(b-1, d-1));
	nb = max(b, max(d-1, s-1));
	res = nb-b + nd-d + ns-s;
	cout<<res<<endl;
	return 0;
}