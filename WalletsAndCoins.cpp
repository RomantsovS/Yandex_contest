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

    return "";
}

int main() {
    if (true) {
        {
            istringstream iss(R"(3
2 3
3)");
            assert((f(iss) == "Petya"));
        }

        cout << "ok\n";
    } else {
        cout << f(cin);
    }

    return 0;
}