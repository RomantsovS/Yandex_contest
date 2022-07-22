#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum(int i) {
    int sum = 0;

    while(i > 0) {
        sum += i % 10;
        i /= 10;
    }

    return sum;
}

int f() {
    vector<size_t> vec(1'000000, 0);

    for(size_t i = 1; i < 1'000'000; ++i) {
        double k = (3.0 * i / (sum(i) * sum(i)));

        if(k - int(k) == 0)
            vec[k] = i;

    }

    for(size_t i = 0; i < 100; ++i)
        cout << i << ' ' << vec[i] << endl;

    return 0;
}

int main() {
    f();

    return 0;
}