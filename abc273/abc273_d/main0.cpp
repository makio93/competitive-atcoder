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
	int h, w, rs, cs, n, q;
	cin >> h >> w >> rs >> cs >> n;
	map<int, set<int>> rtoc, ctor;
	rep(i, n) {
		int ri, ci;
		cin >> ri >> ci;
		rtoc[ri].insert(ci);
		ctor[ci].insert(ri);
	}
	cin >> q;
	rep(i, q) {
		char di;
		int li;
		cin >> di >> li;
		if (di == 'L') {
			if (rtoc.find(rs) == rtoc.end()) cs = max(1, cs-li);
			else {
				auto itr = rtoc[rs].lower_bound(cs);
				if (itr != rtoc[rs].begin()) cs = max(*prev(itr)+1, cs-li);
				else cs = max(1, cs-li);
			}
		}
		else if (di == 'R') {
			if (rtoc.find(rs) == rtoc.end()) cs = min(w, cs+li);
			else {
				auto itr = rtoc[rs].lower_bound(cs);
				if (itr != rtoc[rs].end()) cs = min(*itr-1, cs+li);
				else cs = min(w, cs+li);
			}
		}
		else if (di == 'U') {
			if (ctor.find(cs) == ctor.end()) rs = max(1, rs-li);
			else {
				auto itr = ctor[cs].lower_bound(rs);
				if (itr != ctor[cs].begin()) rs = max(*prev(itr)+1, rs-li);
				else rs = max(1, rs-li);
			}
		}
		else {
			if (ctor.find(cs) == ctor.end()) rs = min(h, rs+li);
			else {
				auto itr = ctor[cs].lower_bound(rs);
				if (itr != ctor[cs].end()) rs = min(*itr-1, rs+li);
				else rs = min(h, rs+li);
			}
		}
		cout << rs << ' ' << cs << endl;
	}
	return 0;
}
