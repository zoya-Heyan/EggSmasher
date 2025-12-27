# EggSmasherEgg Smasher V3 - Terminal Roguelike Game

Egg Smasher V3 is a terminal-based roguelike game written in C++. Players smash eggs to earn money, hatch ducks, and collect rare legendary eggs. The game features a rarity system, a shop with items, and passive income from ducks, providing a simple but engaging strategy gameplay in the terminal.

Features
	•	Rarity System: Eggs can be Common, Rare, Epic, or Legendary.
	•	Random Events: Each egg smash triggers a random event based on rarity.
	•	Ducks: Hatch ducks to earn passive income each turn.
	•	Shop: Purchase items like Lucky Charm to increase rare egg chances.
	•	Terminal Animations: ASCII animations for smashing eggs and hatching ducks.
	•	Modular Code Structure: Split into multiple header and cpp files for maintainability.

Gameplay
	1.	Start the game by running the compiled executable.
	2.	The HUD shows your current money, number of ducks, and item status.
	3.	Press Enter to smash an egg.
	4.	Based on the egg’s rarity, you may gain money, hatch ducks, or trigger legendary events.
	5.	Ducks provide passive income each turn.
	6.	Press S to open the shop and purchase items.
	7.	Press Q to quit the game.

Requirements
	•	C++11 or higher
	•	macOS / Linux terminal (supports ANSI escape codes for colors)
	•	g++ or clang++ compiler

Compilation

```
# Compile all .cpp files
g++ main.cpp EggGame.cpp Terminal.cpp suiji.cpp -o EggSmasher

# Run the game
./EggSmasher
```

Project Structure

```
EggSmasher/
├── main.cpp          # Game entry point
├── EggGame.h         # EggGame class declaration
├── EggGame.cpp       # EggGame class implementation
├── Terminal.h        # Terminal utilities (clear screen, colors)
├── Terminal.cpp      # Terminal functions implementation
├── Rarity.h          # Enum for egg rarity
├── Item.h            # Item struct for shop
├── suiji.h           # Random number generation header
└── suiji.cpp         # Random number generation implementation
```

Future Improvements
	•	Add save/load functionality to persist game progress.
	•	Add multiple items and achievements.
	•	Implement advanced events and boss eggs.
	•	Make it cross-platform compatible (Windows terminals).

Author
	•	Chen (陈先生) - University of Nottingham Ningbo China

License

MIT License