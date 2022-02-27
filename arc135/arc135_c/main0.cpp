// 終了後,自力AC

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

struct TrieNode {
	vector<TrieNode*> nxt;
	TrieNode() : nxt(vector<TrieNode*>(2, nullptr)) {}
	void add(int val, int di=30) {
		if (di < 0) return;
		if (nxt[((val>>di)&1)] == nullptr) nxt[((val>>di)&1)] = new TrieNode();
		nxt[((val>>di)&1)]->add(val, di-1);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	TrieNode* root = new TrieNode();
	root->add(0);
	rep(i, n) root->add(a[i]);
	vector<int> bcnt(30);
	rep(i, n) rep(j, 30) if ((a[i]>>j)&1) bcnt[j]++;
	ll res = 0;
	function<void(TrieNode*,int)> dfs = [&](TrieNode* vnode, int di) -> void {
		if (di < 0) {
			ll rval = 1, sum = 0;
			rep(i, 30) {
				sum += rval * bcnt[i];
				rval *= 2;
			}
			res = max(res, sum);
			return;
		}
		if (vnode->nxt[0] != nullptr) dfs(vnode->nxt[0], di-1);
		if (vnode->nxt[1] != nullptr) {
			int tbcnt = bcnt[di];
			bcnt[di] = n - bcnt[di];
			dfs(vnode->nxt[1], di-1);
			bcnt[di] = tbcnt;
		}
	};
	dfs(root, 30);
	cout << res << endl;
	return 0;
}
