// 自力,TLE

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
	int n;
	cin >> n;
	vector<int> ax(n), ay(n), bx(n), by(n);
	rep(i, n) cin >> ax[i] >> ay[i];
	rep(i, n) cin >> bx[i] >> by[i];
	double p = 0.0;
	map<ll, int> vcnt;
	rep3(i, 1, n) vcnt[(ll)(ax[i]-ax[0])*(ax[i]-ax[0])+(ll)(ay[i]-ay[0])*(ay[i]-ay[0])]++;
	rep(i, n) {
		map<ll, int> tcnt;
		rep(j, n) if (j != i) tcnt[(ll)(bx[j]-bx[i])*(bx[j]-bx[i])+(ll)(by[j]-by[i])*(by[j]-by[i])]++;
		if (vcnt.size() != tcnt.size()) continue;
		bool ok = true;
		auto vitr = vcnt.begin(), titr = tcnt.begin();
		ll aval = vcnt.begin()->first, bval = tcnt.begin()->first;
		while (vitr != vcnt.end()) {
			if (vitr->second!=titr->second || vitr->first*bval!=titr->first*aval) {
				ok = false;
				break;
			}
			++vitr, ++titr;
		}
		if (ok) {
			p = sqrt((double)(tcnt.begin()->first)/vcnt.begin()->first);
			break;
		}
	}
	printf("%.10f\n", p);
	return 0;
}
