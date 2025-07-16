#include <cmath>

bool compare(float float1, float float2, float margin) {
	const auto greater_magnitude = std::fmax(std::fabs(float1),std::fabs(float2));
	return std::fabs(float1-float2) <= margin * greater_magnitude;
}
