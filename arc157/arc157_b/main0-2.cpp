// 本番WA2

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
	int n, k;
	string s;
	cin >> n >> k >> s;
	int xcnt = count(all(s), 'X');
	if (xcnt < k) {
		rep(i, n) {
			if (s[i] == 'X') s[i] = 'Y';
			else s[i] = 'X';
		}
		k = n - k;
	}
	if (xcnt==0 && k==0) {
		cout << (n-1) << endl;
		return 0;
	}
	int vcnt = 0;
	rep3(i, 1, n) if (s[i]=='Y' && s[i-1]=='Y') ++vcnt;
	vector<pair<int, int>> xlst;
	rep(i, n) {
		if (s[i] == 'X') {
			if (i==0 || s[i-1]=='Y') xlst.emplace_back(i, 1);
			else xlst.back().second++;
		}
	}
	vector<pair<int, int>> slst;
	for (const auto& pi : xlst) {
		if (pi.first==0 || pi.first+pi.second==n) continue;
		slst.emplace_back(pi.second, pi.first);
	}
	sort(all(slst));
	int m = slst.size();
	rep(i, m) {
		if (k < slst[i].first) break;
		vcnt += slst[i].first + 1;
		k -= slst[i].first;
	}
	vcnt += k;
	cout << vcnt << endl;
	return 0;
}
