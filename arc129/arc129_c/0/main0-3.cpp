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

// 本番WA3

int main() {
	int n;
	cin >> n;
	vector<int> lens;
	bool sig = false;
	for (int i=1; i*i<=n*2; ++i) if (i*(i+1)/2 == n) {
		sig = true;
		lens.push_back(i);
		break;
	}
	if (!sig) {
		for (int i=1; i*(i+1)/2<n; ++i) for (int j=1; j*(j+1)/2<=n-i*(i+1)/2; ++j) {
			if (i*(i+1)/2+j*(j+1)/2 == n) {
				sig = true;
				lens.push_back(i);
				lens.push_back(j);
				break;
			}
		}
	}
	if (!sig) {
		for (int i=1; i*(i+1)/2<n; ++i) for (int j=1; j*(j+1)/2<n-i*(i+1)/2; ++j) {
			int k = ((int)round(sqrt((n-i*(i+1)/2-j*(j+1)/2)*2))) - 1;
			while ((k+1)*(k+2)/2 <= n-i*(i+1)/2-j*(j+1)/2) ++k;
			if (i*(i+1)/2+j*(j+1)/2+k*(k+1)/2 == n) {
				sig = true;
				lens.push_back(i);
				lens.push_back(j);
				lens.push_back(k);
				break;
			}
		}
	}
	if (!sig) {
		for (int i=1; i*(i+1)/2<n; ++i) for (int j=1; j*(j+1)/2<n-i*(i+1)/2; ++j) for (int k=1; k*(k+1)/2<n-i*(i+1)/2-j*(j+1)/2; ++k) {
			int h = ((int)round(sqrt((n-i*(i+1)/2-j*(j+1)/2-k*(k+1)/2)*2))) - 1;
			while ((h+1)*(h+2)/2 <= n-i*(i+1)/2-j*(j+1)/2-k*(k+1)/2) ++h;
			if (i*(i+1)/2+j*(j+1)/2+k*(k+1)/2+h*(h+1)/2 == n) {
				sig = true;
				lens.push_back(i);
				lens.push_back(j);
				lens.push_back(k);
				lens.push_back(h);
				break;
			}
		}
	}
	string s;
	if (lens.size() == 1) {
		s += string(lens[0], '7');
	}
	else {
		s += string(lens[0], '7');
		int llen = lens.size();
		rep3(i, 1, llen) {
			int tval = (6 - lens[i-1] % 6) % 6, r = 1;
			rep(j, tval) r = r * 3 % 7;
			s += (char)(r+'0');
			s += string(lens[i], '7');
		}
	}
	reverse(all(s));
	cout << s << endl;
	return 0;
}
