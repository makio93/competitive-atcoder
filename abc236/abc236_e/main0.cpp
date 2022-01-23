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

// 本番WA

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<map<int, pair<ll, int>>> dp(n+1);
	dp[0][0] = { 0, 0 };
	dp[1][1] = { a[0], 1 };
	function<bool(pair<ll,int>,pair<ll,int>)> comp = [](pair<ll,int> api, pair<ll,int> bpi) -> bool {
		if (api.second==0 && bpi.second==0) return true;
		else if (api.second == 0) return false;
		else if (bpi.second == 0) return true;
		else return (api.first/(double)api.second >= bpi.first/(double)bpi.second);
	};
	rep3(i, 1, n) {
		for (auto pi : dp[i]) {
			if (comp(make_pair(pi.second.first+a[i], pi.second.second+1), dp[i+1][pi.second.second+1])) {
				dp[i+1][pi.second.second+1] = make_pair(pi.second.first+a[i], pi.second.second+1);
			}
		}
		for (auto pi : dp[i-1]) {
			if (comp(make_pair(pi.second.first+a[i], pi.second.second+1), dp[i+1][pi.second.second+1])) {
				dp[i+1][pi.second.second+1] = make_pair(pi.second.first+a[i], pi.second.second+1);
			}
		}
	}
	map<int, pair<ll, int>> res1;
	for (auto pi : dp[n-1]) if (comp(pi.second, res1[pi.second.second])) res1[pi.second.second] = pi.second;
	for (auto pi : dp[n]) if (comp(pi.second, res1[pi.second.second])) res1[pi.second.second] = pi.second;
	double resa = res1.begin()->second.first / (double)res1.begin()->second.second;
	for (auto pi : res1) resa = max(resa, pi.second.first/(double)pi.second.second);
	printf("%.10f\n", resa);
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
