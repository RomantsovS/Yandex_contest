#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string f(istream& is) {
    size_t n;
    is >> n;

    size_t p = 0;
    size_t v = 0;

    size_t p_val = 0;
    size_t v_val = 0;

    for (size_t i = 0; i < n; i += 3) {
        is >> p_val;
        p += p_val;

        is >> v_val;
        v += v_val;

        if (p_val < v_val) {
            is >> p_val;
            p += p_val;
        } else {
            is >> v_val;
            v += v_val;
        }
    }

    return p_val > v_val ? "Petya" : "Vasya";
}

int main() {
    if (true) {
        {
            istringstream iss(R"(3
1 2 3
)");
            assert((f(iss) == "Petya"));
        }

        {
            istringstream iss(R"(3
1 4 2
)");
            assert((f(iss) == "Vasya"));
        }

        cout << "ok\n";
    } else {
        cout << f(cin);
    }

    return 0;
}