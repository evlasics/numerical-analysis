#include <iostream>
#include <cmath>
#include <vector>

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
void nine() {
	//2^1023, 2^1022, 2^1021, 2^1020
	double a = exp2(1020);
	double b;
	// proof that it is not just already infinity.
	cout << "a_1 is " << fixed << a << "\n";
	for(int n = 1; n <= 1000; ++n) {
		b = n * a;
		a = b / n;
		if (n % 100 == 0) {
			cout << n << " - a: " << fixed << a << ", b: " << b << "\n";
		}
	}
}

// This is enough practice for now. I read all the following problems and none seemed *that* relevant.

// 25 - 0% of primes. Use the Prime Number Theorem :)

int main() {

}
