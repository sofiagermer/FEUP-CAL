#include "exercises.h"
#include <bits/stdc++.h>
using namespace std;
bool isCanonical(unsigned int C[], unsigned int n) {
    unsigned int Stock[n];
    unsigned int usedCoinsBruteForce[n];
    unsigned int usedCoinsGreedy[n];
    unsigned int T = 0;
    int numCoinsBruteForce = 0;
    int numCoinsGreedy = 0;
    int min = 1000;
    for(int i = 0; i < n; i++){
        Stock[i] = 1000;
        T += C[i];
        if(C[i] < min) min = C[i];
    }
    for(int exp = min; exp < (T+1); exp++){
        if(!changeMakingBF(C, Stock, n, exp, usedCoinsBruteForce)){
            return false;
        }

        else{
            for (int i = 0; i < n; i++) numCoinsBruteForce += usedCoinsBruteForce[i];

            if(changeMakingGreedy(C, Stock, n, exp, usedCoinsGreedy)){
                for (int i = 0; i < n; i++) numCoinsGreedy += usedCoinsGreedy[i];
            }
            if(numCoinsGreedy > numCoinsBruteForce) return false;
            numCoinsBruteForce = 0;
            numCoinsGreedy = 0;
        }
    }
    return true;
}


/// TESTS ///
#include <gtest/gtest.h>


TEST(TP1_Ex5, canonicalTrue) {
    unsigned int C[] = {1,2,5};
    EXPECT_EQ(isCanonical(C,3), true);

    unsigned int C2[] = {1,2,5,10};
    EXPECT_EQ(isCanonical(C2,4), true);
}

TEST(TP1_Ex5, canonicalFalse) {
    unsigned int C[] = {1,4,5};
    EXPECT_EQ(isCanonical(C,3), false);
}