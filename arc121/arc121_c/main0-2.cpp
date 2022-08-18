// 自力AC

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> p(n), res;
		rep(i, n) cin >> p[i];
		if (n == 2) {
			if (p[0] != 1) {
				res.push_back(1);
				swap(p[0], p[1]);
			}
		}
		else {
			rep(i, n-2) {
				int ri = n-1-i, id = ri;
				while (p[id] != ri+1) --id;
				if (id == ri) continue;
				if ((int)(res.size()+1)%2 != (id+1)%2) {
					if (id+2 <= ri) {
						res.push_back(id+2);
						swap(p[id+1], p[id+2]);
					}
					else if (id-1 >= 0) {
						res.push_back(id);
						swap(p[id-1], p[id]);
						res.push_back(id+1);
						swap(p[id], p[id+1]);
						--id;
					}
				}
				rep3(j, id, ri) {
					res.push_back(j+1);
					swap(p[j], p[j+1]);
				}
			}
			if (p[0] != 1) {
				if ((int)(res.size()+1)%2 == 1) {
					res.push_back(1);
					swap(p[0], p[1]);
				}
				else {
					for (int vid : { 2, 1, 2, 1, 2 }) res.push_back(vid);
					sort(p.begin(), p.begin()+3);
				}
			}
		}
		int m = res.size();
		cout << m << endl;
		rep(i, m) cout << res[i] << (i<m-1?' ':'\n');
	}
	return 0;
}
