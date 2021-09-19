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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> vid(k);
	rep(i, n) vid[a[i]].push_back(i);
	vector<int> cval(k);
	rep(i, k) {
		sort(all(vid[i]));
		int vlen = vid[i].size();
		if (vlen%2 == 0) cval[i] = vid[i][vlen/2] + vid[i][vlen/2-1];
		else cval[i] = vid[i][vlen/2] * 2;
	}
	ll csum = 0;
	rep(i, k) csum += cval[i];
	ll lval = ((csum+k-1)/k - (k-1)) / 2;
	vector<int> tid(k);
	rep(i, k) {
		int di = distance(vid[i].begin(), upper_bound(all(vid[i]), lval+i));
		int vlen = vid[i].size();
		pair<int, int> tmp = { (int)(1e9), (int)(1e9) };
		if (di < vlen) tmp = min(tmp, { abs(vid[i][di]-(lval+i)), vid[i][di] });
		if (di-1 >= 0) {
			if (tmp.first == abs(vid[i][di-1]-(lval+i))) {
				if (i >= k/2) tmp.second = vid[i][di-1];
			}
			else tmp = min(tmp, { abs(vid[i][di-1]-(lval+i)), vid[i][di-1] });
		}
		tid[i] = tmp.second;
	}
	vector<int> tar1(n, -1);
	rep(i, k) tar1[tid[i]] = lval + i;
	int nid = 0;
	rep(i, n) {
		if (tar1[i] == -1) {
			if (nid == lval) nid = lval + k;
			tar1[i] = nid;
			++nid;
		}
	}
	vector<pair<int, int>> uid(n);
	rep(i, n) uid[i] = { tar1[i], i };
	sort(all(uid));
	set<int> ust;
	ust.insert(-1);
	ll res = 0;
	rep(i, n) {
		int sval = distance(ust.begin(), ust.upper_bound(uid[i].second));
		res += (i+1) - sval;
		ust.insert(uid[i].second);
	}
	cout << res << endl;
	return 0;
}
