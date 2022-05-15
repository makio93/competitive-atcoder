// 本番,WA

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
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	map<ll, ll> ast;
	rep(i, n) ast[a[i]] = 0;
	int cnt = 0;
	while ((int)(ast.size())>1 && cnt<n*30) {
		auto itr = ast.begin();
		ll aval = itr->first, xval = itr->second;
		ast.erase(itr);
		bool br = true;
		while (!ast.empty()) {
			auto titr = ast.lower_bound(aval);
			if (next(titr) == ast.end()) {
				if (titr->first > aval+xval) {
					ll taval = aval * 2, txval = xval * 2 + x;
					if (titr->first-(aval+xval) <= taval-titr->first) ast[aval] = xval;
					else {
						ast[taval] = txval;
						br = false;
					}
				}
				else {
					//ast[titr->first] = min(ast[titr->first], xval-(titr->first-aval));
					br = false;
				}
				break;
			}
			else {
				br = false;
				if (titr->first <= aval+xval) {
					//ast[titr->first] = min(ast[titr->first], xval-(titr->first-aval));
					break;
				}
				else {
					aval *= 2;
					xval = xval * 2 + x;
				}
			}
		}
		if (br) break;
		++cnt;
	}
	cout << (ast.rbegin()->first-ast.begin()->first) << endl;
	return 0;
}
