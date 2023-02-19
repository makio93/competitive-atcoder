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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		int bcnt = count(all(s), '1'), res = 0;
		if (bcnt%2 == 1) res = -1;
		else if (bcnt>=4 || bcnt==0) res = bcnt / 2;
		else {
			int li = s.find('1');
			if (s[li+1] != '1') res = bcnt / 2;
			else if (n >= 5) res = 2;
			else if (n == 4) {
				if (li==0 || li+1==3) res = 2;
				else res = 3;
			}
			else res = -1;
		}
		cout << res << endl;
	}
	return 0;
}
