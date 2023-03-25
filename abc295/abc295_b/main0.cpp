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

int main() {
	int r, c;
	cin >> r >> c;
	vector<string> b(r);
	rep(i, r) cin >> b[i];
	auto res = b;
	auto is_fire = [&](int ri, int ci) -> bool {
		rep(i, r) rep(j, c) if (isdigit(b[i][j]) && abs(i-ri)+abs(j-ci)<=b[i][j]-'0') return true;
		return false; 
	};
	rep(i, r) rep(j, c) if (b[i][j]!='.' && is_fire(i, j)) res[i][j] = '.';
	rep(i, r) cout << res[i] << endl;
	return 0;
}
