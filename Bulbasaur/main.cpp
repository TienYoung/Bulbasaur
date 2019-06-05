#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Canvas.h"
#include "MathUtility.h"

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 640;

bool init();

SDL_Texture* loadTexture(std::string path);

void close();


SDL_Window* gWindow = nullptr;

SDL_Renderer* gRenderer = nullptr;

SDL_Texture* gTexture = nullptr;

SDL_Texture* gRenderTarget = nullptr;

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}

	else
	{
// Bulbasaur image load
// 		gTexture = loadTexture("Resources/Bulbasaur.png");
// 		SDL_Rect texRect;
// 		SDL_QueryTexture(gTexture, nullptr, nullptr, &texRect.w, &texRect.h);
// 		texRect.x = SCREEN_WIDTH / 2 - texRect.w / 2;
// 		texRect.y = SCREEN_HEIGHT / 2 - texRect.h / 2;
// 		printf("%d, %d", texRect.w, texRect.h);

		// Create a window size render target(texture) and canvas
		gRenderTarget = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
		Canvas* cav = new Canvas(WINDOW_WIDTH, WINDOW_HEIGHT);
// 		for (int y = 0; y < cav->height; y++)
// 		{
// 			for (int x = 0; x < cav->width; x++)
// 			{
// 				Color c(256.0f / cav->width * x, 256.0f / cav->height * y, 0);
// 				cav->DrawPixel(c, x, y);
// 			}
// 		}

		// Rendering loop
		bool bQuit = false;
		while (!bQuit)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					bQuit = true;
				}
			}

			Color c(Random::GetUint32());
			cav->DrawLine(c, cav->width * Random::GetNormalizedFloat(), cav->height * Random::GetNormalizedFloat(), cav->width * Random::GetNormalizedFloat(), cav->height * Random::GetNormalizedFloat());


			SDL_RenderClear(gRenderer);
			void* mPixels;
			int pitch = 0;
 			SDL_LockTexture(gRenderTarget,nullptr, &mPixels, &pitch);
			memcpy(mPixels, cav->PixelData, cav->width * 4 * cav->height);
			SDL_UnlockTexture(gRenderTarget);

			SDL_RenderCopy(gRenderer, gRenderTarget, nullptr, &cav->rect);

			SDL_RenderPresent(gRenderer);
		}
	}

	close();

	return 0;
}

bool init()
{
	// Initialization flag
	bool bSuccess = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		bSuccess = false;
	}

	else
	{
		// Create window
		gWindow = SDL_CreateWindow("Bulbasaur Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			bSuccess = false;
		}

		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				bSuccess = false;
			}

			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x29, 0x6A, 0x54, 0xFF);
			
				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					bSuccess = false;
				}
			}
		}
	}

	return bSuccess;
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}


void close()
{
	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	// Quit SDL subsystems
	SDL_Quit();
}