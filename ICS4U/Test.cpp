#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main_test()
{
    int value = 5;
    int* ptr = &value;
    std::cout << &ptr;
    return 0;
}