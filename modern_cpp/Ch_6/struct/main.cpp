#include <iostream>

// Struct to hold multiple values
struct Result {
  int sum;
  int product;
};

// Function returning a struct
Result compute(int a, int b) { return {a + b, a * b}; }

int main() {
  Result result = compute(3, 4);
  std::cout << "Sum: " << result.sum << ", Product: " << result.product
            << std::endl;
  return 0;
}
