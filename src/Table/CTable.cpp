#include "CTable.h"
#include <iostream>
#include <iomanip>

CTable::CTable() : headValue(-1), tailValue(-1) {
    std::cout << "CTable Constructor: Game table initialized" << std::endl;
}

CTable::~CTable() {
    std::cout << "CTable Destructor: Cleaning up table" << std::endl;
    playedPieces.clear();
}

void CTable::placeFirstPiece(const std::pair<int, int>& piece) {
    playedPieces.push_back(piece);
    headValue = piece.first;
    tailValue = piece.second;
    std::cout << "First piece placed: [" << headValue << "|" << tailValue << "]" << std::endl;
}

bool CTable::placePiece(const std::pair<int, int>& piece) {
    if (piece.first == headValue || piece.second == headValue) {
        int newHead = (piece.first == headValue) ? piece.second : piece.first;
        playedPieces.insert(playedPieces.begin(), piece);
        headValue = newHead;
        std::cout << "Piece placed at HEAD: [" << piece.first << "|" << piece.second << "] -> New head: " << headValue << std::endl;
        return true;
    }
    else if (piece.first == tailValue || piece.second == tailValue) {
        int newTail = (piece.first == tailValue) ? piece.second : piece.first;
        playedPieces.push_back(piece);
        tailValue = newTail;
        std::cout << "Piece placed at TAIL: [" << piece.first << "|" << piece.second << "] -> New tail: " << tailValue << std::endl;
        return true;
    }
    return false;
}

void CTable::getEnds(int& head, int& tail) const {
    head = headValue;
    tail = tailValue;
}

void CTable::displayTable() const {
    std::cout << "\n=== DOMINOES TABLE ===" << std::endl;
    std::cout << "Head: " << headValue << " | Tail: " << tailValue << std::endl;
    std::cout << "Pieces on table: " << playedPieces.size() << std::endl;
    displayDominoTrain();
    std::cout << "======================" << std::endl;
}

void CTable::displayDominoTrain() const {
    std::cout << "Domino train: ";
    for (const auto& piece : playedPieces) {
        std::cout << "[" << piece.first << "|" << piece.second << "] ";
    }
    std::cout << std::endl;
}