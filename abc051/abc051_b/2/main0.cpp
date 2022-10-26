// 学習2回目,バチャ本番AC

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
	int k, s;
	cin >> k >> s;
	int res = 0;
	rep(x, k+1) rep(y, k+1) {
		int z = s - x - y;
		if (z>=0 && z<=k) ++res;
	}
	cout << res << endl;
	return 0;
}
