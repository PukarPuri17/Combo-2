#ifndef CRANDOM_H
#define CRANDOM_H

class CRandom {
public:
    CRandom();
    ~CRandom();
    
    // Requirement #8: Randomly select first player (0 or 1)
    int selectFirstPlayer();
    
    // Random number in range [min, max]
    int getRandomNumber(int min, int max);
};

#endif