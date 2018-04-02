#include "Game.h"

GameObject* player;
GameObject* car;

Game::Game() {

}

Game::~Game() {
  
}


void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
  int flags = 0;

  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems Initialized!...\n";

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if (window) {
      std::cout << "Window created!\n";
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer created!\n";
    }
    
    isRunning = true;
  } else {
    isRunning = false;
  }

  player = new GameObject("../assets/player.png", renderer, 0, 0);
  car = new GameObject("../assets/car.png", renderer, 150, 150);
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;

    default: 
      break;
  }
}

void Game::update() {
  player->Update();
  car->Update();
}

void Game::render() {
  SDL_RenderClear(renderer);
  
  player->Render();
  car->Render();

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned.\n";
}