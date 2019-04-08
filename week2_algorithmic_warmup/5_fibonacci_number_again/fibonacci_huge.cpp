#include <iostream>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_pisano_period(long long m){
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++){
        c = (a + b) % m;
        a = b;
        b = c;
        //std :: cout << i << '\n';
        if (a == 0 && b == 1)
            return (long long)(i+1);
    }
}

long long get_fibonacci_huge_fast(long long n, long long m){
    long long period = get_pisano_period(m);
    //cout << period << endl;
    long long num = n % period;
    //cout << num << endl;

    long long a = 0;
    long long b = 1;
    long long res = num;

    for (int i = 1; i < num; i++){
        res = (a+b)%m;
        a = b;
        b = res;
    }

    return res%m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //get_fibonacci_huge_fast(n, m);
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    //std::cout << get_pisano_period(m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
