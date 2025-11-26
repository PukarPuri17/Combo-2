#ifndef CDOMINOES_H
#define CDOMINOES_H

#include <vector>
#include <utility> // for std::pair

class CDominoes {
private:
    std::vector<std::pair<int, int>> pieces;  // All 28 domino pieces
    std::vector<std::pair<int, int>> availablePieces;  // Remaining pieces pool
    
public:
    CDominoes();   // Constructor - Requirement #1
    ~CDominoes();  // Destructor - Requirement #1
    
    // Requirement #2: Initialize pieces with random uniform distribution
    void initializePieces();
    
    // Requirement #4: Distribute pieces to players
    std::vector<std::pair<int, int>> drawPieces(int count);
    
    // Get available pieces count
    int getAvailableCount() const;
    
    // Display pieces for debugging
    void displayPieces() const;
};

#endif