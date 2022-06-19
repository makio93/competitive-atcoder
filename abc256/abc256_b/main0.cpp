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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<bool> b(4);
	int res = 0;
	rep(i, n) {
		b[0] = true;
		vector<bool> nb(4);
		repr(j, 4) if (b[j]) {
			if (j+a[i] < 4) nb[j+a[i]] = true;
			else ++res;
		}
		swap(nb, b);
	}
	cout << res << endl;
	return 0;
}
