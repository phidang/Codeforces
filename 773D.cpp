#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01
#define mp make_pair

const int MAX_N = 1e5;

int n, cnt, a[MAX_N][3];

map<pair<int,int>,int> mmap;
int mmax[2][3*MAX_N], mpos[2][3*MAX_N];

void exec(int idx, int x, int y, int z) {
    pair<int, int> p = mp(a[idx][x],a[idx][y]);
    if (mmap.find(p) == mmap.end()) {
        mmap[p] = cnt;
        mmax[0][cnt] = mmax[1][cnt] = -1;
        mpos[0][cnt] = mpos[1][cnt] = -1;
        cnt++;
    }
    int e = mmap[p];
    if (mmax[0][e] < a[idx][z]) {
        mmax[1][e] = mmax[0][e];
        mpos[1][e] = mpos[0][e];
        mmax[0][e] = a[idx][z];
        mpos[0][e] = idx;
    }
    else if (mmax[1][e] < a[idx][z] && mpos[0][e] != idx) {
        mmax[1][e] = a[idx][z];
        mpos[1][e] = idx;
    }
}

void findMax() {
    int num = 0;
    int res = 0;
    int pos[2] = {-1, -1};
    for (map<pair<int,int>,int>::iterator it=mmap.begin(); it!=mmap.end(); it++) {
        int p = it->second;
        // cout<<p<<endl;
        int x = mpos[0][p], y = mpos[1][p];
        if (y==-1) {
            int u = min(a[x][0], min(a[x][1], a[x][2]));
            if (u > res) {
                res = u;
                pos[0] = x;
                num = 1;
            }
        }
        else {
            pair<int, int> val = it->first;
            int u = min(val.first, min(val.second, mmax[0][p]+mmax[1][p]));
            if (u > res) {
                res = u;
                pos[0] = x, pos[1] = y;
                num = 2;
            }
        }
    }
    cout<<num<<endl;
    for (int i=0; i<num; i++) {
        cout<<pos[i]+1<<' ';
    }
}

void solve() {
    cnt=0;
    for (int i=0; i<n; i++) {
        sort(a[i],a[i]+3);
        exec(i, 0, 1, 2);
        exec(i, 0, 2, 1);
        exec(i, 1, 2, 0);
    }
    findMax();
}

int main() {
    if (debug) openfile;
    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin>>a[i][j];
        }
    }
    solve();
    return 0;
}
