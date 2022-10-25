#include <cassert>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

vector<size_t> R(const std::string& str, size_t begin, size_t end, unordered_set<size_t> s) {
	vector<size_t> v;
	size_t val = 0;

	map<size_t, pair<size_t, vector<size_t>>> m;

	for (size_t i = begin; i < end; ++i) {
		val = val * 10 + str[i] - '0';

		if (s.count(val) == 0) {
			s.insert(val);
			if (i + 1 == end) {
				m[0] = { val, {} };
				break;
			}
			auto res = R(str, i + 1, end, s);
			if (res.empty()) {
				s.erase(val);
				if (val == 0)
					return {};
			} 
			else {
				m[res.size()] = { val, res };
			}
		}
		else if (val == 0)
			return {};
	}

	if (m.empty())
		return {};
	auto& max = prev(m.end())->second;
	vector<size_t> res(max.second.size() + 1);
	res[0] = max.first;
	copy(max.second.begin(), max.second.end(), next(res.begin()));
	return res;
}

std::string f(istream& is) {
	size_t n;
	is >> n;

	if (n == 0)
		return "0";

	std::string str(to_string(n));

	unordered_set<size_t> s;
	vector<size_t> v = R(str, 0, str.size(), s);	

	string res;
	for (size_t i = 0; i < v.size(); ++i) {
		if (i > 0)
			res += '-';
		res += to_string(v[i]);
	}
	return res;
}

int main() {
	if (true) {
		{
			istringstream iss(R"(101)");
			assert((f(iss) == "10-1"));
		}
		{
			istringstream iss(R"(102)");
			assert((f(iss) == "1-0-2"));
		}
		{
			istringstream iss(R"(11)");
			assert((f(iss) == "11"));
		}
		{
			istringstream iss(R"(1010)");
			assert((f(iss) == "1-0-10"));
		}
		{
			istringstream iss(R"(10000)");
			assert((f(iss) == "1000-0"));
		}
		{
			istringstream iss(R"(10001000)");
			assert((f(iss) == "100-0-1000"));
		}
		{
			istringstream iss(R"(10001900)");
			assert((f(iss) == "1000-1-90-0"));
		}
		{
			istringstream iss(R"(111111900)");
			assert((f(iss) == "1-11-111-90-0"));
		}

		cout << "ok\n";
	}
	else {
		cout << f(cin);
	}

	return 0;
}