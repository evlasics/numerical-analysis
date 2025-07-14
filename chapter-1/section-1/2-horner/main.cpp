#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Linear time computation of a polynomial at a given value.
// Takes in coefficients a_i, and a value x, evaluates a[0] + a[1]x + a[2]x^2 + ...
double horner_simple(vector<double> coefficients, double x) {
	double b = coefficients.back();
	coefficients.pop_back();

	for_each(coefficients.rbegin(), coefficients.rend(), [&b, x](const double a) {
			b = x * b + a;
	});
	return b;
}

pair<vector<double>, double> horner(vector<double> coefficients, double x) {
	const size_t len = coefficients.size();
	vector<double> b(len-1, 0.0);

	b[len - 2] = coefficients[len - 1];

	for (int i=len - 2; i > 0; --i) {
		b[i-1] = b[i] * x + coefficients[i];
	}
	double r = b[0] * x + coefficients[0];
	return pair<vector<double>, double>(b, r);
}

int main() {
	// Polynomial is 2+3x+x^2 and x is 1 so we should expect to get 20.
	vector<double> coefficients {2.0, 3.0, 1.0};
	double x = 3.0;
	cout << horner_simple(coefficients, x) << "\n\n";

	// Poynomial is 1+x+2x^2 and x is 1 so we should expect to get 4 as our value, and our vector should be {3, 2}
	coefficients = {1.0, 1.0, 2.0};
	x = 1.0;
	auto h = horner(coefficients, x);
	cout << h.second << "\n";
	for (auto v : h.first)
		cout << v << " ";
}
