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

const int INF = (int)(1e9);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> l(n), r(n);
		rep(i, n) cin >> l[i] >> r[i];
		vector<pair<int, int>> lr(n);
		rep(i, n) lr[i] = { l[i], r[i] };
		sort(all(lr));
		priority_queue<int, vector<int>, greater<int>> pq;
		int id = 1, scnt = n;
		while (scnt > 0) {
			auto itr = lower_bound(all(lr), make_pair(id, 0));
			if (pq.empty() && itr!=lr.end()) id = itr->first;
			while (itr!=lr.end() && itr->first==id) {
				pq.push(itr->second);
				++itr;
			}
			if (!pq.empty()) {
				pq.pop();
				--scnt;
			}
			if (!pq.empty() && pq.top()<=id) break;
			++id;
		}
		if (scnt == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
