#include <iostream>

// Function returning returning multiple values via reference
void compute(int a, int b, int &sum, int &product) {
  sum = a + b;
  product = a * b;
}

int main() {
  int sum, product;
  compute(3, 4, sum, product);
  std::cout << "Sum: " << sum << ", Product: " << product << std::endl;
  return 0;
}
