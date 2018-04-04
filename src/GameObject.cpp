#include "GameObject.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
  objTexture = TextureManager::LoadTexture(texturesheet);
  xPos = x;
  yPos = y;
}

GameObject::~GameObject() {}

void GameObject::Update() {
  xPos+=32;
  yPos+=32;

  srcRect.h = 32;
  srcRect.w = 32;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xPos;
  destRect.y = yPos;
  destRect.w = srcRect.w * 2;
  destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);  
}