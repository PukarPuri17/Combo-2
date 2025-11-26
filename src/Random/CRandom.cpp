#include "CRandom.h"
#include <random>
#include <iostream>

CRandom::CRandom() {
    std::cout << "CRandom Constructor: Random generator initialized" << std::endl;
}

CRandom::~CRandom() {
    std::cout << "CRandom Destructor: Cleaning up" << std::endl;
}

// Requirement #8: Random uniform distribution for first player
int CRandom::selectFirstPlayer() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    int firstPlayer = dis(gen);
    std::cout << "Random first player selected: " << firstPlayer << std::endl;
    return firstPlayer;
}

int CRandom::getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}