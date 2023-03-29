// 学習1回目,バチャ本番,自力AC

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
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	rep(i, n) {
		pq.push(p[i]);
		if ((int)(pq.size()) > k) pq.pop();
		if (i >= k-1) cout << pq.top() << endl;
	}
	return 0;
}
