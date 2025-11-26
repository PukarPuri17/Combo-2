#ifndef CTABLE_H
#define CTABLE_H

#include <vector>
#include <utility>
#include <string>

class CTable {
private:
    std::vector<std::pair<int, int>> playedPieces;
    int headValue;
    int tailValue;

public:
    CTable();
    ~CTable();
    
    void placeFirstPiece(const std::pair<int, int>& piece);
    bool placePiece(const std::pair<int, int>& piece);
    void getEnds(int& head, int& tail) const;
    void displayTable() const;
    void displayDominoTrain() const;
};

#endif