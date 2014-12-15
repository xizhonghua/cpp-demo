#include <mylib/fact.h>

int Fact::fact(int n){
    if (n<=0) return 1;
    return n * this->fact(n-1);
}