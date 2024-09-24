#include <iostream>
#include <algorithm>

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main_207b() {
    int N; std::cin >> N;
    std::cout << Fibonacci(N);
    return 0;
}