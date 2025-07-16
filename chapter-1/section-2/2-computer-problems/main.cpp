#include "problems.hpp"
#include "compare.cpp"
#define _USE_MATH_DEFINES
#include <math.h>

using std::pair;
using std::cout;
using std::vector;

// we see here that we should use double precision instead of single precision.
class One : public Problem<float, pair<float, float>>  {
	public: 
		pair<float, float> exec(float c) override {
			float discriminant = sqrt(1.0e16 - 4 * c);
			return pair<float, float> {-5.0e7 + discriminant/2, -5.0e7 - discriminant/2};
		}
		int main() override {
			auto out = exec(1.0);
			cout << out.first << ", " << out.second << "\n";
			out = exec(1.0e8);
			cout << out.first << ", " << out.second;
			return 0;
		}
};

class Nine : public Problem<pair<float, float>, float> {
	const float precision = 0.00001;
	public:
		Nine() {
			testCases = { {{0, 0}, 0} };
		}
		float exec(pair<float, float> in) override {
			const float x = in.first;
			const float y = in.second;
			return cos(x - y) - cos(x) * cos(y) - sin(x) * sin(y);
		}
		int main() override {
			float maxdiff = -100.0;
			for (float x = -M_PI; x < M_PI; x+=0.001) {
				for (float y = -M_PI; y < M_PI; y+=0.001) {
					float error = fabs(exec({x, y}));
					if (error > maxdiff) {
						maxdiff = error;
						cout << "x, y, error: " << x << " " << y << " " << maxdiff << "\n";
					}
				}
			}
			// Since it's like 10^-7 we can be pretty confident they're equal.
			cout << "Max difference: " << maxdiff;
			return 0;
		}
		int test(TestCase<pair<float, float>, float> testCase) override {
			return compare(exec(testCase.in), testCase.out, precision);
		}
};

//20 - Use your brain before just running it on a computer. Or find a way to test much larger values of n. In this case, the student should have taken the logarithm of the terms, and then the computer would have no problem showing that it goes to 0.

// Will do in a bit
class TwentyTwo : public Problem {
}

// Type here dictates which problem we are running.
Nine problem;

int main() {
	problem.runTests();
	return problem.main();
}

