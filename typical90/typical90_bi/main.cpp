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

int main() {
	int q;
	cin >> q;
	vector<int> l, r;
	rep(i, q) {
		int ti, xi;
		cin >> ti >> xi;
		if (ti == 1) l.push_back(xi);
		else if (ti == 2) r.push_back(xi);
		else {
			int llen = l.size();
			if (xi <= llen) cout << l[llen-xi] << endl;
			else cout << r[xi-llen-1] << endl;
		}
	}
	return 0;
}
