// 本番WA

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
	int n, m;
	ll k;
	string s;
	cin >> n >> m >> k >> s;
	int xcnt = count(all(s), 'x');
	ll aval = k / xcnt, bval = k % xcnt;
	string t = s + s;
	vector<int> xids;
	xids.push_back(-1);
	rep(i, n*2) if (t[i] == 'x') xids.push_back(i);
	xids.push_back(n*2);
	ll res = 0;
	int xlen = xids.size();
	rep(i, xlen) {
		int ri = min(xlen-1, (int)(i+bval+1));
		if (xids[ri]>=n && xids[i]<n && i!=0 && ri!=xlen-1) res = max(res, (xids[ri]-xids[i]-1)+min((ll)(m-2),aval)*n);
		else res = max(res, (xids[ri]-xids[i]-1)+aval*n);
	}
	cout << res << endl;
	return 0;
}
