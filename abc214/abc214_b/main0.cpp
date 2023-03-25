// 本番AC

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

int main() {
	int s, t;
	cin >> s >> t;
	int res = 0;
	rep(a, s+1) rep(b, s-a+1) rep(c, s-a-b+1) if (a*b*c <= t) ++res;
	cout << res << endl;
	return 0;
}
