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
	int n, m;
	cin >> n >> m;
	vector<int> t(n), x(n);
	rep(i, n) cin >> t[i] >> x[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> v1, v2;
	ll sum = 0, res = 0;
	rep(i, n) {
		if (t[i] == 0) {
			sum += x[i];
			pq.push(x[i]);
			if ((int)(pq.size()) > m) {
				sum -= pq.top();
				pq.pop();
			}
		}
		if (t[i] == 1) v1.push_back(x[i]);
		if (t[i] == 2) v2.push_back(x[i]);
	}
	res = sum;
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());
	int len1 = v1.size(), len2 = v2.size(), id1 = 0;
	if (!v1.empty()) {
		rep(i2, len2) {
			int nid = min(len1, id1+v2[i2]);
			--m;
			if (m < 0) break;
			if ((int)(pq.size()) > m) {
				sum -= pq.top();
				pq.pop();
			}
			rep3(i, id1, nid) {
				sum += v1[i];
				pq.push(v1[i]);
				if ((int)(pq.size()) > m) {
					sum -= pq.top();
					pq.pop();
				}
				res = max(res, sum);
			}
			id1 = nid;
			if (id1 >= len1) break;
		}
	}
	cout << res << endl;
	return 0;
}
