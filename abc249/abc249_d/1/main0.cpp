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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int mval = 0;
	rep(i, n) mval = max(mval, a[i]);
	vector<int> acnt(mval+1);
	rep(i, n) acnt[a[i]]++;
	ll res = 1;
	rep(i, 3) res *= acnt[1];
	rep3(i, 2, mval+1) res += (ll)acnt[1] * acnt[i] * acnt[i] * 2;
	for (int i=2; i*i<=mval; ++i) {
		res += (ll)acnt[i] * acnt[i] * acnt[i*i];
		for (int j=i+1; i*j<=mval; ++j) res += (ll)acnt[i] * acnt[j] * acnt[i*j] * 2;
	}
	cout << res << endl;
	return 0;
}
