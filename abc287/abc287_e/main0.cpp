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

struct TrieNode {
	int d;
	vector<TrieNode*> next;
	TrieNode() {
		d = 0;
		next.assign(26, nullptr);
	}
};

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	TrieNode *root = new TrieNode();
	rep(i, n) {
		auto itr = root;
		for (const char& ci : s[i]) {
			if (itr->next[ci-'a'] == nullptr) itr->next[ci-'a'] = new TrieNode();
			itr->next[ci-'a']->d++;
			itr = itr->next[ci-'a'];
		}
	}
	rep(i, n) {
		auto itr = root;
		int res = 0, slen = s[i].length();
		rep(j, slen) {
			if (itr->next[s[i][j]-'a']==nullptr || itr->next[s[i][j]-'a']->d<=1) break;
			++res;
			itr = itr->next[s[i][j]-'a'];
		}
		cout << res << endl;
	}
	return 0;
}
