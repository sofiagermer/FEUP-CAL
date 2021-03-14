#include "exercises.h"
#include "exercises.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
using namespace std;
bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::overlaps(const Activity &a2) const {
    return (start < a2.finish) && (a2.start < finish);
}

bool Rec(vector<Activity> A, vector< Activity> &final){
    if(A.empty()) return true;
    if(final.empty()) final.push_back(A.at(0));
    auto it = find(final.begin(), final.end(), A.at(0));
    bool overlaps = false;
    if(it == final.end()){
        for(int j = 0; j < final.size(); j++){
            if(A.at(0).overlaps(final.at(j))){
                overlaps = true;
            }
        }
        if(!overlaps) final.push_back(A.at(0));
        A.erase(A.begin());
    }
    else{
        A.erase(A.begin());
    }
    return Rec(A,final);
}
std::vector<Activity> activitySelectionBacktracking(std::vector<Activity> A) {
//priority is given to activities with the earliest finish time
    auto comp = [] ( Activity activity1, Activity activity2){
        return (activity1.finish < activity2.finish);
    };
    sort(A.begin(),A.end(),comp);
    vector<Activity> final;
    if(Rec(A, final)) return final;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool noOverlaps(const std::vector<Activity> &acts) {
    for(unsigned int i = 0; i < acts.size(); i++) {
        Activity A1 = acts.at(i);
        for(unsigned int j = i + 1; j < acts.size(); j++) {
            Activity A2 = acts.at(j);
            if(A1.overlaps(A2)) return false;
        }
    }
    return true;
}

TEST(TP2_Ex4, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = activitySelectionBacktracking(A);
    EXPECT_EQ(V.size(), 3 );
    EXPECT_EQ(noOverlaps(V), true);
}