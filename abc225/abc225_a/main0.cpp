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

int main() {
	string s;
	cin >> s;
	unordered_set<string> scnt;
	vector<int> ord(3);
	rep(i, 3) ord[i] = i;
	do {
		string ti;
		rep(i, 3) ti += s[ord[i]];
		scnt.insert(ti);
	} while (next_permutation(all(ord)));
	cout << (int)(scnt.size()) << endl;
	return 0;
}
