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

// 自力AC

int op(int a, int b) { return max(a, b); }
int e() { return 0; }
int mapping(int a, int b) { return max(a, b); }
int composition(int a, int b) { return max(a, b); }
int id() { return 0; }

int main() {
	int w, n;
	cin >> w >> n;
	lazy_segtree<int, op, e, int, mapping, composition, id> seg(w+1);
	rep(i, n) {
		int li, ri;
		cin >> li >> ri;
		--li;
		int mval = seg.prod(li, ri);
		cout << (mval+1) << endl;
		seg.apply(li, ri, mval+1);
	}
	return 0;
}
