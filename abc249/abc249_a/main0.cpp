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
	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	int val1 = x / (a+c) * a * b + min(a, x%(a+c)) * b;
	int val2 = x / (d+f) * d * e + min(d, x%(d+f)) * e;
	if (val1 > val2) cout << "Takahashi" << endl;
	else if (val2 > val1) cout << "Aoki" << endl;
	else cout << "Draw" << endl;
	return 0;
}
