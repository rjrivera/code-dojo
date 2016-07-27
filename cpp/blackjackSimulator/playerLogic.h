#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

bool basicStrat(int dealerHand, int playerHand, bool stratTable[31][31]);

void initStratTable(bool stratTable[31][31]);

void updateCount(int &currentCount, int recentCard);

#endif
