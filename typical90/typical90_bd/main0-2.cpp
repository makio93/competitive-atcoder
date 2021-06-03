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

// 自力WA

const string tar = "AB";
const string no = "Impossible";

int main() {
	int n, s;
	cin >> n >> s;
	vector<vector<int>> ab(n, vector<int>(2));
	rep(i, n) cin >> ab[i][0] >> ab[i][1];
	ll sum = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	string res = "";
	rep(i, n) {
		if (ab[i][0] <= ab[i][1]) {
			sum += ab[i][0];
			res += tar[0];
			if (ab[i][1]-ab[i][0] > 0) que.emplace(ab[i][1]-ab[i][0], i);
		}
		else {
			sum += ab[i][1];
			res += tar[1];
			que.emplace(ab[i][0]-ab[i][1], i);
		}
	}
	while (sum < (ll)s) {
		auto p = que.top(); que.pop();
		int sub = p.first, id = p.second;
		sum += sub;
		rep(j, 2) if (res[id] == tar[j]) {
			res[id] = tar[1-j];
			break;
		}
	}
	if (sum == (ll)s) cout << res << endl;
	else cout << no << endl;
	return 0;
}
