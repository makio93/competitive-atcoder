// 学習1回目,解説AC

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
	vector<int> acnt(n+1);
	rep(i, n) acnt[a[i]]++;
	ll asum = 0;
	rep3(i, 1, n+1) asum += (ll)acnt[i] * (acnt[i]-1) / 2;
	rep(i, n) {
		ll res = asum - (acnt[a[i]] - 1);
		cout << res << endl;
	}
	return 0;
}
