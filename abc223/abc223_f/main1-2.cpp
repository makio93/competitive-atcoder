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

// 解説AC2,遅延セグ木

const int INF = (int)(1e9);

int op(int a, int b) { return min(a, b); }
int e() { return INF; }
int mapping(int f, int x) { return f+x; }
int composition(int f, int g) { return f+g; }
int id() { return 0; }

int main() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<int> vals(n), sum(n+1);
	rep(i, n) {
		if (s[i] == '(') vals[i] = 1;
		else vals[i] = -1;
	}
    rep(i, n) sum[i+1] = sum[i] + vals[i];
    lazy_segtree<int, op, e, int, mapping, composition, id> st(sum);
    rep(i, q) {
        int ti, li, ri;
        cin >> ti >> li >> ri;
        --li; --ri;
        if (ti == 1) {
            swap(vals[li], vals[ri]);
            st.apply(li+1, ri+1, vals[li]-vals[ri]);
        }
        else {
            if (st.prod(li+1,ri+1)>=st.get(li) && st.get(ri+1)==st.get(li)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
	return 0;
}
