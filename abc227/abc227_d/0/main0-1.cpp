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

// 本番WA1

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	priority_queue<ll, vector<ll>, greater<ll>> que;
	rep(i, k) que.push(a[i]);
	int id = k;
	while (id < n) {
		ll pval = que.top(); que.pop();
		que.push(pval+a[id]);
		++id;
	}
	cout << que.top() << endl;
	return 0;
}
