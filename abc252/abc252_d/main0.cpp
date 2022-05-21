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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, int> acnt;
	rep(i, n) acnt[a[i]]++;
	vector<int> vals;
	for (auto pi : acnt) vals.push_back(pi.second);
	int m = vals.size();
	vector<ll> sum(m);
	rep(i, m) sum[i] = vals[i];
	repr(i, m-1) sum[i] += sum[i+1];
	vector<ll> sum2(m);
	repr(i, m-1) sum2[i] = vals[i] * sum[i+1];
	repr(i, m-1) sum2[i] += sum2[i+1];
	ll res = 0;
	repr(i, m-2) res += vals[i] * sum2[i+1];
	cout << res << endl;
	return 0;
}
