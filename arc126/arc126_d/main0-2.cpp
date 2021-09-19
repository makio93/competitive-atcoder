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

// 本番,未完成

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
	vector<vector<int>> tid(k);
	rep(i, k) {
		int di = distance(vid[i].begin(), upper_bound(all(vid[i]), lval+i));
		int vlen = vid[i].size();
		pair<int, int> tmp = { (int)(1e9), (int)(1e9) };
		if (di < vlen) {
			tmp = min(tmp, { abs(vid[i][di]-(lval+i)), vid[i][di] });
			tid[i].push_back(tmp.second);
		}
		if (di-1 >= 0) {
			if (tmp.first == abs(vid[i][di-1]-(lval+i))) {
				tid[i].push_back(tmp.second);
				tid[i].push_back(vid[i][di-1]);
			}
			else {
				tmp = min(tmp, { abs(vid[i][di-1]-(lval+i)), vid[i][di-1] });
				tid[i].push_back(tmp.second);
			}
		}
	}
	int onum = 1;
	rep(i, k) onum *= (int)(tid[i].size());
	ll res = (ll)(1e15);
	rep(i, onum) {
		vector<int> kid(k);
		int ival = i;
		vector<int> tar1(n, -1);
		rep(j, k) {
			tar1[tid[j][ival%(int)(tid[j].size())]] = lval + i;
			ival /= (int)(tid[j].size());
		}
		int nid = 0;
		rep(i, n) {
			if (tar1[i] == -1) {
				if (nid == lval) nid = lval + k;
				tar1[i] = nid;
				++nid;
			}
		}
		ll tres = 0;
		vector<pair<int, int>> uid(n);
		rep(i, n) uid[i] = { tar1[i], i };
		sort(all(uid));
		set<int> ust;
		ust.insert(-1);
		rep(i, n) {
			int sval = distance(ust.begin(), ust.upper_bound(uid[i].second));
			tres += (i+1) - sval;
			ust.insert(uid[i].second);
		}
		res = min(res, tres);
	}
	cout << res << endl;
	return 0;
}
