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

// 本番後,自力WA

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	priority_queue<ll, vector<ll>, greater<ll>> que;
	rep(i, n) que.push(a[i]);
	while ((int)(que.size()) > k) {
		ll val1 = que.top(); que.pop();
		ll val2 = que.top(); que.pop();
		que.push(val1+val2);
	}
	cout << que.top() << endl;
	return 0;
}
