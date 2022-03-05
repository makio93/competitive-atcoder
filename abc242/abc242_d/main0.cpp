// 本番AC

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

int main() {
	string s;
	cin >> s;
	const string tar = "ABC";
	function<char(ll,ll)> calc = [&](ll ti, ll ki) -> char {
		if (ti == 0) return s[(int)ki];
		else if (ki == 0) return tar[((s[0]-'A')+ti)%3];
		else {
			if (ki%2 == 0) return tar[(calc(ti-1, ki/2)-'A'+1)%3];
			else return tar[(calc(ti-1, ki/2)-'A'+2)%3];
		}
	};
	int q;
	cin >> q;
	rep(i, q) {
		ll ti, ki;
		cin >> ti >> ki;
		--ki;
		cout << calc(ti, ki) << endl;
	}
	return 0;
}
