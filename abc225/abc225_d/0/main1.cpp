// 解説AC

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
	int n, q;
	cin >> n >> q;
	vector<int> fid(n, -1), bid(n, -1);
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			fid[yi] = xi;
			bid[xi] = yi;
		}
		else if (qi == 2) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			fid[yi] = -1;
			bid[xi] = -1;
		}
		else {
			int xi;
			cin >> xi;
			--xi;
			int pid = xi;
			while (fid[pid] != -1) pid = fid[pid];
			vector<int> res;
			while (pid != -1) {
				res.push_back(pid+1);
				pid = bid[pid];
			}
			int m = res.size();
			cout << m << ' ';
			rep(j, m) printf("%d%c", res[j], (j<m-1?' ':'\n'));
		}
	}
	return 0;
}
