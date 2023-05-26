// 自力AC2

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

template<typename T>
class LazySegmentTree {
	T INF_ST;
	int n;
	vector<T> node, lazy;
public:
	LazySegmentTree(int n_, T INF_ST_=numeric_limits<T>::max()) : LazySegmentTree(vector<T>(n_, INF_ST_), INF_ST_) {}
	LazySegmentTree(vector<T> v, T INF_ST_=numeric_limits<T>::max()) : INF_ST(INF_ST_) {
		int n_ = v.size();
		n = 1;
		while (n < n_) n *= 2;
		node.resize(n*2-1, INF_ST);
		lazy.resize(n*2-1, INF_ST);
		for (int i=0; i<n_; ++i) node[n+i-1] = v[i];
		for (int i=n-2; i>=0; --i) node[i] = min(node[i*2+1], node[i*2+2]);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != INF_ST) {
			node[k] = lazy[k];
			if (r-l > 1) {
				lazy[k*2+1] = lazy[k*2+2] = lazy[k];
			}
			lazy[k] = INF_ST;
		}
	}
	void update(int a, int b, T x, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (b<=l || r<=a) return;
		if (a<=l && r<=b) {
			lazy[k] = x;
			eval(k, l, r);
		}
		else {
			update(a, b, x, k*2+1, l, (l+r)/2);
			update(a, b, x, k*2+2, (l+r)/2, r);
			node[k] = min(node[k*2+1], node[k*2+2]);
		}
	}
	T find(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (b<=l || r<=a) return INF_ST;
		if (a<=l && r<=b) return node[k];
		T vl = find(a, b, k*2+1, l, (l+r)/2);
		T vr = find(a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> l(n-1), r(n-1);
	rep(i, n-1) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	vector<int> a(q), b(q);
	rep(i, q) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	vector<int> alst;
	rep(i, n-1) alst.push_back(l[i]);
	rep(i, n-1) alst.push_back(r[i]);
	rep(i, q) alst.push_back(a[i]);
	sort(all(alst));
	alst.erase(unique(all(alst)), alst.end());
	int m = alst.size();
	rep(i, n-1) l[i] = lower_bound(all(alst), l[i]) - alst.begin();
	rep(i, n-1) r[i] = lower_bound(all(alst), r[i]) - alst.begin();
	rep(i, q) a[i] = lower_bound(all(alst), a[i]) - alst.begin();
	vector<int> ord(q);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return b[li] > b[ri];
	});
	LazySegmentTree<int> lst(m);
	lst.update(0, m, n-1);
	int tid = 0;
	vector<int> res(q);
	repr(i, n) {
		if (i < n-1) {
			lst.update(0, l[i], i);
			lst.update(r[i]+1, m, i);
		}
		while (tid<q && b[ord[tid]]==i) {
			res[ord[tid]] = lst.find(a[ord[tid]], a[ord[tid]]+1) - i + 1;
			++tid;
		}
	}
	reverse(all(ord));
	lst.update(0, m, 0);
	tid = 0;
	rep(i, n) {
		if (i-1 >= 0) {
			lst.update(0, l[i-1], i);
			lst.update(r[i-1]+1, m, i);
		}
		while (tid<q && b[ord[tid]]==i) {
			res[ord[tid]] += i - lst.find(a[ord[tid]], a[ord[tid]]+1);
			++tid;
		}
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
