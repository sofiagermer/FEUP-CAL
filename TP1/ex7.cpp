#include "exercises.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <numeric>
using namespace std;
double minimumAverageCompletionTime(vector<unsigned int> tasks, vector<unsigned int> &orderedTasks) {
    sort(tasks.begin(),tasks.end());
    for(const auto &t: tasks){
        orderedTasks.push_back(t);
    }
    double bestAverage = 0.0;

    for (size_t i = 1; i <= tasks.size(); i++) {
        bestAverage += accumulate(tasks.begin(), tasks.begin() + i, 0);
    }

    return bestAverage / tasks.size();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex7, taskOrdering) {
    std::vector<unsigned int> tasks = {15, 8, 3, 10};
    std::vector<unsigned int> orderedTasks;
    double averageTime = minimumAverageCompletionTime(tasks, orderedTasks);
    EXPECT_EQ(orderedTasks.size(), 4 );
    ASSERT_NEAR(averageTime, 17.75, 0.00001);
    ASSERT_THAT(orderedTasks,  ::testing::ElementsAre(3,8,10,15));
}