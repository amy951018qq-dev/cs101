#include <stdio.h>

void print_spaces(int rows, int r) {
    for (int sp = 0; sp < rows;sp++){
        printf(" ");
    }
}

// 計算階乘
int factorial(int r) {
    long long result = 1;
    for(int i = 1; i <= r; i++) {
        result *= i;
    }
    return result;
}

// 計算組合數 C(r, i)
int combination(int r, int i) {
    if(i > r) return 0; // i 不可以大於 r
    return factorial(r) / (factorial(i) * factorial(r - i));
}

void print_pascal_number(int rows, int r) {
    for (int i = 0; i<= r; i++){
        printf("%d", combination(r, i));
        printf(" ");
    } 
    printf("\n");
}

int main() {
    // main loop for rows i=0 to 5
    int rows = 5;
    for (int r = 0; r< 5; r++) { 
    // print spaces
    print_spaces(rows, r);
    // print numbers by ith row
    print_pascal_number(rows, r);
    rows=rows-1;
    }
return 0;
}

