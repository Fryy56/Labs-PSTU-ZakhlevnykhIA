#include <iostream>


template <typename T>
	requires std::is_arithmetic_v<T>
[[nodiscard]] constexpr T square(T x) noexcept {
	return x * x;
}

template <std::floating_point T>
[[nodiscard]] consteval T calculate1() noexcept {
	T a = 1000.;
	T b = 0.0001;

	auto sum = a + b;
	auto subLHS = square(sum);

	auto aSquared = square(a);
	auto ab = a * b;
	auto subRHS = aSquared + 2 * ab;

	auto divident = subLHS - subRHS;
	auto divisor = square(b);

	return divident / divisor;
}

void task1() {
	std::cout << "Task 1\n";

	constexpr auto floatRes = calculate1<float>();
	constexpr auto doubleRes = calculate1<double>();

	std::cout << "float: " << floatRes << "\ndouble: " << doubleRes << "\n\n";

	return;
}


int main() {
	task1();

	return 0;
}