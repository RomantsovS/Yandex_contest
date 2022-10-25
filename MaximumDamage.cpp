#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

size_t R(size_t first, size_t n, size_t a, map<size_t, size_t>& m) {
	if (n == 1)
		return 1;
	if (n == a)
		return 0;

	if (m.count(n) != 0)
		return m[n];

	size_t max = n;

	for (size_t i = first; i < n; ++i) {
		if (i == a)
			continue;

		size_t res = R(1, n - i, a, m);
		size_t mul = i * res;

		if (max < mul)
			max = mul;
	}

	m[n] = max;

	return max;
}

size_t f(istream& is) {
	size_t n, a;
	is >> n >> a;

	map<size_t, size_t> m;

	return R(1, n, a, m);
}

int main() {
	if (true) {
		{
			istringstream iss(R"(8 2)");
			assert((f(iss) == 16));
		}
		{
			istringstream iss(R"(9 3)");
			assert((f(iss) == 20));
		}

		cout << "ok\n";
	}
	else {
		cout << f(cin);
	}

	return 0;
}