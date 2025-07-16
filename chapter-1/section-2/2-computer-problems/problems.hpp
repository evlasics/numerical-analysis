#include <vector>
#include <iostream>

template<typename T, typename U>
class TestCase {
	public: 
		T in;
		U out;
};

template<typename T, typename U>
class Problem {
	public: 
		virtual int main () { return 0; }
		virtual U exec (T input) { return U(); };
		void runTests() {
			int n = testCases.size();
			std::cout << "Running tests:\n";
			for (int i = 0; i < n; i++) {
				std::cout << "Test " << i << "/" << n << ": ";
				if(test(testCases[i])) std::cout << "Passed\n";
				else std::cout << "Failed\n";
			}
			std::cout << "Tests complete.\n";
		}
		std::vector<TestCase<T, U>> testCases;
		virtual int test (TestCase<T, U>) { return 0; }
};
