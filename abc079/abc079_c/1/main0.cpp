// 学習1回目,バチャ本番AC

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
	string s, res;
	cin >> s;
	rep(i, 1<<3) {
		int val = s[0] - '0';
		rep(j, 3) {
			if (i&(1<<j)) val += s[j+1] - '0';
			else val -= s[j+1] - '0';
		}
		if (val == 7) {
			res.push_back(s[0]);
			rep(j, 3) {
				if (i&(1<<j)) res.push_back('+');
				else res.push_back('-');
				res.push_back(s[j+1]);
			}
			res += "=7";
			break;
		}
	}
	cout << res << endl;
	return 0;
}
