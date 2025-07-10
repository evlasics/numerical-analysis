#include <iostream>
#include <cmath>

using namespace std;

int main() {
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
