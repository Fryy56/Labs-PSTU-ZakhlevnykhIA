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


[[nodiscard]] std::int32_t calculate21(std::int32_t n, std::int32_t m) noexcept {
	return - -m-++n; // -(-m) - (++n)   |   m - (++n)   |   m - n - 1
}

[[nodiscard]] std::int32_t calculate22(std::int32_t n, std::int32_t m) noexcept {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsequenced"

	// NOLINTNEXTLINE(bugprone-inc-dec-in-conditions)
	return m*n<n++; // (m * n) < (n++)   |   m * n < n   |   m * n - n < 0   |   n * (m - 1) < 0

	#pragma GCC diagnostic pop
}

[[nodiscard]] std::int32_t calculate23(std::int32_t n, std::int32_t m) noexcept {
	return n-- > m++; // (n--) > (m++)   |   n > m
}

template <bool Last = false>
void calculate2(std::int32_t n, std::int32_t m) {
	std::cout << "n = " << n << "; m = " << m << "\n";

	std::cout << std::boolalpha <<
		"  1. " << calculate21(n, m) << "\n"
		"  2. " << static_cast<bool>(calculate22(n, m)) << "\n"
		"  3. " << static_cast<bool>(calculate23(n, m)) << "\n"
		"Assumed:\n"
		"  1. " << m - n - 1 << " (m - n - 1)\n"
		"  2. " << (n * (m - 1) < 0) << " (n * (m - 1))\n"
		"  3. " << (n > m) << " (n > m)\n";

	if constexpr (!Last)
		std::cout << "\n";

	return;
}

void task2() {
	std::cout << "Task 2\n";

	calculate2(5, 3);
	calculate2(-8, 4);
	calculate2(0, 6);
	calculate2(0, 0);
	calculate2(45, -12);
	calculate2(1, 1);
	calculate2(1, 0);
	calculate2<true>(0, 1);

	return;
}


int main() {
	task1();
	task2();

	return 0;
}