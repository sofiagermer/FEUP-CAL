// By: Gonçalo Leão

#include "exercises.h"
#include <bits/stdc++.h>
using namespace std;

//EXPERIÊNCIA USANDO RECURSÃO PARA ENCONTRAR AS COMBINAÇÕES TODAS POSSÍVEIS
bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    vector <unsigned int> indices;
    vector<unsigned int> temp_stock;
    vector <unsigned int> temp_usedCoins;
    vector<unsigned int> used_coins;
    unsigned int temp_change = T;
    int num_coins = 100000;
    int temp_num_coins = 0;
    bool found = false;
    for(int i = 0; i < n ; i++) temp_stock.push_back(Stock[i]);
    for(unsigned int i = 0 ; i < n; i++) indices.push_back(i);

    int i = 0;
    do {
        while(i < n){
            if(temp_change == 0) break;
            else if (C[indices.at(i)] > temp_change) i++;
            else if (temp_stock.at(indices.at(i)) == 0) i++;
            else{
                temp_usedCoins.push_back(C[indices.at(i)]);
                temp_change -= C[indices.at(i)];
                temp_num_coins++;
                temp_stock.at(indices.at(i))--;
            }
        }
        if(temp_change == 0 && temp_num_coins < num_coins) {
            found = true;
            num_coins = temp_num_coins;
            for(int x = 0; x < n; x++){
                usedCoins[x] = 0;
                for(auto &c : temp_usedCoins){
                    if(c == C[x]){
                        usedCoins[x]++;
                    }
                }
            }
        }
        i = 0;
        temp_change = T;
        temp_usedCoins.clear();
        temp_num_coins = 0;
        for(int i = 0; i < n ; i++) temp_stock.at(i) = Stock[i];
    } while (next_permutation(indices.begin(), indices.end()));

    if(!found) return false;
    return true;
}

/// TESTS ///
#include <gtest/gtest.h>


TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}


TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    //EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}