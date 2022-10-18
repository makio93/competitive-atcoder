// バチャ本番AC

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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
	vector<int> mexes(m+1);
	rep(i, n) {
		if (a[i] >= 0) pq.emplace(make_pair(a[i], i), 0);
		else if (a[i]+(ll)(i+1)*m >= 0) {
			int mi = (abs(a[i]) + i) / (i+1), ai = a[i] + (i+1) * mi;
			pq.emplace(make_pair(ai, i), mi);
		}
	}
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int mi = pi.second, av = pi.first.first, aid = pi.first.second;
		if (mexes[mi] == av) mexes[mi]++;
		++mi;
		av += aid + 1;
		if (mi<=m && av<n) pq.emplace(make_pair(av, aid), mi);
	}
	rep3(i, 1, m+1) cout << mexes[i] << endl;
	return 0;
}
