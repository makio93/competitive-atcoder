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
	int n;
	string s;
	cin >> n >> s;
	vector<int> w(n);
	rep(i, n) cin >> w[i];
	priority_queue<int, vector<int>, greater<int>> ch;
	vector<int> ad;
	rep(i, n) {
		if (s[i] == '0') ch.push(w[i]);
		else ad.push_back(w[i]);
	}
	if (ch.empty() || ad.empty()) {
		cout << n << endl;
		return 0;
	}
	sort(all(ad));
	int res = 0, m = ad.size(), ccnt = 0;
	rep(i, m) {
		while (!ch.empty() && ch.top()<ad[i]) {
			++ccnt;
			ch.pop();
		}
		res = max(res, (m-i)+ccnt);
	}
	ccnt += ch.size();
	res = max(res, ccnt);
	cout << res << endl;
	return 0;
}
