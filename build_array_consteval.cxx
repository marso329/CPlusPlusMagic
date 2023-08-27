
#include <array>
#include <iostream>

template <typename T, std::size_t LL, std::size_t RL>
consteval std::array<T, LL + RL> operator+(const std::array<T, LL> &lhs,
                                           const std::array<T, RL> &rhs) {
  std::array<T, LL + RL> ar;

  auto current = std::copy(rhs.begin(), rhs.end(), ar.begin());
  std::copy(lhs.begin(), lhs.end(), current);

  return ar;
}

template <typename... Args>
consteval std::size_t totalArraySize(Args &&...args) {
  return (... + std::forward<Args>(args).size());
}

template <typename... Args> consteval auto totalArray(Args &&...args) {
  return (... + std::forward<Args>(args));
}

int main() {
  constexpr std::array<int, 3> test = {1, 2, 3};
  constexpr std::array<int, 2> test1 = {1, 2};
  constexpr auto test2 = totalArray(test, test1);
  for (auto element : test2) {
    std::cout << element << std::endl;
  }

  constexpr std::size_t total_size = totalArraySize(test, test1, test2);
  std::cout << "size: " << total_size << std::endl;
}