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

struct Point {
	int x, y;
};

size_t f(istream& is) {
	size_t n;
	is >> n;

	vector<Point> vec;
	vec.reserve(n);

	vector<size_t> xvec(n), yvec(n);

	for (size_t i = 0; i < n; ++i) {
		Point p;
		is >> p.x >> p.y;
		vec.push_back(p);
		xvec[i] = vec.size() - 1;
		yvec[i] = vec.size() - 1;
	}

	sort(xvec.begin(), xvec.end(), [&vec](size_t l, size_t r) {return vec[l].x < vec[r].x; });
	sort(yvec.begin(), yvec.end(), [&vec](size_t l, size_t r) {return vec[l].y < vec[r].y; });

	size_t step = 0;

	size_t xmin = 0, xmax = n - 1;
	size_t ymin = 0, ymax = n - 1;

	vector<bool> bvec(n);

	while (xmin <= xmax && ymin <= ymax) {
		while (xmin <= xmax && bvec[xvec[xmin]]) {
			++xmin;
		}
		while (xmin <= xmax && bvec[xvec[xmax]]) {
			--xmax;
		}
		while (ymin <= ymax && bvec[xvec[ymin]]) {
			++ymin;
		}
		while (ymin <= ymax && bvec[xvec[ymax]]) {
			--ymax;
		}

		int x = vec[xvec[xmin]].x;
		while (xmin <= xmax && x == vec[xvec[xmin]].x) {
			bvec[xvec[xmin]] = true;
			++xmin;
		}
		x = vec[xvec[xmax]].x;
		while (xmin <= xmax && x == vec[xvec[xmax]].x) {
			bvec[xvec[xmax]] = true;
			--xmax;
		}
		int y = vec[yvec[ymin]].y;
		while (ymin <= ymax && y == vec[yvec[ymin]].y) {
			bvec[yvec[ymin]] = true;
			++ymin;
		}
		y = vec[yvec[ymax]].y;
		while (ymin <= ymax && y == vec[yvec[ymax]].y) {
			bvec[yvec[ymax]] = true;
			--ymax;
		}
		
		++step;
	}

	return step;
}

int main() {
	if (true) {
		{
			istringstream iss(R"(1
-1 -1)");
			assert((f(iss) == 1));
		}
		{
			istringstream iss(R"(3
-1 -1
0 0
1 1)");
			assert((f(iss) == 2));
		}
		{
			istringstream iss(R"(5
0 1
1 0
1 1
2 1
3 2)");
			assert((f(iss) == 2));
		}

		cout << "ok\n";
	}
	else {
		cout << f(cin);
	}

	return 0;
}