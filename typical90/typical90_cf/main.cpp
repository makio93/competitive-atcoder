#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const int INF = (int)(1e9);
const string tar = "ox";

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> rids(2, vector<int>(n+1, n));
	vector<int> mid(2, n);
	repr(i, n) rep(j, 2) {
		rids[j][i] = rids[j][i+1];
		if (s[i] == tar[j]) {
			rids[j][i] = i;
			mid[j] = max(mid[j], i);
		}
	}
	ll res = 0;
	rep(i, n) rep(j, 2) if (s[i] == tar[j]) res += n - rids[1-j][i];
	cout << res << endl;
	return 0;
}
