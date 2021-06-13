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

// 本番中、作成途中、わからない

using mint = modint1000000007;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int l = n + m;
	mint res = 0;
	rep(i, l) {
		int li = i + 1;
		if (li-k < 0) continue;
		int bl = (li-k+1) / 2;

	}
	return 0;
}
