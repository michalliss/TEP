#include <iostream>
class X {
 public:
  virtual void f(void) {
    std::cout << "vX";
  }
  void f1(void) { std::cout << "X"; }
} x, *px;
class Y : public X {
 public:
  virtual void f(void) {
    std::cout << "vY";
  }
  void f1(void) { std::cout << "Y"; }
} y, *py;

void run() {
  px = &y;
  px->f();
  px->f1();
}