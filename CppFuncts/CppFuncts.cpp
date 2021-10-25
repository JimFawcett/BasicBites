// CppFuncts.cpp

#include <string>
#include <iostream>

/* pass value by value */
auto pass_val_by_val(std::string s) -> std::string {
  std::cout << "\n  Pass val by val";
  std::cout << "\n    input s = " << s;
  s += std::string(" addendum");
  std::cout << "\n    mutated value = " << s;
  return s;
}
/* pass value by refernce */
auto pass_val_by_ref(std::string& s) -> std::string {
  std::cout << "\n  Pass val by ref";
  std::cout << "\n    input s = " << s;
  s += std::string(" addendum");
  std::cout << "\n    mutated value = " << s;
  return s;
}

/* pass reference by value - new instance */
/* can't rebind C++ reference, so must use ptr */
auto pass_ref_by_val(std::string* ptr) {
  std::cout << "\n  Pass ref by val - new instance";
  std::cout << "\n    input *ptr = " << *ptr;
  ptr = new std::string("a string addendum");
  std::cout << "\n    mutated value = " << *ptr;
}

/* pass reference by refernce - new instance */
/* can't rebind C++ reference, so must use ptr */
auto pass_ref_by_ref(std::string** ptr) {
  std::cout << "\n  Pass ref by ref - new instance";
  std::cout << "\n    input **ptr = " << **ptr;
  *ptr = new std::string("a string addendum");
  std::cout << "\n    mutated value = " << **ptr;
}

int main() {
  /* pass value by value */
  auto s1 = std::string("a string");
  auto r1 = pass_val_by_val(s1);
  std::cout << "\n  return value = " << r1;
  std::cout << "\n  input s = " << s1 << "\n";

  /* pass value by reference */
  auto s2 = std::string("a string");
  auto r2 = pass_val_by_ref(s2);
  std::cout << "\n  return value = " << r2;
  std::cout << "\n  input s = " << s2 << "\n";

  /* pass reference by value - new instance*/
  /* can't rebind C++ reference, so must use ptr */
  auto s3 = std::string("a string");
  auto ptr3 = &s3;
  pass_ref_by_val(ptr3);
  std::cout << "\n  no side effect: *ptr = " << *ptr3;
  std::cout << "\n  input s = " << s3 << "\n";

  /* pass reference by reference - new instance*/
  /* can't rebind C++ reference, so must use ptr */
  auto s4 = std::string("a string");
  auto ptr4 = &s4;
  pass_ref_by_ref(&ptr4);
  std::cout << "\n  side effect: *ptr = " << *ptr4;
  std::cout << "\n  input s = " << s4 << "\n";

}