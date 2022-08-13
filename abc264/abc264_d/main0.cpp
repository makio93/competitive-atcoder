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
const string tar = "atcoder";

int main() {
	string s;
	cin >> s;
	vector<int> rvals(7);
	rep(i, 7) rvals[i] = tar.find(s[i]);
	int res = 0;
	rep(i, 7) rep3(j, i+1, 7) if (rvals[j] < rvals[i]) ++res;
	cout << res << endl;
	return 0;
}
