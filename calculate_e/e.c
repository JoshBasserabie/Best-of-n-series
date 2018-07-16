#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>

#define MAX_ITERATIONS 10000
#define TARGET 100

int main() {
    int randomData = open("/dev/random", O_RDONLY);
    int itemp = 0;
    double thits = 0;
    double sum = 0;
    for(int i = 0; i < MAX_ITERATIONS; i++) {
        read(randomData, &itemp, sizeof(int));
        double temp = (double)abs(itemp);
        temp /= INT_MAX;
        temp *= TARGET;
        sum += temp;
        if(sum > TARGET) {
            sum = 0;
            thits++;
        }
    }
    printf("e is approximately: %lf\n", MAX_ITERATIONS / thits);
    return 0;
}