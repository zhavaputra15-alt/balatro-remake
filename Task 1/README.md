# Task 1 - Card Game Simulation

## Anggota Kelompok
- Zhava Erlangga Rhenata Putra (Core Architecture)
- Damar (Shop System & Modifiers)

## Refleksi Design Pattern
1. **Strategy Pattern**: Digunakan pada `IScoringRule` dan `IRewardRule` agar logika perhitungan skor dan reward dapat diubah atau disesuaikan tanpa mengubah struktur utama `RunSession`.
2. **Decorator Pattern**: Digunakan untuk menambahkan variasi atau modifier pada aturan hadiah dasar.
3. **Factory Pattern**: Digunakan untuk pembuatan instance `IInputGenerator` secara fleksibel.