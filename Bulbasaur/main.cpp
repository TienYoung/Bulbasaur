#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include <GL/gl3w.h>
//#include <glfw3.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 640;

bool init();

SDL_Texture* loadTexture(std::string path);

void close();


SDL_Window* gWindow = nullptr;
SDL_GLContext gl_context;

SDL_Renderer* gRenderer = nullptr;

SDL_Texture* gTexture = nullptr;

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}

	else
	{
		gTexture = loadTexture("Resources/Bulbasaur.png");
		SDL_Rect texRect;
		SDL_QueryTexture(gTexture, nullptr, nullptr, &texRect.w, &texRect.h);		
		texRect.x = SCREEN_WIDTH / 2 - texRect.w / 2;
		texRect.y = SCREEN_HEIGHT / 2 - texRect.h / 2;	
		//printf("%d, %d", texRect.w, texRect.h);

		ImVec4 clear_color = ImVec4(0.16f, 0.42f, 0.33f, 1.00f);

		// Rendering loop
		bool bQuit = false;
		while (!bQuit)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				ImGui_ImplSDL2_ProcessEvent(&event);
				if (event.type == SDL_QUIT)
				{
					bQuit = true;
				}
				if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(gWindow))
				{
					bQuit = true;
				}
			}

			// Start the Dear ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplSDL2_NewFrame(gWindow);
			ImGui::NewFrame();

			{
				ImGui::Begin("Hello");
				ImGui::End();
			}

			// Rendering
			ImGui::Render();
			SDL_GL_MakeCurrent(gWindow, gl_context);
			ImGuiIO& io = ImGui::GetIO();
			glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
			glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
			glClear(GL_COLOR_BUFFER_BIT);
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			SDL_GL_SwapWindow(gWindow);

// 			SDL_RenderClear(gRenderer);
// 
// 			SDL_RenderCopy(gRenderer, gTexture, nullptr, &texRect);
// 
// 			// Limit refresh rate
// 			SDL_Delay(16);
// 
// 			SDL_RenderPresent(gRenderer);
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
		// GL 3.3 Core + GLSL 330
		const char* glsl_version = "#version 330";
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		// Create window with grapics context
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
		// Create window
		SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
		gWindow = SDL_CreateWindow("Bulbasaur", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
		if (gWindow == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			bSuccess = false;
		}

		else
		{
			// Create GL context
			gl_context = SDL_GL_CreateContext(gWindow);
			SDL_GL_SetSwapInterval(1);

			bool bError = gl3wInit() != 0;

			if (bError)
			{
				printf("Failed to initialize OpenGL loader!\n");
				bSuccess = false;
			}

			else
			{
				// Create renderer for window
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
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

					else
					{
						// Setup Dear ImGui context
						IMGUI_CHECKVERSION();
						ImGui::CreateContext();
						ImGuiIO& io = ImGui::GetIO(); (void)io;
						//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

						// Setup Dear ImGui Style
						ImGui::StyleColorsDark();

						// Setup Platform/Renderer bindings
						ImGui_ImplSDL2_InitForOpenGL(gWindow, gl_context);
						ImGui_ImplOpenGL3_Init(glsl_version);
					}
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
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	// Quit SDL subsystems
	SDL_Quit();
}