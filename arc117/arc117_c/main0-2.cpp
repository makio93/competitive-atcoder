// 本番2,WA

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

int main() {
	int n;
	cin >> n;
	string c;
	cin >> c;
	string clst = "BWR";
	unordered_map<char, int> cid;
	rep(i, 3) cid[clst[i]] = i;
	char res;
	vector<string> convert = { "BRW", "RWB", "WBR" };
	rep3r(i, 2, n+1) {
		string nc;
		set<char> cnt;
		rep(i, (int)(c.length())-1) {
			char ci = (char)convert[cid[c[i]]][cid[c[i+1]]];
			nc += ci;
			cnt.insert(ci);
		}
		if ((int)(cnt.size()) == 1) {
			res = nc.front();
			break;
		}
		swap(c, nc);
	}
	if ((int)(c.length()) == 1) res = c.front();
	cout << res << endl;
	return 0;
}
