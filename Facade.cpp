#include <string>

using namespace std;

class C { //Sub sistema
public: void h() {}
public: int i() { return 0; }
};

class B {
private: C c; // Clase b que usa la Clase C
public: int g() { c.h(); return 0; }
};

class A {
private: B b; // Clase A que usa la Clase B
public: int f() { return b.g(); }
};