/*
만약 C++20을 이용하고 계시다면 필요없는 이야기입니다.
numeric 헤더를 인클루드하면 내장 gcd 함수가 딸려오기 때문이죠.
*/
template <typename T>
inline T gcd(const T& a, const T& b) {return b ? gcd(b, a%b) : a;}
