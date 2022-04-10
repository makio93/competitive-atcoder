// 本番,WA

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
	int n;
	cin >> n;
	vector<int> a(2*n);
	rep(i, n) cin >> a[i];
	rep3(i, n, 2*n) a[i] = a[i-n];
	pair<ll, int> res = { 0, -1 };
	set<pair<int, int>> pq;
	ll sum = 0;
	for (int i=n-2; i+1<2*n-2; i+=2) {
		sum += a[i];
		pq.emplace(a[i], i);
		if (pq.begin()->first < a[i+1]) {
			sum -= pq.begin()->first;
			pq.erase(pq.begin());
			sum += a[i+1];
			pq.emplace(a[i+1], i+1);
		}
	}
	res = max(res, { sum, n-2 });
	for (int i=n-4; i>=0; i-=2) {
		if (pq.find({a[i+n], i+n}) != pq.end()) {
			sum -= a[i+n];
			pq.erase({a[i+n], i+n});
		}
		if (pq.find({a[i+n+1], i+n+1}) != pq.end()) {
			sum -= a[i+n+1];
			pq.erase({a[i+n+1], i+n+1});
		}
		if ((int)(pq.size()) < n) {
			if (a[i] >= a[i+1]) {
				sum += a[i];
				pq.emplace(a[i], i);
			}
			else {
				sum += a[i+1];
				pq.emplace(a[i+1], i+1);
			}
		}
		else if (pq.begin()->first < max(a[i], a[i+1])) {
			sum -= pq.begin()->first;
			pq.erase(pq.begin());
			if (a[i] >= a[i+1]) {
				sum += a[i];
				pq.emplace(a[i], i);
			}
			else {
				sum += a[i+1];
				pq.emplace(a[i+1], i+1);
			}
		}
		res = max(res, { sum, i });
	}
	pq.clear();
	sum = 0;
	for (int i=n-1; i+1<2*n-1; i+=2) {
		sum += a[i];
		pq.emplace(a[i], i);
		if (pq.begin()->first < a[i+1]) {
			sum -= pq.begin()->first;
			pq.erase(pq.begin());
			sum += a[i+1];
			pq.emplace(a[i+1], i+1);
		}
	}
	res = max(res, { sum, n-1 });
	for (int i=n-3; i>=0; i-=2) {
		if (pq.find({a[i+n], i+n}) != pq.end()) {
			sum -= a[i+n];
			pq.erase({a[i+n], i+n});
		}
		if (pq.find({a[i+n+1], i+n+1}) != pq.end()) {
			sum -= a[i+n+1];
			pq.erase({a[i+n+1], i+n+1});
		}
		if ((int)(pq.size()) < n) {
			if (a[i] >= a[i+1]) {
				sum += a[i];
				pq.emplace(a[i], i);
			}
			else {
				sum += a[i+1];
				pq.emplace(a[i+1], i+1);
			}
		}
		else if (pq.begin()->first < max(a[i], a[i+1])) {
			sum -= pq.begin()->first;
			pq.erase(pq.begin());
			if (a[i] >= a[i+1]) {
				sum += a[i];
				pq.emplace(a[i], i);
			}
			else {
				sum += a[i+1];
				pq.emplace(a[i+1], i+1);
			}
		}
		res = max(res, { sum, i });
	}
	cout << res.second << ' ' << res.first << endl;
	return 0;
}
