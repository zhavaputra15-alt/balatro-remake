#pragma once

class BlindRule {
private:
    int targetScore; // Target skor minimum untuk menang

public:
    // Constructor untuk menentukan target skor awal (misal: 300)
    BlindRule(int target = 300);

    // Fungsi untuk mengecek apakah skor mencapai target
    bool checkBlind(int score);
};