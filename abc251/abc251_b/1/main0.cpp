// バチャ,自力AC

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
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<bool> acnt(w+1);
	rep(i, n) {
		int val1 = a[i];
		if (val1 > w) continue;
		acnt[val1] = true;
		rep3(j, i+1, n) {
			int val2 = val1 + a[j];
			if (val2 > w) continue;
			acnt[val2] = true;
			rep3(k, j+1, n) {
				int val3 = val2 + a[k];
				if (val3 > w) continue;
				acnt[val3] = true;
			}
		}
	}
	int res = 0;
	rep3(i, 1, w+1) if (acnt[i]) ++res;
	cout << res << endl;
	return 0;
}
