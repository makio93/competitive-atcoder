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

// 自力で解答、小課題4まで得点

void query(map<int, int>& a, int v) {
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
		map<int, int> a;
		int l = 1, r = n;
		query(a, l); query(a, r);
		while (r-l > 1) {
			int c = (l+r) / 2;
			query(a, c);
			if (a[c] <= a[r]) l = c;
			else if (a[c] <= a[l]) r = c;
			else {
				if (c+1 < r) {
					query(a, c+1);
					if (a[c+1] > a[c]) l = c+1;
					else r = c;
				}
				else if (c-1 > l) {
					query(a, c-1);
					if (a[c-1] > a[c]) r = c-1;
					else l = c;
				}
				else {
					pair<int, int> mval = { -1, -1 };
					rep3(i, l, r+1) mval = max(mval, { a[i], i });
					l = r = mval.second;
				}
			}
		}
		if (l < r) {
			pair<int, int> mval = { -1, -1 };
			rep3(i, l, r+1) mval = max(mval, { a[i], i });
			l = r = mval.second;
		}
		cout << "! " << a[l] << endl;
		cout.flush();
	}
	return 0;
}
