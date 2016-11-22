#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

ll a;

bool isLucky(ll x) {
    while (x!=0){
        if (abs(x%10)==8) return true;
        x/=10;
    }
    return false;
}

int main() {
    if (debug) openfile;
    cin>>a;
    int b=1;
    while (1){
        a++;
        if (isLucky(a)) {
            cout<<b<<endl;
            return 0;
        }
        b++;
    }
    return 0;
}
