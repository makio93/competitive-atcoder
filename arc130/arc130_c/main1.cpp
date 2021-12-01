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

// 解説AC

const int INF = (int)(1e9);

int main() {
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	vector<int> acnt(10), bcnt(10);
	rep(i, n) acnt[a[i]-'0']++;
	rep(i, m) bcnt[b[i]-'0']++;
	tuple<int, string, string> mres = { INF, "", "" };
	rep3(i1, 1, 10) if (acnt[i1] > 0) {
		auto tacnt = acnt, tbcnt = bcnt;
		string ta, tb;
		tacnt[i1]--;
		ta += (char)(i1+'0');
		rep3(bi, max(1,10-i1), max(1,10-i1)+10) if (tbcnt[bi%10] > 0) {
			tbcnt[bi%10]--;
			tb += (char)(bi%10+'0');
			break;
		}
		rep3(ai, 1, 10) rep3(bi, max(1,9-ai), 10) {
			int tlen = min(tacnt[ai], tbcnt[bi]);
			if (tlen > 0) {
				tacnt[ai] -= tlen;
				tbcnt[bi] -= tlen;
				ta += string(tlen, (char)(ai+'0'));
				tb += string(tlen, (char)(bi+'0'));
			}
		}
		rep3r(ai, 1, 10) if (tacnt[ai] > 0) ta += string(tacnt[ai], (char)(ai+'0'));
		rep3r(bi, 1, 10) if (tbcnt[bi] > 0) tb += string(tbcnt[bi], (char)(bi+'0'));
		int mlen = max(ta.length(), tb.length());
		vector<int> dcnt(mlen+1);
		rep(i, mlen) {
			int val = dcnt[i] + (i<(int)(ta.length()) ? (ta[i]-'0') : 0) + (i<(int)(tb.length()) ? (tb[i]-'0') : 0);
			dcnt[i] = val % 10;
			dcnt[i+1] = val / 10;
		}
		int sum = 0;
		rep(i, mlen+1) sum += dcnt[i];
		reverse(all(ta));
		reverse(all(tb));
		mres = min(mres, { sum, ta, tb });
	}
	cout << get<1>(mres) << endl;
	cout << get<2>(mres) << endl;
	return 0;
}
