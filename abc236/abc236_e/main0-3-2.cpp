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

// ヒント付きで自力考察,誤答2

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<pair<ll, int>>> dp(n+1, vector<pair<ll, int>>(2, make_pair(0LL, 0)));
	dp[1][1] = { a[0], 1 };
	function<bool(pair<ll,int>,pair<ll,int>)> comp = [&n](pair<ll,int> api, pair<ll,int> bpi) -> bool {
		if (api.second==0 && bpi.second==0) return true;
		else if (api.second == 0) return false;
		else if (bpi.second == 0) return true;
		else {
			double aval = api.first/(double)api.second, bval = bpi.first/(double)bpi.second;
			return (api.first+aval*(n-api.second) >= bpi.first+bval*(n-bpi.second));
		}
	};
	rep3(i, 1, n) {
		if (comp(make_pair(dp[i][0].first+a[i],dp[i][0].second+1), make_pair(dp[i][1].first+a[i],dp[i][1].second+1))) {
			dp[i+1][1] = make_pair(dp[i][0].first+a[i], dp[i][0].second+1);
		}
		else dp[i+1][1] = make_pair(dp[i][1].first+a[i], dp[i][1].second+1);
		dp[i+1][0] = dp[i][1];
	}
	pair<ll, int> rval = { 0LL, 0 };
	rep3(i, n-1, n+1) rep(j, 2) if (comp(dp[i][j], rval)) rval = dp[i][j];
	printf("%.10f\n", rval.first/(double)rval.second);
	multiset<int> st1, st2;
	st1.insert(a[0]); st1.insert(a[1]);
	st2.insert(a[0]);
	auto mitr1 = st1.find(max(a[0], a[1])), mitr2 = st2.find(a[0]);
	rep3(i, 2, n) {
		int nval1 = -1, nval2 = -1;
		if (a[i] >= *mitr1) {
			if ((int)(st1.size())%2 == 1) {
				if ((int)(st1.size()) <= 1) nval1 = a[i];
				else nval1 = min(*next(mitr1), a[i]);
			}
			else nval1 = *mitr1;
		}
		else {
			if ((int)(st1.size())%2 == 1) nval1 = *mitr1;
			else nval1 = max(*prev(mitr1), a[i]);
		}
		if (a[i] >= *mitr2) {
			if ((int)(st2.size())%2 == 1) {
				if ((int)(st2.size()) <= 1) nval2 = a[i];
				else nval2 = min(*next(mitr2), a[i]);
			}
			else nval2 = *mitr2;
		}
		else {
			if ((int)(st2.size())%2 == 1) nval2 = *mitr2;
			else nval2 = max(*prev(mitr2), a[i]);
		}
		if (nval1 >= nval2) {
			if (a[i-1] >= *mitr2) {
				if ((int)(st2.size())%2 == 1) {
					if ((int)(st2.size()) <= 1) st2.insert(a[i-1]);
					else {
						st2.insert(a[i-1]);
						mitr2++;
					}
				}
				else st2.insert(a[i-1]);
			}
			else {
				if ((int)(st2.size())%2 == 1) st2.insert(a[i-1]);
				else {
					st2.insert(a[i-1]);
					mitr2--;
				}
			}
			if (a[i] >= *mitr1) {
				if ((int)(st1.size())%2 == 1) {
					if ((int)(st1.size()) <= 1) st1.insert(a[i]);
					else {
						st1.insert(a[i]);
						mitr1++;
					}
				}
				else st1.insert(a[i]);
			}
			else {
				if ((int)(st1.size())%2 == 1) st1.insert(a[i]);
				else {
					st1.insert(a[i]);
					mitr1--;
				}
			}
		}
		else {
			if (a[i] >= *mitr2) {
				if ((int)(st2.size())%2 == 1) {
					if ((int)(st2.size()) <= 1) st2.insert(a[i]);
					else {
						st2.insert(a[i]);
						mitr2++;
					}
				}
				else st2.insert(a[i]);
			}
			else {
				if ((int)(st2.size())%2 == 1) st2.insert(a[i]);
				else {
					st2.insert(a[i]);
					mitr2--;
				}
			}
			swap(st1, st2);
			swap(mitr1, mitr2);
		}
	}
	cout << max(*mitr1, *mitr2) << endl;
	return 0;
}
