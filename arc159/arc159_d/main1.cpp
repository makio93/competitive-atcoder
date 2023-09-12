// 解説AC

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

const int INF = (int)(1.5e9);

int op1(int a, int b) { return min(a, b); }
int e1() { return INF; }
int op2(int a, int b) { return max(a, b); }
int e2() { return 0; }

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	map<int, int> mp;
	rep(i, n) {
		int len = r[i] - l[i] + 1;
		auto itr = mp.upper_bound(l[i]);
		bool make = true;
		if (itr != mp.begin()) {
			int pr = prev(itr)->first + prev(itr)->second - 1;
			if (pr >= l[i]) {
				if (pr-l[i]+1 >= len) continue;
				len -= pr-l[i]+1;
				prev(itr)->second = r[i] - prev(itr)->first + 1;
				make = false;
			}
		}
		if (make) mp[l[i]] = r[i] - l[i] + 1;
		while (itr!=mp.end() && len>itr->second) {
			len -= itr->second;
			itr = mp.erase(itr);
		}
		if (itr != mp.end() && len > 0) {
			mp[itr->first+len] = itr->second - len;
			mp.erase(itr);
		}
	}
	int res = 0;
	for (auto itr=mp.begin(); itr!=mp.end(); ++itr) res += itr->second;
	cout << res << endl;
	return 0;
}
