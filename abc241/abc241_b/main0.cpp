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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	unordered_map<int, int> acnt;
	rep(i, n) acnt[a[i]]++;
	bool ok = true;
	rep(i, m) {
		if (acnt.find(b[i]) == acnt.end()) {
			ok = false;
			break;
		}
		acnt[b[i]]--;
		if (acnt[b[i]] == 0) acnt.erase(b[i]);
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
