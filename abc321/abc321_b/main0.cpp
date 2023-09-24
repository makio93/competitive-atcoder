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
	int n, x;
	cin >> n >> x;
	vector<int> a(n-1);
	rep(i, n-1) cin >> a[i];
	int res = -1;
	rep(i, 101) {
		auto b = a;
		b.push_back(i);
		sort(all(b));
		if (accumulate(b.begin()+1, b.end()-1, 0) >= x) {
			res = i;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
