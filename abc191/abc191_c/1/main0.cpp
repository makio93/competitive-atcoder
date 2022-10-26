// 学習1回目,バチャ本番AC

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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int res = 0;
	rep(i, h-1) rep(j, w-1) {
		int bcnt = 0;
		rep(di, 2) rep(dj, 2) {
			int ii = i + di, jj = j + dj;
			if (s[ii][jj] == '#') ++bcnt;
		}
		if (bcnt==1 || 4-bcnt==1) ++res;
	}
	cout << res << endl;
	return 0;
}
