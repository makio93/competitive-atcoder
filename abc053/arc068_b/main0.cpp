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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, int> acnt;
	rep(i, n) acnt[a[i]]++;
	int scnt = 0;
	for (auto& pi : acnt) if (pi.second%2 == 0) ++scnt;
	if (scnt%2 == 0) cout << (int)(acnt.size()) << endl;
	else cout << (int)(acnt.size()-1) << endl;
	return 0;
}
