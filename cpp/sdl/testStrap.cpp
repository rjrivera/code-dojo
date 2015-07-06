#include<stdlib.h>
#include"Rectangle.h"
#include<iostream>
#include"Character.h"
#include<SDL2/SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

bool init();

bool loadMedia();

void close();

SDL_Surface* loadSurface(std::string path);

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* blueSurface = NULL;

SDL_Surface* redSurface = NULL;

SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* loadSurface(std::string path)
{
    //load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loadedSurface;
}


bool init(){

	//initialization flag
	bool success = true;

	//initialize SDL
	if(SDL_Init( SDL_INIT_VIDEO) < 0){

		printf("sdl could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
    	}
    	else
    	{
        //Get window surface
        	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        	if( gWindow == NULL){
            		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            		success = false;
        	}
        	else{
            		gScreenSurface = SDL_GetWindowSurface(gWindow);

	        }

     	}

    return success;
}

bool loadMedia()
{
     //Loading success flag
    bool success = true;

    //Load images
    blueSurface = loadSurface( "Content/sprites/blue.bmp" );
    redSurface = loadSurface( "Content/sprites/red.bmp");
    if(blueSurface == NULL || redSurface == NULL)
    {
        printf( "Unable to load default image from  %s! SDL Error: %s\n", "Content/sprites/*", SDL_GetError());
        success = false;
    }

    return success;

}

void close(){

	//Deallocate memory
	SDL_FreeSurface(redSurface);
	SDL_FreeSurface(blueSurface);

	//Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();

}

int main(){

	std::cout << "This is a test strap program\n";

	loadMedia();
 

	if(!init()){
		printf("Failed to initialize!\n");
	}
	else{

		bool quit = false;

		SDL_Event e;

		gCurrentSurface = redSurface;

        	Rectangle* myFirstRect = new Rectangle(5, 10, 4, 8);

		Character* blue = new CharacterBlue(blueSurface);

	        Character* red = new CharacterRed(redSurface);

		std::cout << "Incoming data on rectangle (x, y, width, height): \n " <<
		myFirstRect->x << "\n" <<
		myFirstRect->y << "\n" <<
		myFirstRect->width << "\n" <<
		myFirstRect->height << "\n";

		std::cout << "Addresses of empty blue and red characters inbound\n" <<
		blue << "\n" <<
		red << "\n" ;

		SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);
		
		while(!quit){
			if( e.type == SDL_QUIT){
				quit = true;
			}
		}

	
	}
	close();
	return(0);
}
