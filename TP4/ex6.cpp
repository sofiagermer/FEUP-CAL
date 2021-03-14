#include "exercises.h"

int maxSubsequenceDP(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    if ( n == 0) return 0;
    int temp_sum = 0;
    int max_sum = 0;
    for (int first = 0; first < n ; first++) {
        if(A[first] >= (temp_sum + A[first])){
            temp_sum = A[first];
            i = first;
            j = first;
        }
        else{
            temp_sum += A[first];
            if( temp_sum > max_sum){
                max_sum = temp_sum;
                j = first;
            }
        }
    }
    if( temp_sum > max_sum){
        max_sum = temp_sum;
    }

    return max_sum;
}


int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
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

int maxSubsequenceDC(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // TODO
	// Copy-paste your solution for ex2 of TP3 HERE
	return 0;
}

void testPerformanceMaxSubsequence() {
	// TODO
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex6, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequenceDP(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDP(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDP(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDP(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);

    testPerformanceMaxSubsequence();
}