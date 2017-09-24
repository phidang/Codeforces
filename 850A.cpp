#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265
#define eps 0.0000001

int n, a[1010][5];
vector<int> res;

double dotProd(int *x, int *y) {
	double res=0;
	for (int i=0; i<5; i++) {
		// cout<<x[i]<<' ';
		res+=x[i]*y[i];
	}
	// cout<<endl;
	return res;
}

double lenVec(int *x) {
	return sqrt(dotProd(x, x));
}

double angle(int *x, int *y) {
	return acos(dotProd(x, y) / (lenVec(x)*lenVec(y))) * 180.0 / PI;
}

int* calcVec(int *pointA, int *pointB) {
	int *vec = new int[5];
	for (int i=0; i<5; i++) {
		vec[i]=pointB[i]-pointA[i];
	}
	return vec;
}

void solve() {
	for (int i=0; i<n; i++) {
		bool isGood = true;
		for (int j=0; j<n-1; j++) {
			if (i==j) continue;
			int *vecIJ = calcVec(a[i], a[j]);
			for (int k=j+1; k<n; k++) {
				if (k==i) continue;
				int *vecIK = calcVec(a[i],a[k]);
				if (angle(vecIJ, vecIK)+eps<90.0) {
					isGood = false;
					break;
				}
			}
			if (!isGood) {
				break;
			}
		}
		if (isGood) {
			res.push_back(i+1);
		}
	}
	cout<<res.size()<<endl;
	for (int i=0; i<res.size(); i++) {
		cout<<res[i]<<endl;
	}
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) {
			cin>>a[i][j];
		}
	}
	solve();
	return 0;
}