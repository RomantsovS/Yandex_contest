#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

size_t wsf(const vector<vector<int>>& g, int v, int u) {
    queue<int> q;

    q.push(v);

    vector<int> d(g.size(), -1);
    d[v] = 0;

    while (!q.empty()) {
        int k = q.front();

        if (k == u) return d[u];

        q.pop();

        for (size_t i = 0; i < g.size(); ++i) {
            if (g[k][i] > 0 && d[i] == -1) {
                d[i] = d[k] + 1;
                q.push(i);
            }
        }
    }

    return -1;
}

struct Point {
    int64_t x, y;
};

int f(istream& is) {
    size_t n;
    is >> n;

    vector<Point> vec(n);
    for (auto& p : vec) is >> p.x >> p.y;

    size_t k;
    is >> k;

    vector<vector<int>> g(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i == j)
                g[i][j] = 0;
            else {
                size_t len = abs(vec[i].x - vec[j].x) + abs(vec[i].y - vec[j].y);
                // cout << len << endl;
                if (len <= k) g[i][j] = 1;
            }
        }
    }

    // for (size_t i = 0; i < n; ++i) {
    //     for (size_t j = 0; j < n; ++j) {
    //         if (j != 0) cout << ", ";
    //         cout << std::setw(4) << g[i][j];
    //     }
    //     cout << endl;
    // }

    size_t a, b;
    is >> a >> b;

    int res = wsf(g, a - 1, b - 1);
    return res;
}

int main() {
    if (false) {
        {
        istringstream iss(R"(7
0 0
0 2
2 2
0 -2
2 -2
2 -1
2 1
2
1 3
)");
        assert((f(iss) == 2));}
{
istringstream iss(R"(4
0 0
1 0
0 1
1 1
2
1 4
)");
        assert((f(iss) == 1));}
        {
istringstream iss(R"(4
0 0
2 0
0 2
2 2
1
1 4
)");
        assert((f(iss) == -1));
        }

        cout << "ok\n";
    } else {
        cout << f(cin);
    }

    return 0;
}