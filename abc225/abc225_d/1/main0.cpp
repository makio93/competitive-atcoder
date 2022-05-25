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
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> xy(n, { -1, -1 });
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			xy[xi].second = yi;
			xy[yi].first = xi;
		}
		else if (qi == 2) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			xy[xi].second = xy[yi].first = -1;
		}
		else {
			int xi;
			cin >> xi;
			--xi;
			deque<int> res;
			res.push_front(xi);
			int nval = xi;
			while (xy[nval].first != -1) {
				nval = xy[nval].first;
				res.push_front(nval);
			}
			nval = xi;
			while (xy[nval].second != -1) {
				nval = xy[nval].second;
				res.push_back(nval);
			}
			int m = res.size();
			cout << m;
			rep(i, m) cout << ' ' << (res[i]+1);
			cout << endl;
		}
	}
	return 0;
}
