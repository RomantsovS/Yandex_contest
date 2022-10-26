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

using namespace std;

size_t f(istream& is) {
	size_t n;
	is >> n;

	priority_queue<int> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	int v;
	for (size_t i = 0; i < n; ++i) {
		is >> v;
		minq.push(v);
		maxq.push(v);
	}

	int step = 0;

	while (minq.top() != maxq.top()) {
		v = maxq.top();
		maxq.pop();

		v -= minq.top();

		maxq.push(v);
		minq.push(v);

		++step;
	}

	return step;
}

int main() {
	if (true) {
		{
			istringstream iss(R"(2
1 1)");
			assert((f(iss) == 0));
		}
		{
			istringstream iss(R"(3
9 6 3)");
			assert((f(iss) == 3));
		}
		{
			istringstream iss(R"(6
1000000000 1000000000 1000000000 1000000000 1000000000 1)");
			assert((f(iss) == 4999999995));
		}

		cout << "ok\n";
	}
	else {
		cout << f(cin);
	}

	return 0;
}