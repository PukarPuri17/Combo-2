#ifndef CPLAYER_H
#define CPLAYER_H

#include <vector>
#include <utility> 
#include <string>

class CPlayer {
private:
    std::vector<std::pair<int, int>> hand;  // Player's pieces
    std::string name;

public:
    CPlayer(const std::string& playerName);
    ~CPlayer();
    
    // Add pieces to player's hand
    void addToHand(const std::vector<std::pair<int, int>>& newPieces);
    
    // Requirement #6: Check if player can play a piece
    bool canPlay(int head, int tail) const;
    
    // Requirement #6: Find a matching piece
    std::pair<int, int> findMatchingPiece(int head, int tail, bool& foundMatch);
    
    // Remove piece from hand
    void removePiece(const std::pair<int, int>& piece);
    
    // Get hand size
    int getHandSize() const;
    
    // Display player's hand
    void displayHand() const;
    
    // Check if hand is empty (win condition)
    bool isHandEmpty() const;
};

#endif