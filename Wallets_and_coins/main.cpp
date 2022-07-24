#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void f(istream& is, ostream& os) {
    int n;
    is >> n;

    size_t sum = 0;
    vector<size_t> vec(n);

    for (size_t i = 0; i < n; ++i) {
        is >> vec[i];
    }

    sort(vec.begin(), vec.end());
    is >> n;

    for (int i = n; i > 0; --i) {
        vector<size_t> v(n);
        for (int j = vec.size(); j > 0; --j) {
            if (vec[j] < n) {
                os << "No\n";
                return;
            }
        }
    }
}

int main() {
    if (true) {
        {
            istringstream iss(R"(2
2 3
5
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(Yes
)";
            string str = oss.str();
            // cout << str;

            // cout << str.size() == expected.size() <<

            // for(size_t i = 0; i < expected.size(); ++i) {
            //     cout << i << boolalpha << (str[i] == expected[i]) << endl;
            // }
            assert(oss.str() == expected);
        }
        {
            istringstream iss(R"(2
2 3
4
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(No
)";
            string str = oss.str();
            assert(oss.str() == expected);
        }
        {
            istringstream iss(R"(2
2 3
3
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(Yes
)";
            string str = oss.str();
            assert(oss.str() == expected);
        }

        cout << "ok\n";
    } else {
        f(cin, cout);
    }

    return 0;
}