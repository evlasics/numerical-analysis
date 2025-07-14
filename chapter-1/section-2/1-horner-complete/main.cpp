#include <vector>
#include <iostream>

using namespace std;

// Converts polynomial in terms of x to polynomial in terms of (x-r). 
void hornerComplete(vector<float>& a, float r) {
	int n = a.size()-1;
	for(int k = 0; k < n; ++k) {
		for(int j = n-1; j >= k; --j) {
			a[j] = a[j] + r * a[j+1];
		}
	}
}
int main() {
	// 2x^2+x+1 -> 2(x+1)^2 - 3(x+1) + 2, where r = -1
	vector<float> a = {1, 1, 2};
	hornerComplete(a, -1);
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
//	vector<float> a = {9, 3, 4, 1, 1};
//	hornerComplete(a, -2);
//	for (int i = 0; i < a.size(); ++i) {
//		cout << a[i] << " ";
//	}
}
