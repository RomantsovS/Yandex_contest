#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;

int h(int a, int b) {
	return __popcnt(a ^ b);
}

void f(istream& is, ostream& os) {
	size_t n, q;
	is >> n >> q;

	while (q-- > 0) {
		string s1, s2;
		is >> s1 >> s2;

		int d = 0;

		for (size_t i = 0; i < n; ++i) {
			if (s1[i] != s2[i])
				++d;
		}

		d /= 2;
		for (size_t i = 0; d > 0; ++i) {
			if (s1[i] != s2[i]) {
				s1[i] = (s1[i] == '0' ? '1' : '0');
				--d;
			}
		}

		os << s1 << endl;
	}
}

int main() {
	if (true) {
		{
			istringstream iss(R"(5 3
01000 00110
00000 11111
00001 00111)");
			ostringstream oss;
			f(iss, oss);
			assert(oss.str() == R"(00000
11000
00101
)");
		}

		cout << "ok\n";
	}
	else {
		f(cin, cout);
	}

	return 0;
}