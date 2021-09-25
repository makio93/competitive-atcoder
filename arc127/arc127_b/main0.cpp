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

// 本番AC

int main() {
	int n, l;
	cin >> n >> l;
	vector<string> res;
	if (l == 1) {
		rep(i, 3) res.push_back(string(1, (char)(i+'0')));
		rep(i, 3*n) cout << res[i] << endl;
		return 0;
	}
	int nval = 0;
	rep(i, n) {
		string si2, si0, si1;
		int tval = nval;
		rep(j, l-1) {
			si2 += (char)((tval%3)+'0');
			tval /= 3;
		}
		si2 += '2';
		reverse(all(si2));
		si0 = si2;
		rep(j, l) si0[j] = (char)((((int)(si0[j]-'0')+1)%3) + '0');
		si1 = si0;
		rep(j, l) si1[j] = (char)((((int)(si1[j]-'0')+1)%3) + '0');
		res.push_back(si2);
		res.push_back(si0);
		res.push_back(si1);
		++nval;
	}
	rep(i, n*3) cout << res[i] << endl;
	return 0;
}
