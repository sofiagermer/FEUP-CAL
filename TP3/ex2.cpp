#include "exercises.h"
#include <iostream>     // std::cout
#include <climits>

using namespace std;

// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossingSum(int arr[], int i, int m, int j)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int aux = m; aux >= i; aux--) {
        sum = sum + arr[aux];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int aux = m + 1; i <= j; j++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max(max(left_sum + right_sum, left_sum), right_sum);
}

int rec(int A[], int n, int &i, int &j){
    if( n == 1) {
        cout << "oi : " << A[i] << endl;
        cout << "i : " << i << endl;
        cout << " j: " << j << endl;
        cout << "------" << endl;
        return A[i];
    }
    int mid = i + n/2;
    int b = rec(A, n/2, i, mid);
    int c = rec(A, n/2, mid , j);
    int d = maxCrossingSum(A, i,mid,j);
    /*cout << "END : " << endl;
    cout << "i : " << i << endl;
    cout << " j: " << j << endl;*/
    return(max(max(b,c), d));

}
int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
    if ( n == 0 ) return 0;
    if( n == 1) return A[0];
    i = 0;
    j = n -1;
    return rec(A,n,i,j);
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex2, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    /*EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);
*/
    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
   // EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
   // EXPECT_EQ(i, 3);
   // EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    //EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    //EXPECT_EQ(i, 0);
    //EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    //EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    //EXPECT_EQ(i, 3);
    //EXPECT_EQ(j, 6);
}