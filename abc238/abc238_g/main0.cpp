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

// 終了後,自力解答,WA(RE)

const int AMAX = (int)(1e6) + 5;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<bool> vlst(AMAX+1);
	vector<int> plst;
	rep3(i, 2, AMAX) {
		if (vlst[i]) continue;
		plst.push_back(i);
		for (int j=i; j<=AMAX; j+=i) vlst[j] = true;
	}
	int m = plst.size();
	vector<vector<int>> pcnts(n, vector<int>(m));
	rep(i, n) {
		int aval = a[i];
		for (int j=2; j*j<=aval; ++j) {
			if (aval%j == 0) {
				int id = lower_bound(all(plst), j) - plst.begin();
				while (aval%j == 0) {
					pcnts[i][id]++;
					aval /= j;
				}
			}
		}
		if (aval > 1) pcnts[i][lower_bound(all(plst),aval)-plst.begin()]++;
	}
	vector<vector<ll>> sum(n+1, vector<ll>(m));
	rep(i, n) rep(j, m) sum[i+1][j] += sum[i][j] + pcnts[i][j];
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		bool ok = true;
		rep(j, m) if ((sum[ri][j]-sum[li][j])%3 != 0) ok = false;
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
