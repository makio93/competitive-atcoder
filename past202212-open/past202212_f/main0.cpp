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
	ll n, a, b, c, d;
	string x;
	cin >> n >> a >> b >> c >> d >> x;
	int pid = x.find('.'), xval = stoi(x.substr(0, pid)) * 1000 + stoi(x.substr(pid+1));
	ll sval = a * (1000-xval) + b * (2000-xval) + c * (3000-xval) + d * (4000-xval);
	ll res = sval <= 0 ? 0 : (sval+abs(1000-xval)-1) / abs(1000-xval);
	cout << res << endl;
	return 0;
}
