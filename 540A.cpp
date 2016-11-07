#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n;
string a,b;

int main(){
    if (debug) openfile;
    cin>>n;
    cin>>a>>b;
    int res=0;
    for (int i=0; i<n; i++) {
        res += min(min(abs(a[i]-b[i]), 57-a[i]+b[i]-47),57-b[i]+a[i]-47);
    }
    cout<<res<<endl;
    return 0;
}
