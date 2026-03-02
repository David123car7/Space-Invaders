# Space-Invaders

Re-creation of Space Invaders game, built using  using C++ and the raylib library.

# Setup

## Install required tools

You need a GCC (or alternative C99 compiler), make and git (to download raylib repo).

```bash
sudo apt install build-essential git
```

## Install required libraries

You need to install some required libraries; ALSA for audio, Mesa for OpenGL accelerated graphics and X11 for windowing system.

```bash
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
```

## Build raylib using Cmake

```bash
sudo apt install cmake
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake ..
make
sudo make install
sudo ldconfig
```







