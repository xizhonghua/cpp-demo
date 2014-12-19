#include "Sample1.h"
#include <cmath>
using namespace std;

/*
 * Class:     Sample1
 * Method:    evaluate
 * Signature: ([D)D
 */
JNIEXPORT jdouble JNICALL Java_Sample1_evaluate
  (JNIEnv * env, jobject obj, jdoubleArray array)
{
    double sum = 0.0;
    jsize len = env->GetArrayLength(array);
    if(len == 0) return sum;
    
    jdouble *body = env->GetDoubleArrayElements(array, 0);
    for(int i=0;i<len;i++) {
        sum += (body[i] * body[i]);
    }

    env->ReleaseDoubleArrayElements(array, body, 0);

    return sqrt(sum) / len;
}