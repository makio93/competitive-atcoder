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
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> alst(n);
	rep(i, n) {
		cin >> alst[i].first;
		alst[i].second = i;
	}
	unordered_set<int> bst;
	rep(i, k) {
		int bi;
		cin >> bi;
		--bi;
		bst.insert(bi);
	}
	sort(alst.rbegin(), alst.rend());
	int id = 0;
	bool ok = false;
	while (id==0 || (id>0&&id<n&&alst[id-1].first==alst[id].first)) {
		if (bst.find(alst[id].second) != bst.end()) {
			ok = true;
			break;
		}
		++id;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
