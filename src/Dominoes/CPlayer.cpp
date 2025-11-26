#include "CPlayer.h"
#include <iostream>
#include <algorithm>

CPlayer::CPlayer(const std::string& playerName) : name(playerName) {
    std::cout << "Player " << name << " created" << std::endl;
}

CPlayer::~CPlayer() {
    std::cout << "Player " << name << " destroyed" << std::endl;
    hand.clear();
}

void CPlayer::addToHand(const std::vector<std::pair<int, int>>& newPieces) {
    hand.insert(hand.end(), newPieces.begin(), newPieces.end());
}

// Requirement #6: Check if player has any piece that matches head or tail
bool CPlayer::canPlay(int head, int tail) const {
    for (const auto& piece : hand) {
        if (piece.first == head || piece.first == tail || 
            piece.second == head || piece.second == tail) {
            return true;
        }
    }
    return false;
}

// Requirement #6: Find and return a matching piece
std::pair<int, int> CPlayer::findMatchingPiece(int head, int tail, bool& foundMatch) {
    for (auto it = hand.begin(); it != hand.end(); ++it) {
        // Check if piece matches head
        if (it->first == head || it->second == head) {
            std::pair<int, int> matchingPiece = *it;
            hand.erase(it);
            foundMatch = true;
            return matchingPiece;
        }
        // Check if piece matches tail  
        else if (it->first == tail || it->second == tail) {
            std::pair<int, int> matchingPiece = *it;
            hand.erase(it);
            foundMatch = true;
            return matchingPiece;
        }
    }
    foundMatch = false;
    return std::make_pair(-1, -1); // No match found
}

void CPlayer::removePiece(const std::pair<int, int>& piece) {
    auto it = std::find(hand.begin(), hand.end(), piece);
    if (it != hand.end()) {
        hand.erase(it);
    }
}

int CPlayer::getHandSize() const {
    return hand.size();
}

void CPlayer::displayHand() const {
    std::cout << name << "'s hand: ";
    for (const auto& piece : hand) {
        std::cout << "[" << piece.first << "|" << piece.second << "] ";
    }
    std::cout << std::endl;
}

bool CPlayer::isHandEmpty() const {
    return hand.empty();
}