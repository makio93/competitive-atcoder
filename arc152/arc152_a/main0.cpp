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
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<bool> b(l);
	int id = 1, tid = -1;
	rep(i, n) {
		if (id >= l) {
			tid = i;
			break;
		}
		if (a[i]==2 && id+1>=l) {
			b[id-1] = b[id] = true;
			id += 2;
		}
		else {
			rep(j, a[i]) {
				b[id] = true;
				++id;
			}
			++id;
		}
	}
	bool ok = true;
	if (tid != -1) {
		rep3(i, tid, n) if (a[i] == 2) {
			ok = false;
			break;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
