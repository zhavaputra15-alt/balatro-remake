#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Struktur Kartu
struct Card {
    int value;    // Nilai: 2-10, J=11, Q=12, K=13, A=14
    char suit;    // Kembang: 'H', 'D', 'C', 'S'
};

// --- FUNGSI HELPER (PEMBANTU) ---

// 1. Cek Flush (Semua kembang sama)
bool isFlush(const vector<Card>& cards) {
    char firstSuit = cards[0].suit;
    for (size_t i = 1; i < cards.size(); i++) {
        if (cards[i].suit != firstSuit) return false;
    }
    return true;
}

// 2. Cek Straight (Nilai berurutan)
bool isStraight(const vector<Card>& cards) {
    vector<int> vals;
    for (const auto& c : cards) vals.push_back(c.value);
    sort(vals.begin(), vals.end());

    // Kasus A-2-3-4-5 (As bernilai 1)
    bool isAceLowStraight = (vals[0] == 2 && vals[1] == 3 && vals[2] == 4 && vals[3] == 5 && vals[4] == 14);
    if (isAceLowStraight) return true;

    // Cek urutan normal
    for (size_t i = 0; i < vals.size() - 1; i++) {
        if (vals[i + 1] != vals[i] + 1) return false;
    }
    return true;
}

// Menghitung jumlah kartu yang nilainya sama
map<int, int> getFrequencyMap(const vector<Card>& cards) {
    map<int, int> freq;
    for (const auto& c : cards) {
        freq[c.value]++;
    }
    return freq;
}

// 3. Royal Flush
bool isRoyalFlush(const vector<Card>& cards) {
    vector<int> vals;
    for (const auto& c : cards) vals.push_back(c.value);
    sort(vals.begin(), vals.end());
    
    bool isTenToAce = (vals[0] == 10 && vals[1] == 11 && vals[2] == 12 && vals[3] == 13 && vals[4] == 14);
    return isFlush(cards) && isTenToAce;
}

// 4. Straight Flush
bool isStraightFlush(const vector<Card>& cards) {
    return isFlush(cards) && isStraight(cards) && !isRoyalFlush(cards);
}

// 5. Four of a Kind
bool isFourOfAKind(const vector<Card>& cards) {
    auto freq = getFrequencyMap(cards);
    for (auto const& pair_item : freq) {
        if (pair_item.second == 4) return true;
    }
    return false;
}

// 6. Full House
bool isFullHouse(const vector<Card>& cards) {
    auto freq = getFrequencyMap(cards);
    bool hasThree = false, hasTwo = false;
    for (auto const& pair_item : freq) {
        if (pair_item.second == 3) hasThree = true;
        if (pair_item.second == 2) hasTwo = true;
    }
    return hasThree && hasTwo;
}

// 7. Three of a Kind
bool isThreeOfAKind(const vector<Card>& cards) {
    auto freq = getFrequencyMap(cards);
    bool hasThree = false;
    for (auto const& pair_item : freq) {
        if (pair_item.second == 3) hasThree = true;
    }
    return hasThree && !isFullHouse(cards);
}

// 8. Two Pair
bool isTwoPair(const vector<Card>& cards) {
    auto freq = getFrequencyMap(cards);
    int pairCount = 0;
    for (auto const& pair_item : freq) {
        if (pair_item.second == 2) pairCount++;
    }
    return pairCount == 2;
}

// 9. Pair
bool isPair(const vector<Card>& cards) {
    auto freq = getFrequencyMap(cards);
    int pairCount = 0;
    for (auto const& pair_item : freq) {
        if (pair_item.second == 2) pairCount++;
    }
    return pairCount == 1;
}

// --- FUNGSI UTAMA ELSE IF (LOGIKA ZHAVA) ---
string checkPokerHand(vector<Card>& cards) {
    if (isRoyalFlush(cards)) {
        return "Royal Flush";
    }
    else if (isStraightFlush(cards)) {
        return "Straight Flush";
    }
    else if (isFourOfAKind(cards)) {
        return "Four of a Kind";
    }
    else if (isFullHouse(cards)) {
        return "Full House";
    }
    else if (isFlush(cards)) {
        return "Flush";
    }
    else if (isStraight(cards)) {
        return "Straight";
    }
    else if (isThreeOfAKind(cards)) {
        return "Three of a Kind";
    }
    else if (isTwoPair(cards)) {
        return "Two Pair";
    }
    else if (isPair(cards)) {
        return "Pair";
    }
    else {
        return "High Card";
    }
}