# atan2-playground

A small educational C++ / SFML project, built to practice the fundamentals of game architecture: a resource manager, a fixed-timestep game loop, and separating responsibilities across classes (`Application`, `Player`, `Crosshair`, `Projectile`).

This is **not** meant to be played as a game — it's a learning exercise documenting good practices in C++/SFML. The repository is public in case it's useful to someone else learning the same things.

## Features

- WASD player movement (normalized, including diagonal movement)
- Crosshair that follows the mouse cursor
- Shooting a projectile toward the crosshair on Space, direction computed with `atan2`
- A simple resource manager for handling textures (no global variables)

## Requirements

- C++17 or newer
- CMake 3.28 or newer

## Build

This project uses FetchContent to fetch SFML 3.0.2, configured through CMake ([Dependencies.cmake](Dependencies.cmake)).

You can easily build a .sln file through [`Setup.bat`](scripts/Setup.bat) localized in `scripts/` directory

Alternatively, use:
```
cmake -B "build dir name" -S . -G "VisualStudio version"
```

## Asset sources

Textures used in this project come from [**Loop Cat: The Adventure of a Cat**](https://gx.games/pl/games/qp1ok5/loop-cat-the-aventure-of-a-cat/) by Fran Nabo Romero, available on [GX Games](https://gx.games/). Used strictly for educational/testing purposes, not commercial. All rights to the artwork belong to its original author.

## License

The source code of this project is available under the [MIT License](LICENSE). The MIT license covers the code only — it does **not** apply to the textures used (see the section above).
