struct BigInteger {
    bool sign;
    std::string s;
    BigInteger(): sign(0), s("0") {}
    void parsing(const string &x) {
        if (x[0] == '+') {
            sign = false;
            s = x.substr(1,x.size()-1);
        } else if (x[0] == '-') {
            sign = true;
            s = x.substr(1,x.size()-1);
        } else s = x;
    }
    BigInteger(int64_t x) { parsing(to_string(x)); }
    // 더하기 빼기 곱하기 나누기 나머지 -> 나머지는 오버로딩 되겠지 뭥
    friend long long log10(BigInteger &x) { assert(x > 0); return x.s.size()-1; }
    bool operator == (const BigInteger &rhs) { return s == rhs.s; }
    bool operator != (const BigInteger &rhs) { return s != rhs.s; }
    friend bool operator < (const BigInteger &x, const BigInteger &y) {
        if (x.s.size() == y.s.size()) {
            for (int i = 0; i < int(x.s.size()); ++i) {
                if (x.s[i] == y.s[i]) continue;
                return x.s[i] < y.s[i];
            }
        }
        return x.s.size() < y.s.size();
    }
    friend bool operator > (const BigInteger &x, const BigInteger &y) { return y < x; }
    friend bool operator <= (const BigInteger &x, const BigInteger &y) { return not (y > x); }
    friend bool operator >= (const BigInteger &x, const BigInteger &y) { return not (y < x); }
    friend string to_string(const BigInteger &x) { return x.sign ? "-"+x.s : x.s; }
    friend istream &operator >> (istream &i, BigInteger &x) { return i >> x.s; }
    friend ostream &operator << (ostream &o, BigInteger x) { return o << x.s; }
};
