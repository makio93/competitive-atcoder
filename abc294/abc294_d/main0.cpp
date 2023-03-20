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
	int n, q;
	cin >> n >> q;
	set<int> wait, call;
	rep(i, n) wait.insert(i);
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			call.insert(*wait.begin());
			wait.erase(wait.begin());
		}
		else if (qi == 2) {
			int xi;
			cin >> xi;
			--xi;
			call.erase(xi);
		}
		else {
			int res = *call.begin();
			cout << (res+1) << endl;
		}
	}
	return 0;
}
