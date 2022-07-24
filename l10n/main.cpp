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
#include <string_view>

using namespace std;

void f(istream& is, ostream& os) {    
    size_t n;
    is >> n;

    vector<string> words(n);

    set<pair<string_view, string_view>> prefixes;

    for(auto& str : words) {
        is >> str;
    }

    vector<string_view> words_sorted(words.begin(), words.end());
    sort(words_sorted.begin(), words_sorted.end());

    for(const auto& str : words) {
        size_t i = 1;
        // cout << str << endl;
        for(i = 1; i < str.size() / 2; ++i) {
            auto p = string_view(str).substr(0, i);
            auto s = string_view(str).substr(str.size() - i);
            
            if(prefixes.find({p, s}) != prefixes.end())
                continue;

            // cout << "p: " << p << endl;
            
            auto lb = lower_bound(words_sorted.begin(), words_sorted.end(), p,
            [](string_view l, const string_view r){
              return l.substr(0, r.size()) < r;
            });
            auto ub = upper_bound(words_sorted.begin(), words_sorted.end(), p,
            [](string_view r, const string_view l){
              return r < l.substr(0, r.size());
            });
            // cout << "s: " << s << endl;
            
            bool b = false;
            while(lb != ub) {
                // cout << "found: " << *lb << endl;
                if(*lb != str) {
                    // cout << lb->substr(lb->size() - p.size()) << endl;
                    if(lb->size() == str.size() && string_view(*lb).substr(lb->size() - p.size()) == s) {
                        // cout << "break\n";
                        b = true;
                        prefixes.insert({p, s});
                        break;
                    }
                    }
                ++lb;
            }
            if(!b)
                break;
        }
        if(i < str.size() / 2)
            os << string_view(str).substr(0, i) << to_string(str.size() - 2 * i)
                << string_view(str).substr(str.size() - i) << endl;
        else
            os << str << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (true) {
        {
            istringstream iss(R"(2
localization
internationalization
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(l10n
i18n
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }
        {
            istringstream iss(R"(4
banana
apple
potato
tomato
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(b4a
a3e
p4o
t4o
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }
        {
            istringstream iss(R"(2
aaaa
abaa
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(aaaa
abaa
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }
        {
            istringstream iss(R"(2
aaaaa
abaaa
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(aaaaa
abaaa
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }
        {
            istringstream iss(R"(2
aaaaa
abaab
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(a3a
a3b
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }
        {
            istringstream iss(R"(2
aaaa
aaaaaaaaaaaaaaaaaaaa
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(a2a
a18a
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }
        {
            istringstream iss(R"(2
aaaaaaaaaaaaaaaaaaaa
abaaaaaaaaaaaaaaaaaa
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(aa16aa
ab16aa
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }

        {
            istringstream iss(R"(10
aaaa
abaa
abab
bbbb
baba
aaaaaaaaaaaaaaaaaaaa
abaaaaaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbbb
sjfdhlsakdjfhsald
sdfasdfsadfafdsfdd
)");

            ostringstream oss;
            f(iss, oss);

            string expected = R"(aaaa
abaa
a2b
b2b
b2a
aa16aa
ab16aa
b18b
s15d
s16d
)";
            string str = oss.str();
            // cout << str;
            assert(str == expected);
        }

        cout << "ok\n";
    } else {
        f(cin, cout);
    }

    return 0;
}