#include <iostream>
#include "test.h"
class A {
 private:
  virtual std::string getName() { return "A";}
 public:
  virtual std::string name() = 0;
  virtual ~A() {
    std::cout << "~A";
  }
  friend std::string gname(A *obj);
};

class B : public A {
 private:
  virtual std::string getName() { return "B"; };
 public:
  virtual std::string name() {
    return getName();
  }
  virtual ~B() {
    std::cout << "~B";
  }
};

class C : public B {
 private:
    virtual std::string getName() { return "C"; };
 public:
  virtual std::string name() {
    return getName();
  }
  virtual ~C() {
    std::cout << "~C";
  }
};

std::string gname(A *obj) {
  std::cout << obj->getName() << std::endl;
}

int main() {
  std::cout << "Hello, World!" << std::endl;

  B btest;
  C ctest;
  std::cout << btest.name();
  gname(&btest);
  std::cout << std::endl;

  std::cout << ctest.name();
  gname(&ctest);
  std::cout << std::endl;
  A *ap = new B();

  run();
}