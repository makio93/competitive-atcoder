// 復習,解説,作成途中

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

const ll INF = (ll)(1e18);

int main() {
	int h, w, h1, w1, h2, w2;
	cin >> h >> w >> h1 >> w1 >> h2 >> w2;
	h2 = min(h2, h1);
	w2 = min(w2, w1);
	vector<vector<ll>> a(h, vector<ll>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<vector<ll>> sum(h+1, vector<ll>(w+1));
	rep(i, h) rep(j, w) sum[i+1][j+1] += a[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
	vector<vector<ll>> Taka(h-h1+1, vector<ll>(w-w1+1)), Aoki(h-h2+1, vector<ll>(w-w2+1));
	rep3(i, h1, h+1) rep3(j, w1, w+2) Taka[i-1][j-1] = sum[i][j] - sum[i][j-w1] - sum[i-h1][j] + sum[i-h1][j-w1];
	rep3(i, h2, h+1) rep3(j, w2, w+2) Aoki[i-1][j-1] = sum[i][j] - sum[i][j-w2] - sum[i-h2][j] + sum[i-h2][j-w2];
	vector<vector<ll>> mvals(h-h1+1, vector<ll>(w-w1+1));
	rep(i, h-h1+1) {
		int k = w1 - w2;
		rep(j, w-w1+1) mvals[i][j] = Aoki[i][j];
		for (int j2=0; k>0; ++j2) {
			if (k&1) {
				int len = (1<<j2);
				rep(j, w-w1+1) mvals[i][j] = max(mvals[i][j], Aoki[i][j+len]);
			}
			k /= 2;
		}
	}
	return 0;
}
