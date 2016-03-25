//STL
#include <iostream>
#include <vector>
// gtest
#include <gtest/gtest.h>

#define NO_PRINT
//#define USE_INPUT

void printTrainInfo(const std::vector<std::size_t> & trainMainTrack,
    const std::vector<std::size_t> & trainSubTrack)
{
#ifndef NO_PRINT
    for(auto i = trainMainTrack.rbegin(); i != trainMainTrack.rend(); ++i)
        std::cout << *i << ' ';
    std::cout << "; ";

    for(auto i = trainSubTrack.rbegin(); i != trainSubTrack.rend(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
#endif
}

std::vector<std::size_t>::iterator
findExpectTrainInMain(
    std::vector<std::size_t> & trainMainTrack,
    std::size_t expectTrain)
{
    std::vector<std::size_t>::iterator it;
    for(it = trainMainTrack.begin(); it != trainMainTrack.end(); ++it) {
        if (*it == expectTrain)
            break;
    }
    return it;
}

void FindExpectDoCopy(
    std::vector<std::size_t> & trainMainTrack,
    std::vector<std::size_t>::iterator it,
    std::vector<std::size_t> & trainSubTrack)
{
    auto copyIt = it;
    for(copyIt = trainMainTrack.begin(); copyIt != it; ++copyIt) {
        trainSubTrack.push_back(*copyIt);
        std::cout << *copyIt << " move to the subTrack" << std::endl;
        printTrainInfo(trainMainTrack, trainSubTrack);
    }
}

void ScheduleTrains(std::vector<std::size_t> & trainMainTrack,
    std::vector<std::size_t> & trainSubTrack)
{
    std::size_t n = trainMainTrack.size();
    std::size_t expectTrain = 1;

    while(expectTrain != n + 1) {
        std::vector<std::size_t>::iterator it;
        it = findExpectTrainInMain(trainMainTrack, expectTrain);
        if(it != trainMainTrack.end()) {
            FindExpectDoCopy(trainMainTrack, it, trainSubTrack);
            std::cout << *it << " move to the right from Maintrack." << std::endl;
            trainMainTrack.erase(trainMainTrack.begin(), it + 1);
            printTrainInfo(trainMainTrack, trainSubTrack);
            ++expectTrain;
        } else {
            if(expectTrain == trainSubTrack.back()){
                std::cout << trainSubTrack.back() << " move to the right from Subtrack." << std::endl;
                trainSubTrack.erase(trainSubTrack.end() - 1);
                printTrainInfo(trainMainTrack, trainSubTrack);
                ++expectTrain;
            } else {
                std::cout << "Can't do a success train scheduling." << std::endl;
                break;
            }
        }
    }

    std::cout << std::endl;
}

TEST(ScheduleTest, test1) {
    std::vector<std::size_t> trainMainTrack {5, 3, 1, 2, 4};
    std::vector<std::size_t> trainSubTrack;
    for(auto & i : trainMainTrack) std::cout << i << ' '; std::cout << std::endl;
    ScheduleTrains(trainMainTrack, trainSubTrack);
}

TEST(ScheduleTest, test2) {
    std::vector<std::size_t> trainMainTrack {4, 1, 3, 5, 2};
    std::vector<std::size_t> trainSubTrack;
    for(auto & i : trainMainTrack) std::cout << i << ' '; std::cout << std::endl;
    ScheduleTrains(trainMainTrack, trainSubTrack);
}

TEST(ScheduleTest, test3) {
    std::vector<std::size_t> trainMainTrack {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<std::size_t> trainSubTrack;
    for(auto & i : trainMainTrack) std::cout << i << ' '; std::cout << std::endl;
    ScheduleTrains(trainMainTrack, trainSubTrack);
}

TEST(ScheduleTest, test4) {
    std::vector<std::size_t> trainMainTrack {5, 4, 3, 2, 1};
    std::vector<std::size_t> trainSubTrack;
    for(auto & i : trainMainTrack) std::cout << i << ' '; std::cout << std::endl;
    ScheduleTrains(trainMainTrack, trainSubTrack);
}

TEST(ScheduleTest, test5) {
    std::vector<std::size_t> trainMainTrack {1, 3, 5, 7, 9, 8, 6, 4, 2};
    std::vector<std::size_t> trainSubTrack;
    for(auto & i : trainMainTrack) std::cout << i << ' '; std::cout << std::endl;
    ScheduleTrains(trainMainTrack, trainSubTrack);
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

#ifdef USE_INPUT
    while(true) {
        std::size_t n = 0;
        std::vector<std::size_t> trainMainTrack;
        std::vector<std::size_t> trainSubTrack;

        std::cin >> n;
        std::size_t train = 0;
        trainMainTrack.clear();
        trainSubTrack.clear();
        for(std::size_t i = 0; i < n; ++i) {
            std::cin >> train;
            trainMainTrack.push_back(train);
        }

        ScheduleTrains(trainMainTrack, trainSubTrack);
    }
#endif

    return RUN_ALL_TESTS();
}
