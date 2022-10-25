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

struct GameStat {
    int a, b, res;
};

void print_delimeter(ostream& os, size_t num_teams, size_t max_team_size) {
    os << '+' << string(num_teams > 10 ? 2 : 1, '-') << '+';
    os << string(max_team_size, '-') << '+';

    for (size_t i = 0; i < num_teams + 2; ++i) {
        os << "-+";
    }
    os << '\n';
}

struct TeamStat {
    size_t score;
    size_t wins;
    size_t place;
};

void f(istream& is, ostream& os) {
    map<string, map<string, GameStat>> m;
    map<string, TeamStat> ts;

    string s, s1, s2;

    size_t max_team_size = 0;
    set<string> teams;

    while (getline(is, s)) {
        istringstream iss(s);
        iss >> s1;
        iss >> s;
        iss >> s2;

        teams.insert(s1);
        teams.insert(s2);

        iss >> s;
        GameStat gs;
        iss >> gs.a;
        iss.ignore(1);
        iss >> gs.b;

        if (gs.a > gs.b)
            gs.res = 3;
        else if (gs.a == gs.b)
            gs.res = 1;
        else
            gs.res = 0;

        m[s1][s2] = gs;
        ts[s1].score += gs.res;
        ts[s1].wins += gs.res == 3 ? 1 : 0;

        swap(gs.a, gs.b);

        if (gs.res == 3)
            gs.res = 0;
        else if (gs.res == 0)
            gs.res = 3;

        m[s2][s1] = gs;
        ts[s2].score += gs.res;
        ts[s2].wins += gs.res == 3 ? 1 : 0;

        max_team_size = max(max_team_size, s1.size());
        max_team_size = max(max_team_size, s2.size());
    }

    ++max_team_size;

    vector<string> teams_vec(teams.begin(), teams.end());

    print_delimeter(os, teams.size(), max_team_size);

    vector<size_t> scores(teams.size());
    iota(scores.begin(), scores.end(), 0);

    sort(scores.begin(), scores.end(), [&](size_t lhs, size_t rhs) {
        return ts[teams_vec[lhs]].score > ts[teams_vec[rhs]].score ||
               (ts[teams_vec[lhs]].score == ts[teams_vec[rhs]].score &&
                ts[teams_vec[lhs]].wins > ts[teams_vec[rhs]].wins);
    });

    size_t place = 1;
    auto t = ts[teams_vec[scores[0]]];

    for (size_t i = 0; i < teams.size(); ++i) {
        if (!(ts[teams_vec[scores[i]]].score == t.score &&
              ts[teams_vec[scores[i]]].wins == t.wins)) {
            ++place;
            t = ts[teams_vec[scores[i]]];
        }
        ts[teams_vec[scores[i]]].place = place;
    }

    // for (auto& tt : scores) {
    //     cout << teams_vec[tt] << ": " << ts[teams_vec[tt]].score << ' '
    //          << ts[teams_vec[tt]].wins << ' ' << ts[teams_vec[tt]].place << endl;
    // }

    size_t n = 1;

    for (size_t i = 0; i < teams.size(); ++i) {
        os << '|';
        if (teams.size() > 10 && n < 10) os << ' ';
        os << to_string(n++) + '|';

        os << teams_vec[i];
        os << string(max_team_size - teams_vec[i].size(), ' ');
        os << '|';

        auto& tgs = m[teams_vec[i]];

        for (size_t j = 0; j < teams.size(); ++j) {
            if (i == j)
                os << 'X';
            else if (tgs.count(teams_vec[j]) == 0) {
                os << ' ';
            } else {
                if (tgs[teams_vec[j]].res == 3)
                    os << 'W';
                else if (tgs[teams_vec[j]].res == 1)
                    os << 'D';
                else
                    os << 'L';
            }

            os << '|';
        }

        os << to_string(ts[teams_vec[i]].score) + '|';
        if (ts[teams_vec[scores[i]]].place < 4)
            os << to_string(ts[teams_vec[i]].place);
        else
            os << ' ';
        os << '|';

        os << '\n';
        print_delimeter(os, teams.size(), max_team_size);
    }
}

int main() {
    if (true) {
//         {
//             istringstream iss(R"(Linux - Gentoo - 1:0
// Gentoo - Windows - 2:1
// Linux - Windows - 0:2
// )");

//             ostringstream oss;
//             f(iss, oss);

//             string expected = R"(+-+--------+-+-+-+-+-+
// |1|Gentoo  |X|L|W|3|1|
// +-+--------+-+-+-+-+-+
// |2|Linux   |W|X|L|3|1|
// +-+--------+-+-+-+-+-+
// |3|Windows |L|W|X|3|1|
// +-+--------+-+-+-+-+-+
// )";
//             // string str = oss.str();

//             // cout << str.size() == expected.size() <<

//             // for(size_t i = 0; i < expected.size(); ++i) {
//             //     cout << i << boolalpha << (str[i] == expected[i]) << endl;
//             // }
//             assert(oss.str() == expected);
//         }

        {
            istringstream iss(R"(Cplusplus - C - 1:0
Cplusplus - Php - 2:0
Java - Php - 1:0
Java - C - 2:2
Java - Perl - 1:1
Java - Haskell - 1:1
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(+-+----------+-+-+-+-+-+-+-+-+
|1|C         |X|L| |D| | |1|3|
+-+----------+-+-+-+-+-+-+-+-+
|2|Cplusplus |W|X| | | |W|6|1|
+-+----------+-+-+-+-+-+-+-+-+
|3|Haskell   | | |X|D| | |1|3|
+-+----------+-+-+-+-+-+-+-+-+
|4|Java      |D| |D|X|D|W|6|2|
+-+----------+-+-+-+-+-+-+-+-+
|5|Perl      | | | |D|X| |1|3|
+-+----------+-+-+-+-+-+-+-+-+
|6|Php       | |L| |L| |X|0| |
+-+----------+-+-+-+-+-+-+-+-+
)";
            string str = oss.str();
            // cout << str;

            // cout << str.size() == expected.size() <<

            // for(size_t i = 0; i < expected.size(); ++i) {
            //     cout << i << boolalpha << (str[i] == expected[i]) << endl;
            // }
            assert(oss.str() == expected);
        }

        cout << "ok\n";
    } else {
        f(cin, cout);
    }

    return 0;
}