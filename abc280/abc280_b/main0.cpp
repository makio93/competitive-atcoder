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
	int n;
	cin >> n;
	vector<int> s(n);
	rep(i, n) cin >> s[i];
	vector<int> a(n);
	a[0] = s[0];
	rep3(i, 1, n) a[i] = s[i] - s[i-1];
	rep(i, n) cout << a[i] << (i<n-1?' ':'\n');
	return 0;
}
