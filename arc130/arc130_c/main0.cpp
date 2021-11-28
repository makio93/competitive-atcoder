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

const int CNT = (4e6);
int cnt;
string a, b;
int n, m;
map<int, int> acnt, bcnt;
string ta, tb;
pair<int, pair<string, string>> res;
bool calc(int d=0, int av=0) {
	if (d == max(n, m)) {
		int len1 = min(n, m), len2 = max(n, m);
		int add = 0, val = 0;
		rep(i, len1) {
			int tval = (ta[n-i-1]-'0') + (tb[m-i-1]-'0') + add;
			val += tval % 10;
			add = tval / 10;
		}
		rep3(i, len1, len2) {
			int tval = add;
			if (n >= m) tval += (ta[n-i-1]-'0');
			else tval += (tb[m-i-1]-'0');
			val += tval % 10;
			add = tval / 10;
		}
		val += add;
		res = min(res, { val, { ta, tb } });
		++cnt;
		return true;
	}
	else if (d >= min(n, m)) {
		bool nres = false;
		if (n >= m) {
			auto aitr = acnt.lower_bound((10-av)%10);
			if (aitr == acnt.end()) aitr = acnt.begin();
			int tv = aitr->first;
			acnt[tv]--;
			if (acnt[tv] == 0) acnt.erase(tv);
			ta[n-d-1] = (char)(tv + '0');
			int add = (av + tv) / 10;
			if ((av+tv)%10 == 0) nres = true;
			bool cres = calc(d+1, add);
			ta[n-d-1] = '.';
			acnt[tv]++;
			if ((cnt>CNT) || (cres&&nres)) return true;
			rep3(i, 1, 10) if (acnt.find((tv+i)%10) != acnt.end()) {
				int ntv = (tv+i)%10;
				acnt[ntv]--;
				if (acnt[ntv] == 0) acnt.erase(ntv);
				ta[n-d-1] = (char)(ntv + '0');
				int nadd = (av + ntv) / 10;
				if ((av+ntv)%10 == 0) nres = true;
				bool ncres = calc(d+1, nadd);
				ta[n-d-1] = '.';
				acnt[ntv]++;
				if ((cnt>CNT) || (ncres && nres)) return true;
			}
			return false;
		}
		else {
			auto bitr = bcnt.lower_bound((10-av)%10);
			if (bitr == bcnt.end()) bitr = bcnt.begin();
			int tv = bitr->first;
			bcnt[tv]--;
			if (bcnt[tv] == 0) bcnt.erase(tv);
			tb[m-d-1] = (char)(tv + '0');
			int add = (av + tv) / 10;
			if ((av+tv)%10 == 0) nres = true;
			bool cres = calc(d+1, add);
			tb[m-d-1] = '.';
			bcnt[tv]++;
			if ((cnt>CNT) || (cres && nres)) return true;
			rep3(i, 1, 10) if (bcnt.find((tv+i)%10) != bcnt.end()) {
				int ntv = (tv+i)%10;
				bcnt[ntv]--;
				if (bcnt[ntv] == 0) bcnt.erase(ntv);
				tb[m-d-1] = (char)(ntv + '0');
				int nadd = (av + ntv) / 10;
				if ((av+ntv)%10 == 0) nres = true;
				bool ncres = calc(d+1, nadd);
				tb[m-d-1] = '.';
				bcnt[ntv]++;
				if ((cnt>CNT) || (ncres && nres)) return true;
			}
			return false;
		}
	}
	else {
		int amx = 0;
		bool nres = false;
		if (d == 0) amx = acnt.rbegin()->first;
		else {
			auto aitr = acnt.lower_bound((10-av-bcnt.begin()->first+10)%10);
			if (aitr == acnt.end()) aitr = acnt.begin();
			amx = aitr->first;
		}
		rep(i, 10) if (acnt.find((amx+i)%10) != acnt.end()) {
			int atv = (amx + i) % 10;
			auto bitr = bcnt.lower_bound((10-av-atv+10)%10);
			if (bitr == bcnt.end()) bitr = bcnt.begin();
			int btv = bitr->first;
			acnt[atv]--; bcnt[btv]--;
			if (acnt[atv] == 0) acnt.erase(atv);
			if (bcnt[btv] == 0) bcnt.erase(btv);
			ta[n-d-1] = (char)(atv+'0');
			tb[m-d-1] = (char)(btv+'0');
			int add = (av+atv+btv) / 10;
			if ((av+atv+btv)%10 == 0) nres = true;
			bool cres = calc(d+1, add);
			ta[n-d-1] = '.'; tb[m-d-1] = '.';
			acnt[atv]++; bcnt[btv]++;
			if ((cnt>CNT) || (cres && nres)) return true;
		}
		return false;
	}
}

int main() {
	cin >> a >> b;
	n = a.length(); m = b.length();
	cnt = 0;
	rep(i, n) acnt[a[i]-'0']++;
	rep(i, m) bcnt[b[i]-'0']++;
	ta = string(n, '.'); tb = string(m, '.');
	res = { (int)(1e9), { "", "" } };
	calc();
	cout << res.second.first << endl;
	cout << res.second.second << endl;
	return 0;
}
