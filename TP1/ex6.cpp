#include "exercises.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
using namespace std;
bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}
bool Activity:: overlaps(const Activity &a2) const {
    return (start < a2.finish) && (a2.start < finish);
}

vector<Activity> earliestFinishScheduling(vector<Activity> A) {
    //priority is given to activities with the earliest finish time
    auto comp = [] ( Activity activity1, Activity activity2){
        return (activity1.finish < activity2.finish);
    };
    sort(A.begin(),A.end(),comp);
    vector<Activity> final;
    bool possible = true;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < final.size(); j++){
            if(A.at(i) == final.at(j)){
                possible = false;
            }
        }
        if(!possible) continue;
        for(int j = 0; j < final.size(); j++){
            if(A.at(i).overlaps(final.at(j))){
                possible = false;
                break;
            }
        }
        if(possible) final.push_back(A.at(i));
        possible = true;
    }
    return final;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>


TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(V,  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}