#ifndef RARITY_H
#define RARITY_H

enum class Rarity {
    COMMON,
    RARE,
    EPIC,
    LEGENDARY
};

inline const char* rarityName(Rarity r) {
    switch (r) {
        case Rarity::COMMON: return "Common";
        case Rarity::RARE: return "Rare";
        case Rarity::EPIC: return "Epic";
        case Rarity::LEGENDARY: return "Legendary";
    }
    return "";
}

#endif
