// 学習1回目,バチャ本番AC

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
	vector<int> res(m);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	rep(i, n) if (a[i]+(i+1) <= n) {
		if (a[i]+(i+1) >= 0) pq.emplace(a[i]+i+1, i, 1);
		else if ((abs(a[i])+i)/(i+1) <= m) {
			int mid = (abs(a[i])+i) / (i+1);
			pq.emplace(a[i]+mid*(i+1), i, mid);
		}
	}
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int aval = get<0>(pi), id = get<1>(pi), mi = get<2>(pi);
		if (res[mi-1] == aval) res[mi-1] = aval + 1;
		if (mi+1<=m && aval+id+1<=n) pq.emplace(aval+id+1, id, mi+1);
	}
	rep(i, m) cout << res[i] << endl;
	return 0;
}
