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
	int w;
	cin >> w;
	map<int, int> st;
	st[1] = 1;
	rep3(i, 2, w+1) if (st.find(i) == st.end()) {
		map<int, int> pst = st;
		pst[i] = 1;
		for (auto pi : st) if (pi.second<3 && pi.first+i<=w) {
			if (pst.find(pi.first+i) == pst.end()) pst[pi.first+i] = pi.second + 1;
			else pst[pi.first+i] = min(pst[pi.first+i], pi.second+1);
		}
		swap(pst, st);
	}
	vector<int> res;
	for (auto pi : st) if (pi.second == 1) res.push_back(pi.first);
	int n = res.size();
	cout << n << endl;
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ': '\n'));
	return 0;
}
