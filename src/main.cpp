#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "Dominoes/CDominoes.h"
#include "Dominoes/CPlayer.h"
#include "Table/CTable.h"
#include "Random/CRandom.h"

std::mutex gameMutex;
bool gameOver = false;
int currentPlayer = 1; // 1 or 2

void playerTurn(CPlayer* player, CTable* table, int playerId) {
    while (!gameOver) {
        // Wait for this player's turn
        {
            std::lock_guard<std::mutex> lock(gameMutex);
            if (currentPlayer != playerId || gameOver) {
                continue;
            }
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate thinking
        
        std::lock_guard<std::mutex> lock(gameMutex);
        
        std::cout << "\n--- Player " << playerId << "'s Turn ---" << std::endl;
        std::cout << "Pieces in hand: " << player->getHandSize() << std::endl;
        
        int head, tail;
        table->getEnds(head, tail);
        std::cout << "Table ends - Head: " << head << ", Tail: " << tail << std::endl;
        
        if (player->canPlay(head, tail)) {
            bool foundMatch;
            std::pair<int, int> pieceToPlay = player->findMatchingPiece(head, tail, foundMatch);
            
            if (foundMatch) {
                std::cout << "Player " << playerId << " plays: [" << pieceToPlay.first << "|" << pieceToPlay.second << "]" << std::endl;
                table->placePiece(pieceToPlay);
                table->displayTable();
                
                // Check win condition
                if (player->isHandEmpty()) {
                    std::cout << "\n🎉 PLAYER " << playerId << " WINS! 🎉" << std::endl;
                    std::cout << "All pieces placed successfully!" << std::endl;
                    gameOver = true;
                }
            }
        } else {
            std::cout << "Player " << playerId << " cannot play - must pass" << std::endl;
        }
        
        // Switch to other player if game not over
        if (!gameOver) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            std::cout << "Switching to Player " << currentPlayer << std::endl;
        }
        
        break; // Remove this for continuous turns
    }
}

int main() {
    std::cout << "=== MULTI-THREADED DOMINOES GAME ===" << std::endl;
    
    // Setup game components
    CDominoes game;
    CPlayer player1("Player 1");
    CPlayer player2("Player 2"); 
    CTable table;
    CRandom random;
    
    // Distribute pieces
    player1.addToHand(game.drawPieces(10));
    player2.addToHand(game.drawPieces(10));
    
    // Display initial state
    std::cout << "\n--- INITIAL SETUP ---" << std::endl;
    player1.displayHand();
    player2.displayHand();
    std::cout << "Available pieces: " << game.getAvailableCount() << std::endl;
    
    // Start with first piece (manual placement for demo)
    std::cout << "\n--- STARTING GAME ---" << std::endl;
    std::pair<int, int> firstPiece = std::make_pair(6, 6);
    table.placeFirstPiece(firstPiece);
    table.displayTable();
    
    // Randomly choose first player
    currentPlayer = random.selectFirstPlayer() + 1; // Convert 0/1 to 1/2
    std::cout << "First player: " << currentPlayer << std::endl;
    
    // Multi-threaded game play - play 3 rounds for demo
    std::cout << "\n--- MULTI-THREADED GAME PLAY ---" << std::endl;
    
    for (int round = 0; round < 3 && !gameOver; round++) {
        std::cout << "\n--- Round " << (round + 1) << " ---" << std::endl;
        
        std::thread t1(playerTurn, &player1, &table, 1);
        std::thread t2(playerTurn, &player2, &table, 2);
        
        t1.join();
        t2.join();
        
        if (gameOver) break;
    }
    
    // Final game state
    std::cout << "\n--- FINAL GAME STATE ---" << std::endl;
    table.displayTable();
    std::cout << "Player 1 pieces left: " << player1.getHandSize() << std::endl;
    std::cout << "Player 2 pieces left: " << player2.getHandSize() << std::endl;
    
    if (!gameOver) {
        std::cout << "Game ended after demo rounds" << std::endl;
    }
    
    std::cout << "\n=== Multi-threaded Game Complete ===" << std::endl;
    return 0;
}