// バチャ,自力AC

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
	rep(i, h) rep(j, w) if (s[i][j] == '.') {
		int y = i, x = j, cnt = 0;
		for (int dy=-1; dy<=1; ++dy) for (int dx=-1; dx<=1; ++dx) {
			int ny = y + dy, nx = x + dx;
			if (ny>=0 && ny<h && nx>=0 && nx<w && s[ny][nx]=='#') ++cnt;
		}
		s[i][j] = (char)('0'+cnt);
	}
	rep(i, h) cout << s[i] << endl;
	return 0;
}
