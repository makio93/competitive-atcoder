// 

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
	vector<pair<set<int>, int>> boxes(n);
	rep(i, n) {
		boxes[i].first.insert(i);
		boxes[i].second = i;
	}
	map<int, int> ballid;
	vector<int> boxid(n);
	rep(i, n) ballid[i] = i;
	rep(i, n) boxid[i] = i;
	int nval = n;
	rep(i, q) {
		int qi, x;
		cin >> qi >> x;
		--x;
		if (qi == 1) {
			int y;
			cin >> y;
			--y;
			int xid = boxid[x], yid = boxid[y];
			if (boxes[xid].first.size() < boxes[yid].first.size()) {
				swap(boxes[xid].second, boxes[yid].second);
				swap(xid, yid);
				swap(boxid[x], boxid[y]);
			}
			for (const int& id : boxes[yid].first) {
				boxes[xid].first.insert(id);
				ballid[id] = xid;
			}
			boxes[yid].first.clear();
		}
		else if (qi == 2) {
			boxes[boxid[x]].first.insert(nval);
			ballid[nval] = boxid[x];
			++nval;
		}
		else cout << (boxes[ballid[x]].second+1) << endl;
	}
	return 0;
}
