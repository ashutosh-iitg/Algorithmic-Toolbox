#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    // write your code here
    int fibList[n+1];
    fibList[0] = 0;
    fibList[1] = 1;
    for (int i = 2; i <= n; i++){
        fibList[i] = (fibList[i-1] + fibList[i-2])%10;
    }

    return fibList[n];
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
