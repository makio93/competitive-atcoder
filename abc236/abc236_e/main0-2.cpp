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

// 本番後,二分探索と方針を決めて自力考察,WA

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	double l = 0.0, r = 1.1e9;
	vector<pair<int, int>> alst(n);
	rep(i, n) alst[i] = { a[i], i };
	sort(alst.rbegin(), alst.rend());
	while (r-l > 1e-5) {
		double c = l + (r-l) / 2.0;
		ll sum = 0;
		vector<bool> choosed(n);
		rep(i, n) {
			int id = alst[i].second;
			bool ok = true;
			if (id-1>=0 && !choosed[id-1]) ok = false;
			if (id+1<n && !choosed[id+1]) ok = false;
			if (!ok) {
				choosed[id] = true;
				sum += a[id];
			}
		}
		int cnt = 0;
		rep(i, n) if (choosed[i]) ++cnt;
		if (cnt>0 && sum/(double)cnt>=c) l = c;
		else r = c;
	}
	printf("%.10f\n", l);
	int li = 0, ri = (int)(1.05e9);
	while (ri-li > 1) {
		int ci = li + (ri-li) / 2;
		vector<bool> choosed(n);
		vector<int> clst;
		rep(i, n) {
			if (a[i] >= ci) {
				choosed[i] = true;
				clst.push_back(a[i]);
			}
			else {
				if (i-1>=0 && !choosed[i-1]) {
					if (a[i] >= a[i-1]) {
						clst.push_back(a[i]);
						choosed[i] = true;
					}
					else {
						clst.push_back(a[i-1]);
						choosed[i-1] = true;
					}
				}
			}
		}
		bool ok = true;
		if (clst.empty()) ok = false;
		else {
			sort(all(clst));
			int cnt = clst.size();
			if (clst[(cnt+1)/2-1] < ci) ok = false;
		}
		if (ok) li = ci;
		else ri = ci;
	}
	cout << li << endl;
	return 0;
}
