// You are climbing a stair case. 
// It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?
// DP?ⷨ?O(n)
// 쳲??????????O(logn)?Ľⷨ?ġ?????iki??֪????쳲????????????ʽ?ģ?????
// ????????Pow(x, n)???ܵķ?η???????n??ݵĻ?????O(logn)?????
// ?????????ⷽ????????????е??Դ???ⷨ???μ?Wiki - 쳲?????У???
// ??Կ????????һ?????˶??ļ򵥾????еĵ??????????????n-2??ݣ?
// ͬ????η??Ϳ???O(logn)?????

//step[n]=step[n-1]+step[n-2]
class Solution {
public:
    int climbStairs(int n) {
        int ways=1;
        int step=1;
        while(--n){
            ways+=step;
            step=ways-step;
        }
        return ways;
    }
}

// Fibonacci.cpp : Defines the entry point for the console application.
//

// ????ָOffer?????????پ?????ͱ???????
// ??Ȩ??????κ??

#include "stdafx.h"

// ====================????1???ݹ?===================
long long Fibonacci_Solution1(unsigned int n)
{
if(n <= 0)
return 0;

if(n == 1)
return 1;

return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}


// ====================????2??ѭ??====================
long long Fibonacci_Solution2(unsigned n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    long long  fibNMinusOne = 1;
    long long  fibNMinusTwo = 0;
    long long  fibN = 0;
    for(unsigned int i = 2; i <= n; ++ i)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

     return fibN;
}

// ====================????3??????????====================
#include <cassert>

struct Matrix2By2
{
    Matrix2By2
    (
        long long m00 = 0, 
        long long m01 = 0, 
        long long m10 = 0, 
        long long m11 = 0
    )
    :m_00(m00), m_01(m01), m_10(m10), m_11(m11) 
    {
    }

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMultiply
(
    const Matrix2By2& matrix1, 
    const Matrix2By2& matrix2
)
{
    return Matrix2By2(
        matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
        matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
        matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
        matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0);

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0)
    {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1)
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}

// ====================??Դ??====================
void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}

