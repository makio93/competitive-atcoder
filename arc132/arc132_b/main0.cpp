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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	int sid = -1;
	rep(i, n) if (p[i] == 1) sid = i;
	bool rev = false;
	if (abs(p[(sid+1)%n]-p[sid]) == 1) { if (p[(sid+1)%n]-p[sid] == -1) rev = true; }
	else { if (p[(sid+n-1)%n]-p[sid] == 1) rev = true; }
	int res = (int)(1e9);
	if (!rev) res = min({ res, sid, n-sid+2 });
	else res = min({ res, sid+2, (n-1)-sid+1 });
	cout << res << endl;
	return 0;
}
