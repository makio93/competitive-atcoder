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

pair<int, int> op(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> e() { return { 26, 0 }; }

int main() {
	int n;
	string s;
	cin >> n >> s;
	segtree<pair<int, int>, op, e> st(n);
	rep(i, n) st.set(i, { s[i]-'a', -i });
	int rid = n;
	rep(i, n) {
		if (i >= rid) break;
		auto [cid, pid] = st.prod(i, rid);
		if (cid >= s[i]-'a') continue;
		pid *= -1;
		st.set(i, { s[pid]-'a', -i });
		st.set(pid, { s[i]-'a', -pid });
		swap(s[i], s[pid]);
		rid = pid;
	}
	cout << s << endl;
	return 0;
}
