#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, dist, height;
	cin >> n >> dist >> height;
	vector<int> d(n), h(n);
	rep(i, n) cin >> d[i] >> h[i];
	int mid = 0; double rval = (double)(height-h[0]) / (dist-d[0]);
	rep3(i, 1, n) {
		if ((double)(height-h[i])/(dist-d[i]) < rval) {
			mid = i;
			rval = (double)(height-h[i]) / (dist-d[i]);
		}
	}
	double hdif = dist * (double)(height-h[mid]) / (dist-d[mid]), res = max(0.0, height-hdif);
	printf("%.6f\n", res);
	return 0;
}
