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
- [SFML 3](https://www.sfml-dev.org/)
- [vcpkg](https://vcpkg.io/) (used for dependency management)
- CMake with [presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) support

## Build

This project uses vcpkg to fetch SFML, configured through CMake presets.

1. Set up vcpkg if you don't have it yet:

   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   ./vcpkg/bootstrap-vcpkg.sh   # or bootstrap-vcpkg.bat on Windows
   ```

2. Create a `CMakeUserPresets.json` in the project root pointing to your local vcpkg install (this file is git-ignored, as it's machine-specific):

   ```json
   {
     "version": 2,
     "configurePresets": [
       {
         "name": "default",
         "inherits": "vcpkg",
         "environment": {
           "VCPKG_ROOT": "path/to/your/vcpkg"
         }
       }
     ]
   }
   ```

   Alternatively, set the `VCPKG_ROOT` environment variable globally on your system instead.

3. Configure and build:

   ```bash
   cmake --preset=default
   cmake --build build
   ```

## Asset sources

Textures used in this project come from [**Loop Cat: The Adventure of a Cat**](https://gx.games/pl/games/qp1ok5/loop-cat-the-aventure-of-a-cat/) by Fran Nabo Romero, available on [GX Games](https://gx.games/). Used strictly for educational/testing purposes, not commercial. All rights to the artwork belong to its original author.

## License

The source code of this project is available under the [MIT License](LICENSE). The MIT license covers the code only — it does **not** apply to the textures used (see the section above).
