#include <stdio.h>
#include <math.h>

float func4(float x);
struct Str func2(float x, float i);

struct Str {
    float fi;
    float sum;
};

int main() {
    printf("Iteration result: %f\n", func4(2));

    struct Str res2 = func2(2, 5);
    printf("Recursion_2 result: %f\n", res2.sum);

    printf("Correct result: %f", cos(2));
    return 0;

}

struct Str func2(float x, float i) {
    static struct Str result = {1, 1};
    if (i == 0) {
        return result;
    }
    float fi = -func2(x, i-1).fi*x*x/(4*i*i-2*i);
    result.fi = fi;
    result.sum += fi;
    return result;
}

float func4(float x) {
    int n = 5;
    float res = 1;
    float fi = 1;
    for (int i = 1; i < n; i++) {
        float fi1 = (-fi*x*x)/(4*(float)i*(float)i-2*(float)i);
        fi = fi1;
        res += fi1;
    }
    return res;
}