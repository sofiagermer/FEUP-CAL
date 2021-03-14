// By: Gonçalo Leão

#include "exercises.h"
#include "iostream"
int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = 0;
    int temp_sum = 0;
    for (int first = 0; first < n ; first++){
        for (int last = first; last < n; last++){
            temp_sum += A[last];
            if(temp_sum > maxSum){
                i = first;
                j = last;
                maxSum = temp_sum;
            }
        }
        temp_sum = 0;
    }
    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>


TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}
