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

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	ll res = 0;
	rep(i, n) {
		if (pq.empty() || p[i]<pq.top()) pq.push(p[i]);
		else {
			res += p[i] - pq.top();
			pq.pop();
			rep(ii, 2) pq.push(p[i]);
		}
	}
	cout << res << endl;
	return 0;
}
