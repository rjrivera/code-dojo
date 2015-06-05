#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT= 480;

bool init();

SDL_Window * window = NULL;

SDL_Surface * screenSurface= NULL;


bool init(){

	//Initialization flag
	bool success = true;
	//iNITIALIZE SDL - Put this in an init method RIGHT AWAY. 
        if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ){

                printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());

        }

        else {

                window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
                if( window == NULL){
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
                }
                else{
                        screenSurface = SDL_GetWindowSurface( window);

                        SDL_FillRect( screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF) );

                        SDL_UpdateWindowSurface( window );

                        SDL_Delay( 2000 );
                }
        }



	return true;

}


int main( int argc, char* args[] ){

	init();

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;



        
	//main game loop
	while( !quit){


		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0){

			//User requests quit
			if(e.type == SDL_QUIT){

				quit = true;

			}

		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if( currentKeyStates[ SDL_SCANCODE_DOWN ] ){

			quit = true;
		}

	}


	SDL_DestroyWindow( window );

	SDL_Quit();

	return 0;
}
