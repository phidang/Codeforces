#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Travel{
	int d, f, t, c;
};	

int n, m, k;
ll res;
int come[1000010], leave[1000010], link[100010];
Travel a[100010];

bool cmp(Travel x, Travel y) {
	return x.d<y.d || (x.d==y.d && x.f>y.f);
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	for (int i=0; i<m; i++) {
		cin>>a[i].d>>a[i].f>>a[i].t>>a[i].c;
	}
	sort(a, a+m, cmp);
	ll sumCost = 0;
	int cntLeave = 0;
	for (int i=m-1; i>=0; i--) {
		if (a[i].f==0) {
			if (leave[a[i].t]==0) {
				leave[a[i].t]=i;
				cntLeave++;
				sumCost+=a[i].c;
			}
		 	else if (a[i].c<a[leave[a[i].t]].c) {
				sumCost-=a[leave[a[i].t]].c;
				sumCost+=a[i].c;
		 		link[i]=leave[a[i].t];
				leave[a[i].t]=i;
		 	}
		}
	}
	int cntCome=0;
	int r=0;
	res=-1;
	for (int i=0; i<m; i++) {
		if (a[i].f!=0) {
			if (come[a[i].f]==0) {
				come[a[i].f]=a[i].c;
				sumCost+=a[i].c;
				cntCome++;
			}
			else if (a[i].c<come[a[i].f]) {
				sumCost+=a[i].c;
				sumCost-=come[a[i].f];
				come[a[i].f]=a[i].c;
			}
		}
		while (r<m && a[r].d-a[i].d-1<k) {
			if (a[r].f==0) {
				if (r==leave[a[r].t]) {
					if (link[r]==0) {
						cntLeave--;
						break;
					}
					sumCost-=a[r].c;
					sumCost+=a[link[r]].c;
					leave[a[r].t]=link[r];
				}
			}
			r++;
		}
		if (cntLeave<n) break;
		if (cntCome==n) {
			if (res==-1) res=sumCost;
			res=min(res, sumCost);
		}
	}
	cout<<res<<endl;
	return 0;
}