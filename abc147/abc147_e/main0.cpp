// バチャ本番AC

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
const int ADD = 80 * 80 * 2;

int main() {
	int h, w;
	cin >> h >> w;
	vector a(h, vector(w, 0)), b(h, vector(w, 0));
	rep(i, h) rep(j, w) cin >> a[i][j];
	rep(i, h) rep(j, w) cin >> b[i][j];
	vector<bitset<30000>> bs(w+1);
	bs[0][a[0][0]-b[0][0]+ADD] = bs[0][b[0][0]-a[0][0]+ADD] = 1;
	rep3(i, 1, h*w) {
		bs[i%(w+1)] &= 0;
		int ab = abs(a[i/w][i%w]-b[i/w][i%w]);
		if (i%w != 0) {
			bs[i%(w+1)] |= bs[(i-1)%(w+1)] << ab;
			bs[i%(w+1)] |= bs[(i-1)%(w+1)] >> ab;
		}
		if (i-w >= 0) {
			bs[i%(w+1)] |= bs[(i-w)%(w+1)] << ab;
			bs[i%(w+1)] |= bs[(i-w)%(w+1)] >> ab;
		}
	}
	int res = INF;
	rep(i, 30000) if (bs[(h*w-1)%(w+1)][i]) res = min(res, abs(i-ADD));
	cout << res << endl;
	return 0;
}
