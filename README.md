# Snake Game

## Description
A classic Snake game implemented in C++ as a Windows console application. Control the snake, eat fruits to grow and increase your score, and avoid colliding with the borders. This project demonstrates real-time console rendering, keyboard input handling, and basic game loop mechanics using the Windows API.

## Features
- Console-based gameplay
- Real-time movement
- Score tracking
- Snake grows after eating fruits
- Supports both WASD and Arrow Keys

## Controls

| Key            | Action      |
|----------------|-------------|
| W / ↑          | Move Up     |
| A / ←          | Move Left   |
| S / ↓          | Move Down   |
| D / →          | Move Right  |

## Requirements
- Windows operating system
- Visual Studio (recommended) or MinGW (g++)
- This project depends on the following Windows-specific libraries:
  - `windows.h`
  - `conio.h`

> Note: Because it relies on these Windows-only libraries, this project **will not compile or run on Linux or macOS**.

## How to Run

### Visual Studio
1. Clone the repository
2. Open the project in Visual Studio
3. Build the solution
4. Press `Ctrl + F5` to run without debugging

### MinGW
```bash
g++ Snake.cpp -o Snake.exe
Snake.exe
```

## Can I Play It Directly on GitHub?
No. GitHub only hosts and displays source code — it cannot compile or execute interactive C++ console applications. To play the game, you must clone or download this repository and run it locally on a Windows machine using Visual Studio or MinGW, as described above.

## Future Improvements
- Self collision detection
- Difficulty levels
- High score saving
- Better graphics

## License
This project is intended for educational purposes.
