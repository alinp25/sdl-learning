#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

#include <iostream>

class Game {

public:
  Game();
  ~Game();

  void init(const char* title, int width, int height, bool fullscreen);
  
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; };

  static SDL_Renderer *renderer;

private:
  bool isRunning;
  SDL_Window *window;

};
