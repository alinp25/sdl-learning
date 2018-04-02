#pragma once

#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
  GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
  ~GameObject();

  void Update();
  void Render();

private:
  int xPos, yPos;
  SDL_Texture* objTexture;
  SDL_Rect srcRect, destRect;
  SDL_Renderer* renderer;

};