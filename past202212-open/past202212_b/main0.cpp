// バチャ本番AC

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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int lval = lcm(abs(b), abs(d)), ra = a * lval / b, rc = c * lval / d;
	if (ra < rc) cout << '<' << endl;
	else if (ra > rc) cout << '>' << endl;
	else cout << '=' << endl;
	return 0;
}
