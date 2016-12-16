#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01
#define fs first
#define sc second

typedef pair<int, int> ii;

const int direction[4][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
const int MAX_N = 50+7;


vector<ii> qu;
vector< pair<int, ii> > res;
int n, m, k, f, r;
char a[MAX_N][MAX_N];
bool check[MAX_N][MAX_N];

void input() {
	cin>>n>>m>>k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin>>a[i][j];
		}
	}
}

void init() {
	for (int i=0; i<n; i++) {
		memset(check, false, sizeof check);
	}
}

bool insert(int x, int y) {
	if (x<0 || y<0 || x==n || y==m) {
		return false;
	}
	if (check[x][y]==false && a[x][y]=='.') {
		check[x][y]=true;
		qu.push_back(make_pair(x,y));
		r++;
	}
	return true;
}

void bfs(int x, int y) {
	qu.clear();
	f = r = 0;
	qu.push_back(make_pair(x,y));
	int sum = 1;
	check[x][y]=true;
	bool valid = true;
	while (f<=r) {
		ii u = qu[f];
		for (int i=0; i<4; i++) {
			if (insert(u.fs+direction[i][0], u.sc+direction[i][1])==false) {
				valid = false;
			}
		}
		f++;
	}
	if (valid) {
		res.push_back(make_pair(qu.size(), make_pair(x, y)));
	}
}

void fillIn(int x, int y) {
	if (a[x][y] == '.') {
		a[x][y] = '*';
		qu.push_back(make_pair(x,y));
		r++;
	}
}

void fill(int x, int y) {
	qu.clear();
	f = r = 0;
	qu.push_back(make_pair(x,y));
	a[x][y]='*';
	while (f<=r) {
		ii u = qu[f];
		for (int i=0; i<4; i++) {
			fillIn(u.fs+direction[i][0], u.sc+direction[i][1]);
		}
		f++;
	}
}

void output(int result) {
	cout<<result<<endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout<<a[i][j];
		}
		cout<<endl;
	}
}

void solve() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (check[i][j]==false && a[i][j]=='.') {
				bfs(i,j);
			}
		}
	}
	sort(res.begin(), res.end());
	int sum = 0;
	for (int i=0; i<res.size()-k; i++) {
		sum+=res[i].fs;
		fill(res[i].sc.fs, res[i].sc.sc);
	}
	output(sum);
}

int main() {
	if (debug) openfile;
	input();
	init();
	solve();
	return 0;
}