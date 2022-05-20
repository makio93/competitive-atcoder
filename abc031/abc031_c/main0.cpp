// 自力AC

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
	int res = -INF;
	rep(i, n) {
		pair<int, int> mval = { -INF, -1 };
		rep(j, n) if (i != j) {
			int li = i, ri = j;
			if (li > ri) swap(li, ri);
			int aval = 0;
			for (int i1=li+1; i1<=ri; i1+=2) aval += a[i1];
			mval = max(mval, { aval, -j });
		}
		int li = i, ri = -mval.second;
		if (li > ri) swap(li, ri);
		int rval = 0;
		for (int i1=li; i1<=ri; i1+=2) rval += a[i1];
		res = max(res, rval);
	}
	cout << res << endl;
	return 0;
}
