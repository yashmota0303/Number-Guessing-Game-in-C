# Number-Guessing-Game-in-C
# Advanced Number Guessing Game in C

An interactive, feature-packed Command Line Interface (CLI) guessing game written in C. Unlike standard guessing games, this project introduces strategic lifelines, random traps, dynamic difficulty scaling, a shifting boss battle mode, and a blindfold event.

## Features

### 1. Dynamic Difficulty Levels
- **Easy Mode:** Range 1 to 10 | 5 attempts
- **Medium Mode:** Range 1 to 25 | 10 attempts
- **Hard Mode:** Range 1 to 100 | 15 attempts
- **Boss Battle:** Range 1 to 400 | 25 attempts

### 2. Gameplay Mechanics & Game Modes
- **Boss Battle Position Shift:** Every 3 attempts during Boss Mode, the secret number shifts position dynamically (`+2` or `-2`).
- **Trap System:** In Hard Mode, a hidden trap number can trigger upon generation, deducting 2 attempts immediately.
- **Blindfold Mode:** Triggers periodically on Hard Mode, clearing the terminal history after a brief delay to force memory-based play.
- **Proximity Feedback:** Hints inform players if a guess is "Too far" or "Seriously far" relative to the target number.

### 3. Interactive Lifelines
Players can trigger a lifeline menu during their turn by entering `0` as their guess (costs no attempts):
- **50/50 Cut:** Narrows down the target number range relative to the midpoint of the maximum boundary.
- **Clamp Range:** Clamps the target within a tighter window (`target - 5` to `target + 5`).
- **Elimination:** Randomly generates and displays 3 incorrect numbers to rule out choices.

### 4. High Scores and Win Streaks
- **Streak Tracking:** Consecutive correct guesses build a win streak.
- **Bonus Lifelines:** Every 3 consecutive wins grant 1 additional lifeline.
- **Session High Score Tracking:** Keeps record of the lowest attempt counts achieved for Easy, Medium, and Hard difficulties during the session.

## Dependencies and Requirements

- **Operating System:** Windows (uses `windows.h` for system pause delays and `cls` console command).
- **Compiler:** Any standard C compiler (e.g., GCC, MinGW, MSVC).

## Compilation and Execution

To compile and run locally using GCC:

```bash
gcc guess_gameV2.c -o guessing_game
./guessing_game

IF YOU FIND ANY BUGS OR PROBLEMS, DO LET ME KNOW AND CAN GET A FREE BURGER.₹





₹ means that burger value should be upto ₹100 only..
