// 終了後,自力AC

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
	int n, x;
	cin >> n >> x;
	vector<int> res;
	if ((n%2==1&&x==(n+1)/2) || (n%2==0&&((n+1)/2==x||(n+1)/2+1==x))) {
		bool rev = (n%2==0 && (n+1)/2+1==x);
		int tval = x;
		res.push_back(tval);
		rep3(i, 1, n) {
			int add = i;
			if ((i%2==1) ^ (!rev)) add *= -1;
			tval += add;
			res.push_back(tval);
		}
	}
	else {
		int tval = 1, di = n-1;
		if (tval == x) { ++tval; --di; }
		res.push_back(tval);
		rep3(i, 1, n-1) {
			int add = di;
			if (i%2 == 0) add *= -1;
			if (tval+add == x) {
				--di; add = di;
				if (i%2 == 0) add *= -1;
			}
			tval += add;
			res.push_back(tval);
			--di;
		}
		res.push_back(x);
		reverse(all(res));
	}
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
