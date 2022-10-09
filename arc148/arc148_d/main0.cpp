// 自力WA

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
	vector<int> a(n*2);
	rep(i, n*2) cin >> a[i];
	unordered_map<int, int> mcnt;
	rep(i, n*2) mcnt[a[i]]++;
	bool bob = true;
	for (const auto& pi : mcnt) if (pi.second%2 != 0) bob = false;
	if (bob) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return 0;
}
