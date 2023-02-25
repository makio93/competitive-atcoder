// 本番WA1

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
	int n, k;
	string s;
	cin >> n >> k >> s;
	int xcnt = count(all(s), 'X'), res = 0;
	if (xcnt == k) res = n - 1;
	else if (xcnt > k) {
		vector<int> lsum(n), rsum(n);
		rep3(i, 1, n) {
			if (s[i-1]=='Y' && s[i]=='Y') lsum[i] = lsum[i-1] + 1;
			else lsum[i] = lsum[i-1];
		}
		repr(i, n-1) {
			if (s[i+1]=='Y' && s[i]=='Y') rsum[i] = rsum[i+1] + 1;
			else rsum[i] = rsum[i+1];
		}
		int li = -1, tcnt = 0;
		rep(ri, n) {
			if (s[ri] == 'X') ++tcnt;
			while (tcnt>k && li<ri) {
				if (s[li+1] == 'X') --tcnt;
				++li;
			}
			res = max(res, max(0, ri-li-1) + (li>=0?lsum[li]:0) + (ri+1<n?rsum[ri+1]:0));
		}
	}
	else {
		rep(i, n) if (s[i] == 'X') s[i] = 'V';
		k -= xcnt;
		int li = 0, tcnt = 0, vcnt = 0;
		rep(ri, n) {
			if (s[ri] == 'Y') ++tcnt;
			if (s[ri]=='V' && ri-1>=li && s[ri-1]=='V') ++vcnt;
			if (tcnt > k) {
				while (s[li] != 'Y') {
					if (li+1<=ri && s[li+1]!='Y') --vcnt;
					++li;
				}
				++li; --tcnt;
			}
			if (tcnt == k) {
				while (s[li] != 'Y') {
					if (li+1<=ri && s[li+1]!='Y') --vcnt;
					++li;
				}
				res = max(res, vcnt+max(0,li-1)+max(0,n-ri-2));
			}
		}
	}
	cout << res << endl;
	return 0;
}
