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

struct struc {
    set<size_t> s;
    size_t n;
};

void R(string_view n, size_t start, vector<struc>& v) {
    for (size_t i = 0; i < n.size(); ++i) {
        size_t k = stoul(string(n.substr(0, i + 1)));

        cout << n.substr(0, i + 1);

        if (s.count(k) == 0) {
            s.insert(k);

            R(s, n.substr(i + 1));
        }
    }
}

void f(istream& is, ostream& os) {
    string n;
    is >> n;

    vector<struc> v;
    R(n, 0, v);

    os << "1";
}

int main() {
    if (true) {
        {
            istringstream iss(R"(101
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
            // assert(oss.str() == expected);
        }

        cout << "ok\n";
    } else {
        f(cin, cout);
    }

    return 0;
}