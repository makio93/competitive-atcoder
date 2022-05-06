// 練習0,自力AC

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
	double p;
	cin >> p;
	auto f = [&](double x) -> double { return x + p / pow(2.0, x/1.5); };
	double l = 0.0, r = p;
	while (r-l >= 1e-8) {
		double cl = l + (r-l) / 3.0, cr = l + (r-l) * 2.0 / 3.0;
		if (f(cl) >= f(cr)) l = cl;
		else r = cr;
	}
	double res = f(l);
	printf("%.10f\n", res);
	return 0;
}
