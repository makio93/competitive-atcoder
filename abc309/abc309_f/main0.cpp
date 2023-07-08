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

const int INF = (int)(1.5e9);

int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
	int n;
	cin >> n;
	vector<vector<int>> hwd(n, vector<int>(3));
	rep(i, n) {
		cin >> hwd[i][0] >> hwd[i][1] >> hwd[i][2];
		sort(hwd[i].rbegin(), hwd[i].rend());
	}
	vector<int> wlst;
	rep(i, n) wlst.push_back(hwd[i][1]);
	sort(all(wlst));
	wlst.erase(unique(all(wlst)), wlst.end());
	int wlen = wlst.size();
	rep(i, n) hwd[i][1] = lower_bound(all(wlst), hwd[i][1]) - wlst.begin();
	map<int, vector<pair<int, int>>> hmp;
	rep(i, n) hmp[hwd[i][0]].emplace_back(hwd[i][1], hwd[i][2]);
	segtree<int, op, e> st(wlen+1);
	bool res = false;
	for (const auto& vpi : hmp) {
		for (const auto& [wi, di] : vpi.second) {
			if (st.prod(0, wi) < di) {
				res = true;
				break;
			}
		}
		if (res) break;
		for (const auto& [wi, di] : vpi.second) st.set(wi, min(st.get(wi), di));
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
