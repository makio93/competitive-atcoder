#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力解答2回目、3点を獲得
int maxn;

void query(map<int, int>& a, int v) {
	v = min(v, maxn);
	if (a.find(v) == a.end()) {
		int res = -1;
		cout << "? " << v << endl;
		cout.flush();
		cin >> res;
		if (res == -1) exit(0);
		a[v] = res;
	}
}

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		maxn = n;
		map<int, int> a;
		int l = 1, r = n;
		while (r-l>=3) {
			int d3 = (r-l+2) / 3, lc = l + d3, rc = max(lc+1, r-d3);
			query(a, lc); query(a, rc);
			if (a[lc] < a[rc]) l = lc;
			else if (a[lc] > a[rc]) r = rc;
			else { l = lc; r = rc; }
		}
		{
			pair<int, int> mval = { -1, -1 };
			rep3(i, l, r+1) {
				query(a, i);
				mval = max(mval, { a[i], i });
			}
			l = r = mval.second;
		}
		cout << "! " << a[l] << endl;
		cout.flush();
	}
	return 0;
}
