#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力解答3回目、やっぱりできない

const ll mod = (1e9) + 7;

struct mint {
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    /*
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
    */
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int w;
vector<vector<int>> board;
vector<vector<mint>> dp;

void calc(vector<vector<mint>>& ndp, int hi, int wi=0, mint cnt=1, string pkey="0", string skey="0") {
    int pid = (int)((char)(pkey.back()) - '0'), sid = (int)((char)(skey.back()) - '0');
    mint tar = (wi > 0) ? (cnt * dp[wi][pid]) : 1;
    ndp[wi][sid] += tar;
    if (wi < w) {
        calc(ndp, hi, wi+1, tar, pkey+'0', skey+'0');
        if (pid==0 && sid==0) {
            if (board[hi-1][wi+1] == 1) calc(ndp, hi, wi+1, tar, pkey+'1', skey+'0');
            if (board[hi][wi+1] == 1) calc(ndp, hi, wi+1, tar, pkey+'0', skey+'1');
        }
    }
}

int main() {
    int h;
    cin >> h >> w;
    vector<string> c(h);
    board = vector<vector<int>>(h+1, vector<int>(w+1, -1));
    rep(i, h) {
        cin >> c[i];
        rep(j, w) {
            if (c[i][j] == '.') board[i+1][j+1] = 1;
            else board[i+1][j+1] = 0;
        }
    }
    dp = vector<vector<mint>>(w+1, vector<mint>(2));
    rep(i, w+1) dp[i][0] = 1;
    rep3(i, 1, h+1) {
        vector<vector<mint>> ndp(w+1, vector<mint>(2));
        calc(ndp, i);
        swap(dp, ndp);
    }
    cout << (dp[w][0]+dp[w][1]) << endl;
    return 0;
}
