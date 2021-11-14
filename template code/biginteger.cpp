#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cerr << #x << " is " << x << endl
#define el '\n'
using namespace std; using ll = long long;

struct BigInteger {
    bool sign; string s;
    BigInteger(): sign(0), s("0") {}
    void parsing(const string &x) {
        if (x[0] == '+') {
            sign = false;
            s = x.substr(1,x.size()-1);
        } else if (x[0] == '-') {
            sign = true;
            s = x.substr(1,x.size()-1);
            if (s == "0") sign = false;
        } else {
            sign = false;
            s = x;
        }
    }
    BigInteger(int64_t x) { parsing(to_string(x)); }
    // 더하기 빼기 곱하기 나누기 나머지 -> 나머지는 오버로딩 되겠지 뭥
    BigInteger &operator - () { sign ^= 1; return *this; }
    friend long long log10(BigInteger &x) { assert(x > 0); return x.s.size()-1; }
    bool operator == (const BigInteger &rhs) {
        if (s == "0" and rhs.s == "0") return true;
        return s == rhs.s;
    }
    bool operator != (const BigInteger &rhs) { return not (*this == rhs); }
    friend bool operator < (const BigInteger &x, const BigInteger &y) {
        if (x.sign == false and y.sign == false) {
            if (x.s.size() == y.s.size()) {
                for (size_t i = 0; i < x.s.size(); ++i) {
                    if (x.s[i] == y.s[i]) continue;
                    return x.s[i] < y.s[i];
                }
            }
            return x.s.size() < y.s.size();
        } else if (x.sign == false and y.sign == true) {
            if (x.s == "0" and y.s == "0") return false;
            return false;
        }
        else if (x.sign == true and y.sign == false) {
            if (x.s == "0" and y.s == "0") return false;
            return true;
        }
        else {
            if (x.s.size() == y.s.size()) {
                for (size_t i = 0; i < x.s.size(); ++i) {
                    if (x.s[i] == y.s[i]) continue;
                    return x.s[i] > y.s[i];
                }
            }
            return x.s.size() > y.s.size();
        }
    }
    friend bool operator > (const BigInteger &x, const BigInteger &y) { return y < x; }
    friend bool operator <= (const BigInteger &x, const BigInteger &y) { return not (y > x); }
    friend bool operator >= (const BigInteger &x, const BigInteger &y) { return not (y < x); }
    friend string to_string(const BigInteger &x) { return x.sign ? "-"+x.s : x.s; }
    friend istream &operator >> (istream &i, BigInteger &x) {
        string tmp; i >> tmp;
        x.parsing(tmp);
        return i;
    }
    friend ostream &operator << (ostream &o, const BigInteger &x) {
        if (x.sign) o << '-';
        return o << x.s;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    BigInteger x = 11;
    cout << BigInteger(-11) << ' ' << x << el;
    cout << (BigInteger(+0) > BigInteger(-0) ? "True" : "False") << el;
}
