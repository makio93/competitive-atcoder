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

// 本番AC

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> pvals(n, make_pair(-1, -1));
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			pvals[yi].first = xi;
			pvals[xi].second = yi;
		}
		else if (qi == 2) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			pvals[yi].first = -1;
			pvals[xi].second = -1;
		}
		else {
			int xi;
			cin >> xi;
			--xi;
			deque<int> res;
			int pid = xi;
			while (pid != -1) {
				res.push_front(pid+1);
				pid = pvals[pid].first;
			}
			pid = pvals[xi].second;
			while (pid != -1) {
				res.push_back(pid+1);
				pid = pvals[pid].second;
			}
			int m = res.size();
			cout << m << ' ';
			rep(j, m) printf("%d%c", res[j], (j<m-1?' ':'\n'));
		}
	}
	return 0;
}
