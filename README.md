# Soil
Soil
Soil is a 2D farming simulation game built with C++ and the iGraphics library. Step into the boots of a farmer, cultivate crops, raise animals, and sell your goods at the market to grow your farm into a thriving enterprise.

🌟 Features
Dynamic Menu System: A fully interactive main menu with options to start a new game, view high scores, and quit.

Two Explorable Maps: Travel between your home farm and the bustling town market via a ship.

Farming Mechanics: Plant seeds, watch your crops grow through multiple stages, and harvest them for food.

Upgradable Farm: Purchase a special crop bed for faster growth and hire a worker to help on your farm.

Animal Husbandry: Animated cows roam your farm, and you can collect milk to sell.

In-Game Economy: Manage your money to buy seeds and upgrades. Sell food and milk at the market to earn more.

Arcade Mini-Game: Take a break from farming and test your reflexes with a fun color-matching mini-game at the market.

Persistent Leaderboard: Your score (total money) is saved to a file, and the top 5 scores are displayed on the leaderboard.

Day/Night Cycle: An in-game clock tracks the time of day.

Collision System: A tile-based collision system prevents the player from walking through obstacles.

🎮 How to Play
Controls
Movement: W, A, S, D or Arrow Keys

Interact: E (Used for planting/harvesting crops, entering the shop, and starting the arcade game)

Inventory: I (Press and hold to view your current money, food, milk, and seeds)

Return to Menu: ESC (From the in-game screen or leaderboard)

Mouse: Used to navigate the main menu and play the arcade mini-game.

Gameplay
Enter your name in the console when the game starts.

From the main menu, select New Game.

Explore your farm, plant your initial seeds, and collect milk from the cow area.

Travel to the market by walking onto the ship at the dock.

In the market, visit the shop to sell your produce or buy more seeds and special upgrades.

Try your luck at the arcade machine for a chance to win extra money!

When you're ready to finish, select Quit from the main menu to save your score.

🛠️ Setup and Installation
This project is built using the iGraphics library, which is a wrapper for OpenGL GLUT.

Prerequisites
A C++ compiler (like g++).

A development environment configured to work with iGraphics.h and GLUT (e.g., Code::Blocks).

The required DLL files for GLUT must be accessible by the executable.

Running the Game
Clone the repository or download the source files.

Set up the project folder structure as follows:

/YourProjectFolder
|-- main.cpp
|-- menu.hpp
|-- elements.hpp
|-- movement.hpp
|-- scores.txt      (will be created automatically)
|-- /img/           (Contains all .bmp and .png image assets)
|-- /Audios/        (Contains all .mp3 audio files)


Compile the main.cpp file with your C++ compiler, linking the necessary graphics libraries (-lopengl32 -lfreeglut -lglu32 -lgdi32).

Run the generated executable.

📂 File Structure
main.cpp: The main entry point of the game. Handles the game loop, drawing logic, and event handling.

menu.hpp: Manages the main menu, leaderboard display, and related user interactions.

elements.hpp: Defines and controls all non-player game elements, such as crops, animals, the shop, and the in-game world.

movement.hpp: Handles player character movement, animation, and collision detection.
