#include <fmt/base.h>

#include <concepts>
#include <cstdint>
#include <cmath>


template <std::floating_point T>
[[nodiscard]] std::pair<T, std::uintmax_t> calculate() noexcept {
	constexpr T eps = 1.e-4;

	T sum = 0.;
	std::uintmax_t n = 1u;
	for (T aPrev = 2.; eps <= aPrev; ++n) {
		sum += aPrev;

		aPrev *= 2 * std::pow(static_cast<T>(n) / (n + 1u), n);
	}

	return { sum, n - 1u };
}

int main() {
	auto [sumF, nF] = calculate<float>();
	auto [sumD, nD] = calculate<double>();

	fmt::println(
		"float:\n"
		"  sum: {}; last n: {}\n"
		"double:\n"
		"  sum: {}; last n: {}",
		sumF, nF,
		sumD, nD
	);

	return 0;
}