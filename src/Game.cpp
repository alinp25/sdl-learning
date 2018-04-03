#include "Game.h"

GameObject* player;
GameObject* car;

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {
  
}


void Game::init(const char* title, int width, int height, bool fullscreen) {
  int flags = 0;

  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems Initialized!...\n";

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
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

  player = new GameObject("../assets/player.png", 0, 0);
  car = new GameObject("../assets/car.png", 150, 150);
  map = new Map();
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
  
  map->DrawMap();
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