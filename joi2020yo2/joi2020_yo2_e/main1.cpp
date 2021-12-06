#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const ll mod = (ll)(1e9) + 7;

const string hands = "RSP";
const string ops = "+-*";
const vector<vector<vector<int>>> results = {
    {
        { 0, 0, 2 }, 
        { 0, 1, 1 }, 
        { 2, 1, 2 }
    },
    {
        { 0, 1, 0 },
        { 1, 1, 2 },
        { 0, 2, 2 }
    },
    {
        { 0, 2, 1 },
        { 2, 1, 0 },
        { 1, 0, 2 }
    }
};

int n, pos;
string e;
char a;

vector<ll> factor();
vector<ll> term();
vector<ll> expression();

vector<ll> mul(vector<ll>& a, vector<ll>& b, char c) {
    int cid = -1;
    rep(i, 3) if (c == ops[i]) cid = i;
    vector<ll> res = { 0, 0, 0 };
    rep(i, 3) rep(j, 3) res[results[cid][i][j]] = (res[results[cid][i][j]] + a[i] * b[j] % mod) % mod;
    return res;
}

vector<ll> factor() {
    vector<ll> res = { 0, 0, 0 };
    if (pos >= n) return res;
    if (hands.find(e[pos]) != string::npos) {
        int hid = -1;
        rep(i, 3) if (e[pos] == hands[i]) hid = i;
        res[hid] = 1;
        ++pos;
    }
    else if (e[pos] == '?') {
        rep(i, 3) res[i] = 1;
        ++pos;
    }
    else if (e[pos] == '(') {
        ++pos;
        res = expression();
        ++pos;
    }
    return res;
}

vector<ll> term() {
    vector<ll> res = { 0, 0, 0 };
    if (pos >= n) return res;
    res = factor();
    while (e[pos] == '*') {
        ++pos;
        auto tres = factor();
        res = mul(res, tres, '*');
    }
    return res;
}

vector<ll> expression() {
    vector<ll> res = { 0, 0, 0 };
    if (pos >= n) return res;
    res = term();
    while (e[pos]=='+' || e[pos]=='-') {
        char op = e[pos];
        ++pos;
        auto tres = term();
        res = mul(res, tres, op);
    }
    return res;
}

int main() {
    cin >> n >> e >> a;
    e.push_back('.');
    pos = 0;
    auto res = expression();
    cout << res[hands.find(a)] << endl;
    return 0;
}
