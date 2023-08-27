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
	unordered_set<int> a;
	int lv = INF, rv = -INF;
	rep(i, n) {
		int ai;
		cin >> ai;
		a.insert(ai);
		lv = min(lv, ai);
		rv = max(rv, ai);
	}
	int res = -1;
	rep3(i, lv, rv+1) if (a.find(i) == a.end()) {
		res = i;
		break;
	}
	cout << res << endl;
	return 0;
}
