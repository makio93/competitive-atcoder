// 自力WA

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

const int INF = (int)(1.5e9);

int op1(int a, int b) { return min(a, b); }
int e1() { return INF; }
int op2(int a, int b) { return max(a, b); }
int e2() { return 0; }

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	vector<int> vlst;
	vlst.push_back(0);
	vlst.push_back(1);
	vlst.push_back(INF);
	vlst.push_back(INF-1);
	rep(i, n) {
		vlst.push_back(l[i]);
		vlst.push_back(l[i]-1);
		vlst.push_back(l[i]+1);
	}
	rep(i, n) {
		vlst.push_back(r[i]);
		vlst.push_back(r[i]-1);
		vlst.push_back(r[i]+1);
	}
	sort(all(vlst));
	vlst.erase(unique(all(vlst)), vlst.end());
	sort(all(vlst));
	int m = vlst.size();
	unordered_map<int, int> vids;
	rep(i, m) vids[vlst[i]] = i;
	segtree<int, op1, e1> st1(m);
	segtree<int, op2, e2> st2(m);
	int res = 0;
	rep(i, n) {
		int li1 = vids[l[i]-1], ri = vids[r[i]], lval = st1.prod(li1, ri+1);
		st1.set(ri, min(l[i], lval));
		int mval1 = st2.prod(0, li1), rval = max(st2.get(ri), (r[i]-l[i]+1)+mval1);
		if (lval!=INF && lval<l[i]) {
			int li2 = vids[lval-1], mval2 = st2.prod(0, li2);
			rval = max(rval, (r[i]-lval+1)+mval2);
		}
		st2.set(ri, rval);
		res = max(res, rval);
	}
	cout << res << endl;
	return 0;
}
