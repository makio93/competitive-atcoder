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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, int> acnt;
	rep(i, n) acnt[a[i]]++;
	ll mval = 0;
	unordered_set<int> visited;
	for (const auto& pi : acnt) if (visited.find(pi.first) == visited.end()) {
		ll val = 0;
		queue<int> que;
		que.push(pi.first);
		visited.insert(pi.first);
		val += (ll)pi.first * pi.second;
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int t1 = (vi + 1) % m, t2 = (vi - 1 + m) % m;
			if (acnt.find(t1)!=acnt.end() && visited.find(t1)==visited.end()) {
				que.push(t1);
				visited.insert(t1);
				val += (ll)t1 * acnt[t1];
			}
			if (acnt.find(t2)!=acnt.end() && visited.find(t2)==visited.end()) {
				que.push(t2);
				visited.insert(t2);
				val += (ll)t2 * acnt[t2];
			}
		}
		mval = max(mval, val);
	}
	ll asum = accumulate(all(a), 0LL);
	cout << (asum-mval) << endl;
	return 0;
}
