#include <bits/stdc++.h>

using namespace std;

const int direction[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool check[400][400], p[400][400][8][40];
int n, a[40], res;

struct PP {
	int x, y, d, step;
	PP(int xx, int yy, int dd, int s) {
		x = xx;
		y = yy;
		d = dd;
		step = s;
	}
};

queue<PP> qu;

void input() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
}

void run(PP u) {
	for (int i=0; i<a[u.step]; i++) {
		int x = u.x + direction[u.d][0]*(i+1);
		int y = u.y + direction[u.d][1]*(i+1);
		int d = (u.d+1)%8;
		if (check[x][y]==false) {
			check[x][y]=true;
			// cout<<x<<' '<<y<<endl;
			res++;
		}
		if (i==a[u.step]-1 && p[x][y][d][u.step]==false) {
			qu.push(PP(x,y,d,u.step+1));
			p[x][y][d][u.step]=true;
		}
		x = u.x + direction[u.d][0]*(i+1);
		y = u.y + direction[u.d][1]*(i+1);
		d = (u.d+7)%8;
		if (check[x][y]==false) {
			check[x][y]=true;
			// cout<<x<<' '<<y<<endl;
			res++;
		} 
		if (i==a[u.step]-1 && p[x][y][d][u.step]==false) {
			qu.push(PP(x,y,d,u.step+1));
			p[x][y][d][u.step]=true;
		}
	}
}

void solve() {
	res = 0;
	qu.push(PP(199, 200, 0, 0));
	while (!qu.empty()) {
		PP u = qu.front();
		qu.pop();
		run(u);
	}
	cout<<res<<endl;
}	

int main() {
	input();
	solve();
	return 0;
}