#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include "logic.cpp"

int main() {
    cout << "=========================================" << endl;
    cout << "   TESTER BALATRO HAND CHECKER (DAMAR)   " << endl;
    cout << "=========================================\n" << endl;

    // Test Case 1: Royal Flush (10, J, Q, K, A Spade)
    vector<Card> hand1 = {
        {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'}, {14, 'S'}
    };
    cout << "Test 1 -> Hasil Program: " << checkPokerHand(hand1) << " | Target: Royal Flush" << endl;

    // Test Case 2: Full House (3 buah King, 2 buah 10)
    vector<Card> hand2 = {
        {13, 'H'}, {13, 'D'}, {13, 'C'}, {10, 'S'}, {10, 'H'}
    };
    cout << "Test 2 -> Hasil Program: " << checkPokerHand(hand2) << " | Target: Full House" << endl;

    // Test Case 3: Flush (5 kartu Hati dengan nilai acak)
    vector<Card> hand3 = {
        {2, 'H'}, {5, 'H'}, {9, 'H'}, {11, 'H'}, {13, 'H'}
    };
    cout << "Test 3 -> Hasil Program: " << checkPokerHand(hand3) << " | Target: Flush" << endl;

    // Test Case 4: Pair (Sepasang angka 8)
    vector<Card> hand4 = {
        {8, 'C'}, {8, 'D'}, {3, 'S'}, {5, 'H'}, {12, 'C'}
    };
    cout << "Test 4 -> Hasil Program: " << checkPokerHand(hand4) << " | Target: Pair" << endl;

    cout << "\n=========================================" << endl;
    cout << "Pengujian Selesai!" << endl;

    return 0;
}