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
	int a, n;
	cin >> a >> n;
	vector<int> memo(n*10+1, -10);
	function<int(int)> calc = [&](int val) -> int {
		if (memo[val] != -10) return memo[val];
		if (val < 1) return -1;
		else if (val == 1) return memo[val] = 0;
		else if (val < 10) {
			if (val%a == 0) {
				int rval = calc(val/a);
				if (rval != -1) return memo[val] = rval + 1;
				else return memo[val] = -1;
			}
			else return memo[val] = -1;
		}
		else {
			int res = -1;
			if (val%a == 0) {
				int rval = calc(val/a);
				if (rval != -1) res = rval + 1;
			}
			string vstr = to_string(val);
			int len = vstr.length();
			rep3(i, 1, len) {
				string tstr = vstr.substr(i)+vstr.substr(0,i);
				if (tstr[0] == '0') break;
				int tval = stoi(tstr);
				if (tval%a == 0) {
					int rval = calc(tval/a);
					if (rval != -1) {
						if (res == -1) res = rval + i + 1;
						else res = min(res, rval+i+1);
					}
				}
			}
			return memo[val] = res;
		}
	};
	cout << calc(n) << endl;
	return 0;
}
