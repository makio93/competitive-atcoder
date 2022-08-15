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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> p(2*n);
	rep(i, 2*n) cin >> p[i];
	vector<int> res;
	for (int i=0; i<2*n; i+=2) {
		if (p[i+1] < p[i]) {
			if (i+3 < 2*n) {
				if (p[i+3] < p[i+2]) {
					if (p[i+2]>p[i] && p[i+1]<p[i+2] && p[i+3]>p[i+1]) {
						res.push_back(i+2);
						swap(p[i+1], p[i+2]);
					}
					else if (p[i+2] > p[i]) {
						res.push_back(i+1);
						res.push_back(i+3);
						swap(p[i], p[i+1]);
						swap(p[i+2], p[i+3]);
					}
					else {
						res.push_back(i+1);
						swap(p[i], p[i+1]);
					}
				}
				else {
					if (p[i+2] > p[i]) {
						res.push_back(i+2);
						swap(p[i+1], p[i+2]);
					}
					else {
						res.push_back(i+1);
						swap(p[i], p[i+1]);
					}
				}
			}
			else {
				res.push_back(i+1);
				swap(p[i], p[i+1]);
			}
		}
		else {
			if (i+3 < 2*n) {
				if (p[i+3] < p[i+2]) {
					if (p[i+3] < p[i+1]) {
						res.push_back(i+3);
						swap(p[i+2], p[i+3]);
					}
					else {
						res.push_back(i+2);
						swap(p[i+1], p[i+2]);
					}
				}
				else {
					if (p[i+2] > p[i+1]) {
						res.push_back(i+2);
						swap(p[i+1], p[i+2]);
					}
				}
			}
		}
	}
	int k = res.size();
	cout << k << endl;
	rep(i, k) cout << res[i] << (i<k-1?' ':'\n');
	return 0;
}
