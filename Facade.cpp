#include <string>

using namespace std;

class C { // a subsystem
public: void h() {}
public: int i() { return 0; }
};

class B {
private: C c; // class B uses class C, a "subsystem"
public: int g() { c.h(); return 0; }
};

class A {
private: B b; // Class A uses Class B, the "interface"
public: int f() { return b.g(); }
};