// 終了後,自力WA2

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
	int mval = *min_element(all(a));
	vector<pair<int, int>> alst(n);
	rep(i, n) alst[i] = { a[i]-mval, i };
	sort(all(alst));
	if (n%2 == 1) {
		bool ok = true;
		rep(i, n) if (alst[i].first%2 == 1) {
			ok = false;
			break;
		}
		if (!ok) {
			cout << "No" << endl;
			return 0;
		}
		rep(i, n) alst[i].first /= 2;
	}
	vector<vector<int>> res;
	int pcnt = 0;
	rep(i, n) if (alst[i].first%2 == 1) ++pcnt;
	if (pcnt > 0) {
		bool ok = true;
		if (n%2==0 && pcnt!=n/2) ok = false;
		if (n%2==1 && pcnt!=(n+1)/2 && pcnt!=n/2) ok = false;
		if (!ok) {
			cout << "No" << endl;
			return 0;
		}
		vector<int> tlst;
		if (n%2 == 0) {
			rep(i, n) if (alst[i].first%2 == 1) tlst.push_back(alst[i].second);
		}
		else {
			if (pcnt == (n+1)/2) {
				rep(i, n) if (alst[i].first%2 == 1) tlst.push_back(alst[i].second);
			}
			else {
				rep(i, n) if (alst[i].first%2 == 0) tlst.push_back(alst[i].second);
			}
		}
		res.push_back(vector<int>(n, -1));
		int id = 1;
		for (const int& ti : tlst) {
			res[0][ti] = id;
			id += 2;
		}
		id = 2;
		rep(i, n) if (res[0][i] == -1) {
			res[0][i] = id;
			id += 2;
		}
		vector<int> b(n);
		rep(i, n) b[alst[i].second] = alst[i].first;
		rep(i, n) b[i] += res[0][i];
		rep(i, n) alst[i] = { b[i], i };
		sort(all(alst));
	}
	int lval = n / 2, rval = n + 1 - n / 2;
	rep(i, n/2) {
		int li = i, ri = n - 1 - i, tval = (alst[ri].first - alst[li].first);
		rep(j, tval) {
			res.push_back(vector<int>(n, -1));
			vector<int>& tlst = res.back();
			tlst[alst[li].second] = rval;
			tlst[alst[ri].second] = lval;
			if (j%2 == 0) {
				int id = 1;
				rep(j2, n) if (tlst[j2] == -1) {
					while (id==lval || id==rval) ++id;
					tlst[j2] = id;
					++id;
				}
			}
			else {
				int id = 1;
				repr(j2, n) if (tlst[j2] == -1) {
					while (id==lval || id==rval) ++id;
					tlst[j2] = id;
					++id;
				}
			}
		}
	}
	cout << "Yes" << endl;
	int m = res.size();
	cout << m << endl;
	rep(i, m) rep(j, n) cout << res[i][j] << (j<n-1?' ':'\n');
	return 0;
}
