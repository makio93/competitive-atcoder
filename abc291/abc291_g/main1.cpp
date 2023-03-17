// 解説AC

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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	b.insert(b.end(), all(b));
	reverse(all(b));
	vector<vector<ll>> alst(5, vector<ll>(n)), blst(5, vector<ll>(n*2));
	rep(i, 5) rep(j, n) alst[i][j] = ((~a[j] >> i) & 1);
	rep(i, 5) rep(j, n*2) blst[i][j] = ((~b[j] >> i) & 1);
	vector<ll> clst(n), ctmp;
	rep(i, 5) {
		ctmp = convolution_ll(alst[i], blst[i]);
		rep(j, n) clst[j] += (n - ctmp[n-1+j]) << i;
	}
	cout << (*max_element(all(clst))) << endl;
	return 0;
}
