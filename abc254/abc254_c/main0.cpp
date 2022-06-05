// 本番AC

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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> alst(k);
	rep(i, n) alst[i%k].push_back(a[i]);
	rep(i, k) sort(all(alst[i]));
	vector<int> ta(n);
	rep(i, k) rep(j, alst[i].size()) ta[i+j*k] = alst[i][j];
	bool ok = true;
	rep(i, n-1) if (ta[i+1] < ta[i]) ok = false;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
