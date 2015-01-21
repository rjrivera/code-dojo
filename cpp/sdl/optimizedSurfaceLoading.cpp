#include<stdlib.h>
#include<SDL2/SDL.h>
#include<string>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key press surfaces constants
//
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool init();

bool loadMedia();

void close();

SDL_Surface* loadSurface(std::string path);

SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL];

SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* loadSurface(std::string path)
{
    //the final optimized image
    SDL_Surface* optimizedSurface = NULL;
    //load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO) < 0)
    {
        printf("sdl could not initialize! sdl_Error: %s\n", SDL_GetError());
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

    //Load splash image
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "Content/sprites/press.bmp" );
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf( "Unable to load default image %s! SDL Error: %s\n", "Content/sprites/press.bmp", SDL_GetError());
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Content/sprites/up.bmp");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL )
    {
        printf("Failed to load up image! \n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Content/sprites/down.bmp");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL )
    {
        printf("Failed to load down image! \n");
        success = false;
    }

    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Content/sprites/left.bmp");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL )
    {
        printf("Failed to load left image! \n");
        success = false;
    }
    
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Content/sprites/right.bmp");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        printf("Failed to load right image! \n");
        success = false;
    }


    return success;
}

void close()
{
    //Deallocate surface
    for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
    SDL_FreeSurface(gKeyPressSurfaces[i]);
    gKeyPressSurfaces[i] = NULL;
    }
    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[]){

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Start up SDL and create window
    if(!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        
        bool quit = false;

        SDL_Event e;

        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

        while(!quit)
        {
            while( SDL_PollEvent( &e ) != 0)
            {
                //User requests quit
                if( e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else if(e.type == SDL_KEYDOWN)
                {
                    switch(e.key.keysym.sym){
                    case SDLK_UP:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                        break;

                    case SDLK_DOWN:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                        break;
                    case SDLK_RIGHT:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;
                    case SDLK_LEFT:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                        break;
                    default:
                        gCurrentSurface[KEY_PRESS_SURFACE_DEFAULT];
                        break;
                    }
                }
                SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

                SDL_UpdateWindowSurface(gWindow);
            }
         }
    }
    close();
    return(0);

}
