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
	int n;
	cin >> n;
	string res;
	rep(i, n+1) {
		int val = -1;
		rep3(j, 1, 10) if (n%j == 0) {
			if (i%(n/j) == 0) {
				val = j;
				break;
			}
		}
		if (val == -1) res.push_back('-');
		else res.push_back(val+'0');
	}
	cout << res << endl;
	return 0;
}
