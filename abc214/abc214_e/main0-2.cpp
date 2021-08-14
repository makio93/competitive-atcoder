#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番解答2,WA

int main() {
	int t;
	cin >> t;
	rep(i0, t) {
		int n;
		cin >> n;
		vector<int> l(n), r(n);
		rep(i, n) cin >> l[i] >> r[i];
		map<int, int> sub;
		rep(i, n) {
			sub[l[i]]++;
			sub[r[i]+1]--;
		}
		sub[0] = 0;
		bool ok = true, plus = false;
		int cnt = 0, cap = 0, pid = 0;
		for (auto p : sub) {
			if (p.first == 0) continue;
			if (plus) cnt = max(0, cnt-(p.first-pid));
			cap += p.second;
			if (cnt > cap) {
				ok = false;
				break;
			}
			if (p.second > 0) plus = true;
			else plus = false;
			cnt += max(0, p.second);
			pid = p.first;
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
