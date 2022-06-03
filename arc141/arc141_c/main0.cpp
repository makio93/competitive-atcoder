// 本番WA

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
	vector<int> p(n*2), q(n*2);
	rep(i, n*2) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n*2) {
		cin >> q[i];
		q[i]--;
	}
	bool ok = true;
	if (p > q) {
		ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	string pstr(n*2, '.'), qstr(n*2, '.');
	pstr[0] = '('; pstr[n*2-1] = ')';
	rep(i, n*2) {
		if (p[i] == q[0]) {
			if (pstr[i] == ')') {
				ok = false;
				break;
			}
			else pstr[i] = '(';
		}
		if (p[i] == q[n*2-1]) {
			if (pstr[i] == '(') {
				ok = false;
				break;
			}
			else pstr[i] = ')';
		}
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> vals(n*2+1);
	rep(i, n*2) {
		if (pstr[i] == '.') {
			if (i+1<n*2 && pstr[i+1]==')' && vals[i]-2<0) pstr[i] = '(';
			else if (vals[i]-1 >= 0) {
				pstr[i] = ')';
				if (p[i-1]>p[i] && vals[i]-2>=0) {
					ok = false;
					break;
				}
			}
			else pstr[i] = '(';
		}
		vals[i+1] += vals[i] + (pstr[i]=='(' ? 1 : -1);
		if (vals[i+1] < 0) {
			ok = false;
			break;
		}
	}
	if (vals[n*2] != 0) ok = false;
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> rqid(n*2);
	rep(i, n*2) rqid[q[i]] = i;
	rep(i, n*2) qstr[rqid[p[i]]] = pstr[i];
	vector<int> qvals(n*2+1);
	rep(i, n*2) {
		if (qstr[i]==')' && q[i-1]<q[i] && qvals[i]-2>=0) {
			ok = false;
			break;
		}
		qvals[i+1] += qvals[i] + (qstr[i]=='(' ? 1 : -1);
		if (qvals[i+1] < 0) {
			ok = false;
			break;
		}
	}
	if (qvals[n*2] != 0) ok = false;
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	string res(n*2, '.');
	rep(i, 2*n) res[p[i]] = pstr[i];
	cout << res << endl;
	return 0;
}
