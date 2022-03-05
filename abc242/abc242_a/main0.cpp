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

int main() {
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	if (x <= a) printf("%.10f\n", 1.0);
	else if (x <= b) printf("%.10f\n", (double)c/(b-a));
	else printf("%.10f\n", 0.0);
	return 0;
}
