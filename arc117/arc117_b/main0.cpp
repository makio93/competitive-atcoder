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

using mint = modint1000000007;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	int n2 = a.size();
	vector<int> b;
	b.push_back(a.front()+1);
	rep3(i, 1, n2) {
		b.push_back(a[i]-a[i-1]+1);
	}
	mint res = 1;
	for (auto bi : b) {
		res *= bi;
	}
	cout << res.val() << endl;
	return 0;
}

