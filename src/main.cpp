#include <iostream>
#include "Dominoes/CDominoes.h"
#include "Dominoes/CPlayer.h"
#include "Table/CTable.h"

int main() {
    std::cout << "=== Dominoes Game Test ===" << std::endl;
    
    // Setup game components
    CDominoes game;
    CPlayer player1("Player 1");
    CPlayer player2("Player 2");
    CTable table;
    
    // Distribute pieces
    player1.addToHand(game.drawPieces(10));
    player2.addToHand(game.drawPieces(10));
    
    // Display initial state
    std::cout << "\n--- INITIAL STATE ---" << std::endl;
    player1.displayHand();
    player2.displayHand();
    std::cout << "Available pieces left: " << game.getAvailableCount() << std::endl;
    table.displayTable();
    
    // Test: Place first piece to start the game
    std::cout << "\n--- STARTING GAME ---" << std::endl;
    std::pair<int, int> firstPiece = std::make_pair(6, 6); // Using double-six to start
    table.placeFirstPiece(firstPiece);
    table.displayTable();
    
    // Test: Get current head and tail
    int head, tail;
    table.getEnds(head, tail);
    std::cout << "Current ends - Head: " << head << ", Tail: " << tail << std::endl;
    
    // Test matching logic with actual table
    std::cout << "\n--- MATCHING TEST ---" << std::endl;
    std::cout << "Player 1 can play: " << (player1.canPlay(head, tail) ? "YES" : "NO") << std::endl;
    std::cout << "Player 2 can play: " << (player2.canPlay(head, tail) ? "YES" : "NO") << std::endl;
    
    // Test: Try to place a piece from player's hand
    std::cout << "\n--- PLACING PIECE TEST ---" << std::endl;
    bool foundMatch;
    std::pair<int, int> pieceToPlay = player1.findMatchingPiece(head, tail, foundMatch);
    
    if (foundMatch) {
        std::cout << "Player 1 plays: [" << pieceToPlay.first << "|" << pieceToPlay.second << "]" << std::endl;
        table.placePiece(pieceToPlay);
        table.displayTable();
        
        // Update ends after placement
        table.getEnds(head, tail);
        std::cout << "New ends - Head: " << head << ", Tail: " << tail << std::endl;
    } else {
        std::cout << "Player 1 cannot play any piece!" << std::endl;
    }
    
    // Display final player hands
    std::cout << "\n--- FINAL STATE ---" << std::endl;
    player1.displayHand();
    player2.displayHand();
    std::cout << "Player 1 pieces left: " << player1.getHandSize() << std::endl;
    std::cout << "Player 2 pieces left: " << player2.getHandSize() << std::endl;
    
    // Test win conditions
    std::cout << "\n--- WIN CONDITIONS ---" << std::endl;
    std::cout << "Player 1 hand empty: " << (player1.isHandEmpty() ? "YES - WINS!" : "NO") << std::endl;
    std::cout << "Player 2 hand empty: " << (player2.isHandEmpty() ? "YES - WINS!" : "NO") << std::endl;
    
    std::cout << "\n=== Test Complete ===" << std::endl;
    return 0;
}