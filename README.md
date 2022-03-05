# LightTD
Tower Defense

Just a simple (partially-finished) mouse-based tower defense game run on the console.
Three types of upgradeable towers: AOE freeze, single target laser, and random rapid multi target.
Monsters are squares that fade as their health goes to 0.
Each wave increases monster health.

Requires Allegro library for the vector drawings.

Apologies for the glaringly lack of comments.

## OSX

```
brew install allegro
brew install pkg-config
gcc game.cpp $(pkg-config allegro-5 allegro_main-5 allegro_font-5 --libs --cflags)
```

leads to error :(
```
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```