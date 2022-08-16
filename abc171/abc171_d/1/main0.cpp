// 学習1回目,自力AC

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
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll asum = accumulate(all(a), 0LL);
	const int mval = (int)(1e5) + 1;
	vector<int> acnt(mval+1);
	rep(i, n) acnt[a[i]]++;
	cin >> q;
	rep(i, q) {
		int bi, ci;
		cin >> bi >> ci;
		asum += (ll)(ci-bi) * acnt[bi];
		acnt[ci] += acnt[bi];
		acnt[bi] = 0;
		cout << asum << endl;
	}
	return 0;
}
