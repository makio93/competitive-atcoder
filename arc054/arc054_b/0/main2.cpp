// 練習0,解法2

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
	double xval = max(0.0, log(p*log(2.0)/1.5) / log(2.0) * 1.5);
	double res = xval + p * pow(2.0, -xval/1.5);
	printf("%.10f\n", res);
	return 0;
}
