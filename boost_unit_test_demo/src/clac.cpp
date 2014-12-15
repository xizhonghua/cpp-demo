#include <mylib/calc.h>

int Calc::add(int a, int b) {
    return a + b;
}

int Calc::sub(int a, int b) {
    //FIXME this is a bug
    return b - a;
}

int Calc::mul(int a, int b) {
    return a*b;
}