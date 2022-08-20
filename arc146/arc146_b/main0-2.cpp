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
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll res = 0;
	vector<ll> alst;
	rep(i, n) alst.push_back(a[i]);
	repr(i, 31) {
		vector<ll> sub, nlst;
		for (ll ai : alst) {
			if (!((ai>>i)&1)) sub.push_back(ai);
			else nlst.push_back(ai);
		}
		if ((int)(nlst.size()) >= k) {
			res |= 1LL<<i;
		}
		else {
			sort(sub.rbegin(), sub.rend());
			ll msum = 0;
			int scnt = k - (int)(nlst.size());
			rep(j, scnt) msum += (1LL<<i) - sub[j];
			if (msum <= (ll)m) {
				m -= msum;
				res |= 1LL<<i;
				rep(j, scnt) nlst.push_back(1LL<<i);
			}
			else for (ll si : sub) nlst.push_back(si);
		}
		for (ll& ai : nlst) ai &= (1LL<<i) - 1;
		swap(alst, nlst);
	}
	cout << res << endl;
	return 0;
}
