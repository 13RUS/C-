#include <iostream>
#include <vector>
#include <math.h>
#include "Matrix.h"

// -- FIBONACCI SECTION ------------------
// -- Recursion --------------------------
// -- The asymptotic complexity is O(2^n) time and inefficiently using stack --
int fib_recursion (unsigned int n) {
    if (n<2) return n;
    return (fib_recursion(n-1)+fib_recursion(n-2));
}

// -- Dynamic Progamming -----------------
// -- The asymptotic complexity is O(n) time and O(n) memory --
int fib_dynamic_one (unsigned int n){
    if (n <= 2) return 1;
    std::vector<int> fibarray(n+1);

    fibarray[1] = 1;
    fibarray[2] = 1;

    for (int i = 3; i <= n; i++) {
        fibarray[i] = fibarray [i-1] + fibarray [i-2];
    }

    return fibarray[n];
}

// -- Dynamic Progamming -----------------
// -- The asymptotic complexity is O(n) time and O(1) memory --
int fib_dynamic_two (unsigned int n){
    if (n <= 2) return 1;
    int x = 1;
    int y = 1;
    int fibnumber = 0;

    for (int i = 2; i < n; i++) {
        fibnumber = x+y;
        x = y;
        y = fibnumber;
    }

    return fibnumber;
}

// -- Fast matrix exponentiation ---------
// -- The asymptotic complexity is O(LogN) --
int fib_matrix (unsigned int n) {
    int a = 1, ta,
        b = 1, tb,
        c = 1, rc = 0, tc,
        d = 0, rd = 1;

    while (n)
    {
        if (n & 1) {
            tc = rc;
            rc = rc*a + rd*c;
            rd = tc*b + rd*d;
        }

        ta = a; tb = b; tc = c;
        a = a*a + b*c;
        b = ta*b + b*d;
        c = c*ta + d*c;
        d = tc*tb + d*d;
        n >>= 1;
    }
    return rc;
}

// -- Fast matrix exponentiation through Class Member function --
// -- The asymptotic complexity is O(LogN) --
int fib_class_matrix (unsigned int n) {
    int rc;

    Matrix P(2,2);

    P(0,0) = 1; P(0,1) = 1;
    P(1,0) = 1; P(1,1) = 0;

    rc = P.fastmultiplication(n);

    return rc;
}

// -- Golden Ration ---------
// -- The asymptotic complexity is O(log(n)) time and O(1) memory --
int fib_bine (unsigned int n) {
    auto index = pow (5,0.5);

    auto left = (1 + index) /2;
    auto right = (1 - index) /2;

    return (pow(left,n) - pow (right,n))/index;
}


// -- EXPONENTIATION SECTION -------------
// -- Iterative --------------------------
//-- The asymptotic complexity is O(n) time --
long power_iterative (long value, unsigned int pow) {
    long result = 1;

    for (long i = 0; i < pow; i ++) {
        result *= value;
    }

    return result;
}

// -- Additional Multiplication ----------
//-- The asymptotic complexity is O(N/2+LogN) = O(N) time --
long int power_multiplication (long int value, unsigned int pow)
{
    if (pow == 0) return 1;
    else if (pow == 1) return value;
    else if (pow % 2 == 0 ) return power_multiplication( value * value, pow/2);
    else return power_multiplication (value * value, pow /2) * value;
}

// -- Binary ------------------------------
//-- The asymptotic complexity is O(n) time --
long power_binary (long value, unsigned int pow) {
    long result = 1;

   while (pow != 0 ) {
       if (pow % 2 == 1) result *= value;
       value *= value;
       pow /= 2;
   }
    return result;
}

// -- PRIME NUMBERS SECTION -------------
// -- Enumeration of divisors -------------
//-- The asymptotic complexity is O(N^2) time --
int prime_divisors (unsigned int n) {
    unsigned int prime_count=0;
    unsigned int isprime;

    if (n==1) return 0;
    if (n==2) return 1;

    for (int i=2; i<n; i++) {
        isprime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) isprime = 0;
        }
        if (isprime==1) prime_count++;
    }
    return prime_count;
}
// -- Enumeration of divisors optimized -------------
//-- The asymptotic complexity is O(N*Sqrt(N)) time --
int prime_divisors_opt (unsigned int n) {
    unsigned int prime_count=0;
    unsigned int isprime;

    if (n==1) return 0;
    if (n==2) return 1;

    for (int i=2; i<n; i++) {
        isprime = 1;
        //if (i%2 == 0) i++;
        for (int j = 2; j <= sqrt(i); j ++ ) {
            if (i % j == 0) isprime = 0;
        }
        if (isprime==1) prime_count++;
    }
    return prime_count;
}

// -- Enumeration of divisors optimized+ -------------
//-- The asymptotic complexity is O(N*Sqrt(N)/Ln(N)) time --
bool isPrime (long n, long primes[]) {
    double sqr_t = sqrt(n);

    for (int i = 0; primes[i] <= sqr_t; i++)
        if (n % primes[i] == 0) return false;

    return true;
}

int prime_divisors_opt_primes (unsigned int n) {
    int prime_count = 0;
    long primes [n/2];

    primes[prime_count++] = 2;

    for (int i = 3; i <= n; i++) {
        if (isPrime(i, primes)) primes[prime_count++] = i;
    }
    return prime_count;
}

// -- Sieve of Eratosthenes -------------
//-- The asymptotic complexity is O(N Log Log N) time --
int prime_eratosthenes (unsigned int n) {
    unsigned int prime_count=0;
    int *a = new int [n];

    for (int i = 0; i < n+1; i++) {
        a[i] = i;
    }
    for (int p = 2; p < n+1; p++){
        if (a[p] !=0) {
            prime_count++;;
            for (int j = p*p; j < n+1; j += p) {
                a[j] = 0;
            }
        }
    }
    return prime_count;
}

// -- Sieve of Eratosthenes -------------
//-- The asymptotic complexity is O(N Log Log N) time --
int prime_eratosthenes_sqrt (unsigned int n) {
    if (n==1) return false;

    return true;
}

// ---------------------------------------
int main() {
    int n = 40;
    int value = 20;
    int pow = 10;
    int e = 100000;

    std::cout << "PRIME NUMBERS ALGORITHMS" << std::endl;
    std::cout << "Devisors              : ";
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "For n = " << e << " number of prime values : " << prime_divisors(e);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Devisors optimized    : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout << "For n = " << e << " number of prime values : " << prime_divisors_opt_primes (e);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Eratosthenes          : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout << "For n = " << e << " number of prime values : " << prime_eratosthenes (e);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "\nEXPONENTIATION ALGORITHMS" << std::endl;
    std::cout << "Iteratvie             : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout << value << "^" << pow << " = " << power_iterative (value, pow);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Multiplication        : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout << value << "^" << pow << " = " << power_multiplication (value, pow);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Binary                : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout << value<< "^" << pow << " = " << power_binary (value, pow);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "\nFIBONACCI ALGORITHMS" << std::endl;

    std::cout << "Recursion             : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout <<"For n = " << n << " F-number = " << fib_recursion(n);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";


    std::cout << "Dynamic Programming 1 : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout <<"For n = " << n << " F-number = " << fib_dynamic_one(n);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Dynamic Programming 2 : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout <<"For n = " << n << " F-number = " << fib_dynamic_two(n);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Matrix                : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout <<"For n = " << n << " F-number = " << fib_matrix(n);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapased time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Matrix through Class  : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout <<"For n = " << n << " F-number = " << fib_class_matrix (n);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    std::cout << "Golden Ration         : ";
    start = std::chrono::high_resolution_clock::now();
    std::cout <<"For n = " << n << " F-number = " << fib_bine(n);
    end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << " elapsed time is " << elapsed_ms.count() << " nanoseconds\n";

    return 0;
}
