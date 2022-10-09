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

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n*2);
	rep(i, n*2) cin >> a[i];
	unordered_map<int, int> mcnt;
	rep(i, n*2) mcnt[a[i]]++;
	bool ok = true;
	if (m%2 == 1) { for (const auto& pi : mcnt) if (pi.second%2 != 0) ok = false; }
	else {
		int rcnt = 0;
		for (auto& pi : mcnt) {
			if (pi.second%2 != 0) {
				if (mcnt.find((pi.first+m/2)%m)==mcnt.end() || pi.second%2!=mcnt[(pi.first+m/2)%m]%2) ok = false;
				else {
					++rcnt;
					pi.second--;
					mcnt[(pi.first+m/2)%m]--;
				}
			}
		}
		if (rcnt%2 != 0) ok = false;
	}
	if (ok) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return 0;
}
