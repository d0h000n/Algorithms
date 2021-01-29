/* README first!!
 This is basic Segment Tree.
 이것은 기본적인 구간 트리입니다.
 
 First index number is 1.
 시작 인덱스는 1입니다.
 
 using namespace std와 iostream, vector, climits, string, functional, cmath의 인클루드를 가정합니다.
 using namespace std and including iostream, vector, climits, string, functional, cmath is a prerequisite.
 
 It supports Query Operation, Update Operation and Clear Operation.
 이는 쿼리 연산, 갱신 연산, 비우기 연산을 지원합니다.
 
 If array's size is not the power of two, initialize them into identity of the operation.
 배열의 크기가 2의 거듭제곱이 아니라면 남는 자리에 연산에 대한 항등원들로 초기화합니다.
 
 Created by 김도훈 on 2021/01/24.
 Copyright © 2021 김도훈. All rights reserved.
 */

#define fctr const T& a, const T& b
template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    T id;
    function<T(fctr)> op;
    void setting(string s) {
        if (s == "max") {op = [](fctr) {return max(a, b);}; id = numeric_limits<T>::min();}
        else if (s == "min") {op = [](fctr) {return min(a, b);}; id = numeric_limits<T>::max();}
        else if (s == "sum") {op = [](fctr) {return a+b;}; id = 0;}
        else cerr << "There is No Operation \""+s+"\"!\n";
    }
    T _query(int s, int e) {
        T q = id;
        for (s += n, e += n; s <= e; s >>= 1, e >>= 1) {
            if (s%2 == 1) q = op(q, tree[s++]);
            if (e%2 == 0) q = op(q, tree[e--]);
        }
        return q;
    }
    void _update(int k, T x) {
        tree[k+n] = x;
        for (int i = (k+n)/2; i >= 1; i >>= 1)
             tree[i] = op(tree[2*i], tree[2*i+1]);
    }
public:
    SegmentTree(T* s, T* e, string x) {
        n = 1<<int(ceil(log2(e-s))); setting(x);
        tree.assign(2*n, id);
        for (auto it = s; it != e; ++it) tree[it-s+n] = *it;
        for (int i = n-1; i > 0; --i) tree[i] = op(tree[2*i], tree[2*i+1]);
    }
    inline void clear() {fill(tree.begin(), tree.end(), id);}
    inline T query(int s, int e) {return _query(s-1, e-1);}
    inline void update(int k, T x) {return _update(k-1, x);}
};
