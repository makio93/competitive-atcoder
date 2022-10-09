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
	vector<int> p(n, -1);
	rep3(i, 1, n) {
		cin >> p[i];
		p[i]--;
	}
	vector<int> cdeg(n);
	rep3(i, 1, n) cdeg[p[i]]++;
	rep(i, q) {
		int mi;
		cin >> mi;
		unordered_set<int> vst;
		rep(j, mi) {
			int vi;
			cin >> vi;
			--vi;
			vst.insert(vi);
		}
		unordered_map<int, int> ccnt;
		int res = 0;
		for (const int& vi : vst) {
			if (p[vi]==-1 || vst.find(p[vi])==vst.end()) ++res;
			else ccnt[p[vi]]++;
		}
		for (const int& vi : vst) res += cdeg[vi] - ccnt[vi];
		cout << res << endl;
	}
	return 0;
}
