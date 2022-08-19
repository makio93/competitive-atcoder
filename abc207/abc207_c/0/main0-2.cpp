// 本番AC

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n), al(n), ar(n);
	rep(i, n) {
		int ti;
		cin >> ti >> l[i] >> r[i];
		if (ti == 2) { r[i]--; ar[i] = 1; }
		if (ti == 3) { l[i]++; al[i] = 1; } 
		if (ti == 4) { l[i]++; r[i]--; al[i] = 1; ar[i] = 1; }
	}
	ll res = 0;
	rep(i, n) {
		rep3(j, i+1, n) {
			if ((l[i]<=r[j]&&r[i]>=l[j]) || (l[j]<=r[i]&&r[j]>=l[i])) ++res;
			else if (r[i]+1==l[j] && ar[i]==1 && al[j]==1) ++res;
			else if (r[j]+1==l[i] && ar[j]==1 && al[i]==1) ++res;
		}
	}
	cout << res << endl;
	return 0;
}
