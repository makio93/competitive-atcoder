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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int res = INF;
	for (int ci='0'; ci<='9'; ++ci) {
		vector<int> ccnt(10);
		rep(i, n) ccnt[s[i].find(ci)]++;
		pair<int, int> mval = { -1, -1 };
		rep(i, 10) mval = max(mval, { ccnt[i], i });
		int val = 10 * (mval.first-1) + mval.second;
		res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
