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
	string s;
	cin >> s;
	int n = s.length();
	vector<int> ccnt(10);
	auto to_mask = [](vector<int>& ccnt) -> int {
		int mask = 0;
		rep(i, 10) mask |= (ccnt[i]%2) << i;
		return mask;
	};
	unordered_map<int, int> mcnt;
	mcnt[to_mask(ccnt)]++;
	rep(i, n) {
		ccnt[s[i]-'0']++;
		mcnt[to_mask(ccnt)]++;
	}
	ll res = 0;
	for (const auto& pi : mcnt) if (pi.second >= 2) res += (ll)pi.second * (pi.second-1) / 2;
	cout << res << endl;
	return 0;
}
