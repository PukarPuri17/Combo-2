#include "CDominoes.h"
#include <iostream>
#include <algorithm>
#include <random>

// Constructor - Requirement #1
CDominoes::CDominoes() {
    std::cout << "CDominoes Constructor: Initializing game..." << std::endl;
    initializePieces();
}

// Destructor - Requirement #1  
CDominoes::~CDominoes() {
    std::cout << "CDominoes Destructor: Cleaning up..." << std::endl;
    pieces.clear();
    availablePieces.clear();
}

// Requirement #2: Initialize all 28 domino pieces
void CDominoes::initializePieces() {
    pieces.clear();
    
    // Create all possible domino combinations (0-0 to 6-6)
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pieces.push_back(std::make_pair(i, j));
        }
    }
    
    // Copy to available pieces
    availablePieces = pieces;
    
    // Requirement #2: Random uniform distribution shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(availablePieces.begin(), availablePieces.end(), g);
    
    std::cout << "Initialized " << pieces.size() << " domino pieces" << std::endl;
}

// Requirement #4: Draw pieces from available pool
std::vector<std::pair<int, int>> CDominoes::drawPieces(int count) {
    std::vector<std::pair<int, int>> drawn;
    
    for (int i = 0; i < count && !availablePieces.empty(); i++) {
        drawn.push_back(availablePieces.back());
        availablePieces.pop_back();
    }
    
    return drawn;
}

int CDominoes::getAvailableCount() const {
    return availablePieces.size();
}

void CDominoes::displayPieces() const {
    std::cout << "All domino pieces: ";
    for (const auto& piece : pieces) {
        std::cout << "[" << piece.first << "|" << piece.second << "] ";
    }
    std::cout << std::endl;
}