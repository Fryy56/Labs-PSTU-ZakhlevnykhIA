#if defined(__linux__) && defined(__amd64__) && (defined(__GNUC__) || defined(__clang__))
	#define LAB_IS_SUPPORTED 1
#else
	#define LAB_IS_SUPPORTED 0
#endif

#if !LAB_IS_SUPPORTED
	#include <fmt/base.h>

#else
	extern "C" char const str[] = "Hello world!\n"; // NOLINT(modernize-avoid-c-arrays)

	__attribute__((naked))
#endif
int main() {
	#if LAB_IS_SUPPORTED
		asm volatile (R"(
			mov edi, 1
			lea rsi, [rip + str]
			mov edx, 13
			mov eax, 1
			syscall

			xor edi, edi
			mov eax, 60
			syscall
		)" :
			:
			: "rax", "rdx", "rsi", "rdi",
				"rcx", "r11", "memory" // syscall
		);
	#else
		fmt::println("Hello world!");

		return 0;
	#endif
}