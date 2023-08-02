// 本番WA

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
	ll n;
	int m;
	cin >> n >> m;
	vector<ll> x(m);
	vector<int> y(m);
	rep(i, m) cin >> x[i] >> y[i];
	if (m == 0) {
		if (n <= 1) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
		return 0;
	}
	int tcnt = 0, ecnt = 0;
	if (x[0]-1 >= 2) ++ecnt;
	if (n-x[m-1] >= 2) ++ecnt;
	if (ecnt == 1) {
		cout << "Takahashi" << endl;
		return 0;
	}
	if ((x[0]-1)%2 == 1) ++tcnt;
	if ((n-x[m-1])%2 == 1) ++tcnt;
	rep(i, m-1) {
		if (x[i+1]-x[i] <= 4) {
			if (y[i+1] == y[i]) ++tcnt;
		}
		else {
			tcnt += ((x[i+1]-x[i]-3)/2+(y[i+1]+y[i])%2)%2;
		}
	}
	if (ecnt == 0) {
		if (tcnt%2 == 1) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}
	else if (ecnt == 2) {
		ll sval = (x[0]-1)/2 + (n-x[m-1])/2;
		if ((tcnt+sval)%2 == 1) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
		return 0;
	}
	return 0;
}
