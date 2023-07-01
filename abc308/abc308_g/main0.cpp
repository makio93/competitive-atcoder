// 本番WA

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

struct TrieNode {
	int vcnt, pval;
	vector<TrieNode*> next;
	TrieNode() {
		next.assign(2, nullptr);
		vcnt = 0;
		pval = 0;
	}
};
class Trie {
public:
	TrieNode *root;
	Trie() { root = new TrieNode(); }
	void add(int val) {
		auto node = root;
		repr(i, 30) {
			int bval = (val>>i) & 1;
			if (node->next[bval] == nullptr) {
				node->next[bval] = new TrieNode();
			}
			node->next[bval]->vcnt++;
			if (node->next[bval]->vcnt <= 2) node->next[bval]->pval ^= val;
			node = node->next[bval];
		}
	}
	void rem(int val) {
		auto node = root;
		repr(i, 30) {
			int bval = (val>>i) & 1;
			if (node->next[bval]->vcnt <= 2) node->next[bval]->pval ^= val;
			node->next[bval]->vcnt--;
			node = node->next[bval];
		}
	}
	int search(TrieNode* vnode, int id) {
		if (id == 0) return 0;
		int rval = INF;
		if (vnode->next[0]->vcnt==1 && vnode->next[1]->vcnt==1) {
			rval = ((vnode->next[0]->pval) ^ (vnode->next[1]->pval)) & ((1<<id)-1);
		}
		rep(i, 2) {
			if (vnode->next[i]->vcnt >= 2) {
				if (vnode->next[i]->vcnt == 2) rval = min(rval, vnode->next[i]->pval&((1<<id)-1));
				else rval = min(rval, search(vnode->next[i], id+1) & ((1<<id)-1));
			}
		}
		return rval;
	}
};

int main() {
	int q;
	cin >> q;
	Trie tr;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int x;
			cin >> x;
			tr.add(x);
		}
		else if (qi == 2) {
			int x;
			cin >> x;
			tr.rem(x);
		}
		else {
			cout << tr.search(tr.root, 30) << endl;
		}
	}
	return 0;
}
