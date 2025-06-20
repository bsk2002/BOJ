#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n, k;

/**
 * 페르마의 소정리 활용
 * P가 소수일 때
 * A^(P-1) mod P = 1
 * A^(P-2) mod P = A^(-1)
 *
 * 따라서 A/B를 modulo 연산의 분배법칙을 활용하려면 페르마의 소정리를 이용,
 * A/B mod P = AB^(-1) mod P = AB^(P-2) mod P
 * = ((A mod P) * (B^(P-2) mod P)) mod P
 */
ll power(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b % 2) res = (res * a) % mod;

        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main() {
    cin >> n >> k;
    ll a = 1, b = 1;

    for (int i = n; i >= n - k + 1; i--) a = (a * i) % mod;
    for (int i = 1; i <= k; i++) b = (b * i) % mod;

    cout << (a * power(b, mod - 2)) % mod;
}
