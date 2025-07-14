#include <iostream>
#include <cmath>

using namespace std;

double e = exp(1.0);

void four() {
	for (int i=1; i<=10; ++i) {
		double n = exp2(3.0 * i);
		double approx = pow(1.0 + 1.0/n, n);
		cout << i<< ": " << e - approx << "\n";
	}
}

void five() {
	double p = 1.0;
	for (int i=1; i<=20; ++i) {
		cout << i<<": " << p <<"\n";
		p = e - (i+1) * p;
	}
	// Proof of why monotonicity is violated was done by hand.
}

// Completed up to problem 8--many were redundant to do on the computer.
int main() {
	five();
}
