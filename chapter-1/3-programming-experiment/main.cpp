#include <iostream>
#include <cmath>

using namespace std;

void original() {
	int n = 30;
	int imax;
	double error = 0;
	double x = 0.5;
	double h = 1;
	double emax = 0;
	double y;
	for (int i = 0; i < n; ++i) {
		h *= 0.25;
		y = (sin(x + h) - sin(x)) / h;
		error = abs(cos(x) - y);
		if (error > emax) {
			emax = error;
			imax = i;
		}
	}
	cout << "imax: " << imax << "\nemax: " << emax;
}

int main() {
	int n = 30;
	int imax;
	double error = 0;
	double x = 0.5;
	double h = 1;
	double emax = 0;
	double y;
	cout << "i,rounding error,truncation error,sum,total error\n";
	for (int i = 1; i <= n; ++i) {
		h *= 0.25;
		y = (sin(x + h) - sin(x-h)) / (2.0*h);
		error = abs(cos(x) - y);
		cout << i << ",";
		long double rounding_error = ((long double)y) * exp2l(-52.0);
		cout << rounding_error << ",";
		long double truncation_error = h*h/6 * cos(x);
		cout << truncation_error << ",";
		cout << rounding_error + truncation_error << ",";
		cout << error << "\n";
	}
}
