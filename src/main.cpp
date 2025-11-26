#include <iostream>
#include "Dominoes/CDominoes.h"

int main() {
    std::cout << "=== Dominoes Game Test ===" << std::endl;
    
    // Test Requirement #1: Constructor/Destructor
    CDominoes game;
    
    // Test Requirement #2: Piece initialization
    game.displayPieces();
    
    // Test Requirement #4: Drawing pieces
    auto player1Pieces = game.drawPieces(10);
    auto player2Pieces = game.drawPieces(10);
    
    std::cout << "Player 1 got " << player1Pieces.size() << " pieces" << std::endl;
    std::cout << "Player 2 got " << player2Pieces.size() << " pieces" << std::endl;
    std::cout << "Available pieces left: " << game.getAvailableCount() << std::endl;
    
    std::cout << "=== Test Complete ===" << std::endl;
    return 0;
}