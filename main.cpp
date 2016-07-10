#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int X_SCALE = 1;
const int Y_SCALE = 1;
const int start_x = SCREEN_WIDTH / 2;
const int start_y = SCREEN_HEIGHT - (SCREEN_HEIGHT / 2);
const int x_inc = round(SCREEN_WIDTH / 10);
const int y_inc = round(SCREEN_HEIGHT / 10);


//SDL2 junk
SDL_Texture* loadTexture(string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event e;
bool quit = false;
bool first_flag = false;

//Function declarations
void system_halt();
bool init();
void close();
void setup_graphics();
void draw_loop();
void key_states();
void graph_code();
void draw_axis();
void draw_grid();
void draw_graph();
void draw_verticle();
void draw_horizontal();
void draw_sin(float x_scale, float y_scale);
void draw_cos(float x_scale, float y_scale);
void draw_tan(float x_scale, float y_scale);
void draw_x(float x_coefficient, float c);
void draw_x2(float x2_coefficient, float x_coefficient, float c);
//void draw_x3(float x3_coefficient, float x2_coefficient, float x_coefficient, float c);
void system_pause();
void graph_switch();

int main(int argc, char* args[])
{
    //Initialize
    setup_graphics();
    
    //Play game
    draw_loop();
    
    
    //Free resources
    close();
    
	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL2 Graphing Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			}
		}
	}

	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL2 subsystems
	SDL_Quit();
}

void setup_graphics()
{
	//Start up SDL2 and create a window
	if(init())
		cout << "SDL2 Successfully Initialized!" << endl;
}

void draw_loop()
{
    
	while(!quit)
	{   
        while(SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            
            //Check keys or mouse
            //key_states();
            
        }
        
        //Clear last frame
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);
        
        //MAIN LOOP CODE GOES HERE
        graph_code();
        
        //Show updated image
        SDL_RenderPresent(gRenderer);
	}
}

void key_states()
{
    //User presses a key
    if(e.type == SDL_KEYDOWN)
    {   
        switch(e.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            cout << "Key 'Escape' is pressed." << endl;
            break;
            
        case SDLK_F1:
            cout << "Key 'F1' is pressed." << endl;
            break;
            
        case SDLK_F2:
            cout << "Key 'F2' is pressed." << endl;
            break;
            
        case SDLK_F3:
            cout << "Key 'F3' is pressed." << endl;
            break;
            
        case SDLK_F4:
            cout << "Key 'F4' is pressed." << endl;
            break;
            
        case SDLK_F5:
            cout << "Key 'F5' is pressed." << endl;
            break;
            
        case SDLK_F6:
            cout << "Key 'F6' is pressed." << endl;
            break;
            
        case SDLK_F7:
            cout << "Key 'F7' is pressed." << endl;
            break;
            
        case SDLK_F8:
            cout << "Key 'F8' is pressed." << endl;
            break;
            
        case SDLK_F9:
            cout << "Key 'F9' is pressed." << endl;
            break;
            
        case SDLK_F10:
            cout << "Key 'F10' is pressed." << endl;
            break;
            
        case SDLK_F11:
            cout << "Key 'F11' is pressed." << endl;
            break;
            
        case SDLK_F12:
            cout << "Key 'F12' is pressed." << endl;
            break;
            
        case SDLK_INSERT:
            cout << "Key 'Insert' is pressed." << endl;
            break;
            
        case SDLK_DELETE:
            cout << "Key 'Delete' is pressed." << endl;
            break;
            
        case SDLK_1:
            cout << "Key '1' is pressed." << endl;
            break;
            
        case SDLK_2:
            cout << "Key '2' is pressed." << endl;
            break;
            
        case SDLK_3:
            cout << "Key '3' is pressed." << endl;
            break;
            
        case SDLK_4:
            cout << "Key '4' is pressed." << endl;
            break;
            
        case SDLK_5:
            cout << "Key '5' is pressed." << endl;
            break;
            
        case SDLK_6:
            cout << "Key '6' is pressed." << endl;
            break;
            
        case SDLK_7:
            cout << "Key '7' is pressed." << endl;
            break;
            
        case SDLK_8:
            cout << "Key '8' is pressed." << endl;
            break;
            
        case SDLK_9:
            cout << "Key '9' is pressed." << endl;
            break;
            
        case SDLK_0:
            cout << "Key '0' is pressed." << endl;
            break;
            
        case SDLK_MINUS:
            cout << "Key '-' is pressed." << endl;
            break;
            
        case SDLK_EQUALS:
            cout << "Key '=' is pressed." << endl;
            break;
            
        case SDLK_BACKSPACE:
            cout << "Key 'Backspace' is pressed." << endl;
            break;
            
        case SDLK_TAB:
            cout << "Key 'Tab' is pressed." << endl;
            break;
            
        case SDLK_q:
            cout << "Key 'q' is pressed." << endl;
            break;
            
        case SDLK_w:
            cout << "Key 'w' is pressed." << endl;
            break;
            
        case SDLK_e:
            cout << "Key 'e' is pressed." << endl;
            break;
            
        case SDLK_r:
            cout << "Key 'r' is pressed." << endl;
            break;
            
        case SDLK_t:
            cout << "Key 't' is pressed." << endl;
            break;
            
        case SDLK_y:
            cout << "Key 'y' is pressed." << endl;
            break;
            
        case SDLK_u:
            cout << "Key 'u' is pressed." << endl;
            break;
            
        case SDLK_i:
            cout << "Key 'i' is pressed." << endl;
            break;
            
        case SDLK_o:
            cout << "Key 'o' is pressed." << endl;
            break;
            
        case SDLK_p:
            cout << "Key 'p' is pressed." << endl;
            break;
            
        case SDLK_LEFTBRACKET:
            cout << "Key '[' is pressed." << endl;
            break;
            
        case SDLK_RIGHTBRACKET:
            cout << "Key ']' is pressed." << endl;
            break;
            
        case SDLK_BACKSLASH:
            cout << "Key '\\' is pressed." << endl;
            break;
            
        case SDLK_a:
            cout << "Key 'a' is pressed." << endl;
            break;
            
        case SDLK_s:
            cout << "Key 's' is pressed." << endl;
            break;
            
        case SDLK_d:
            cout << "Key 'd' is pressed." << endl;
            break;
            
        case SDLK_f:
            cout << "Key 'f' is pressed." << endl;
            break;
            
        case SDLK_g:
            cout << "Key 'g' is pressed." << endl;
            break;
            
        case SDLK_h:
            cout << "Key 'h' is pressed." << endl;
            break;
            
        case SDLK_j:
            cout << "Key 'j' is pressed." << endl;
            break;
            
        case SDLK_k:
            cout << "Key 'k' is pressed." << endl;
            break;
            
        case SDLK_l:
            cout << "Key 'l' is pressed." << endl;
            break;
            
        case SDLK_SEMICOLON:
            cout << "Key ';' is pressed." << endl;
            break;
            
        case SDLK_QUOTE:
            cout << "Key ''' is pressed." << endl;
            break;
            
        case SDLK_RETURN:
            cout << "Key 'Enter' is pressed." << endl;
            break;
            
        case SDLK_LSHIFT:
            cout << "Key 'Left Shift' is pressed." << endl;
            break;
            
        case SDLK_z:
            cout << "Key 'z' is pressed." << endl;
            break;
            
        case SDLK_x:
            cout << "Key 'x' is pressed." << endl;
            break;
            
        case SDLK_c:
            cout << "Key 'c' is pressed." << endl;
            break;
            
        case SDLK_v:
            cout << "Key 'v' is pressed." << endl;
            break;
            
        case SDLK_b:
            cout << "Key 'b' is pressed." << endl;
            break;
            
        case SDLK_n:
            cout << "Key 'n' is pressed." << endl;
            break;
            
        case SDLK_m:
            cout << "Key 'm' is pressed." << endl;
            break;
            
        case SDLK_COMMA:
            cout << "Key ',' is pressed." << endl;
            break;
            
        case SDLK_PERIOD:
            cout << "Key '.' is pressed." << endl;
            break;
            
        case SDLK_SLASH:
            cout << "Key '/' is pressed." << endl;
            break;
            
        case SDLK_RSHIFT:
            cout << "Key 'Right Shift' is pressed." << endl;
            break;
            
        case SDLK_LCTRL:
            cout << "Key 'Left Control' is pressed." << endl;
            break;
            
        case SDLK_LALT:
            cout << "Key 'Left Alt' is pressed." << endl;
            break;
            
        case SDLK_SPACE:
            cout << "Key 'Space' is pressed." << endl;
            break;
            
        case SDLK_RALT:
            cout << "Key 'Right Alt' is pressed." << endl;
            break;
            
        case SDLK_RCTRL:
            cout << "Key 'Right Control' is pressed." << endl;
            break;
            
        case SDLK_LEFT:
            cout << "Key 'Left' is pressed." << endl;
            break;
            
        case SDLK_UP:
            cout << "Key 'Up' is pressed." << endl;
            break;
            
        case SDLK_DOWN:
            cout << "Key 'Down' is pressed." << endl;
            break;
            
        case SDLK_RIGHT:
            cout << "Key 'Right' is pressed." << endl;
            break;
        }
    }
    
    //User releases a key
    else if(e.type == SDL_KEYUP)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            cout << "Key 'Escape' is released." << endl;
            break;
            
        case SDLK_F1:
            cout << "Key 'F1' is released." << endl;
            break;
            
        case SDLK_F2:
            cout << "Key 'F2' is released." << endl;
            break;
            
        case SDLK_F3:
            cout << "Key 'F3' is released." << endl;
            break;
            
        case SDLK_F4:
            cout << "Key 'F4' is released." << endl;
            break;
            
        case SDLK_F5:
            cout << "Key 'F5' is released." << endl;
            break;
            
        case SDLK_F6:
            cout << "Key 'F6' is released." << endl;
            break;
            
        case SDLK_F7:
            cout << "Key 'F7' is released." << endl;
            break;
            
        case SDLK_F8:
            cout << "Key 'F8' is released." << endl;
            break;
            
        case SDLK_F9:
            cout << "Key 'F9' is released." << endl;
            break;
            
        case SDLK_F10:
            cout << "Key 'F10' is released." << endl;
            break;
            
        case SDLK_F11:
            cout << "Key 'F11' is released." << endl;
            break;
            
        case SDLK_F12:
            cout << "Key 'F12' is released." << endl;
            break;
            
        case SDLK_INSERT:
            cout << "Key 'Insert' is released." << endl;
            break;
            
        case SDLK_DELETE:
            cout << "Key 'Delete' is released." << endl;
            break;
            
        case SDLK_1:
            cout << "Key '1' is released." << endl;
            break;
            
        case SDLK_2:
            cout << "Key '2' is released." << endl;
            break;
            
        case SDLK_3:
            cout << "Key '3' is released." << endl;
            break;
            
        case SDLK_4:
            cout << "Key '4' is released." << endl;
            break;
            
        case SDLK_5:
            cout << "Key '5' is released." << endl;
            break;
            
        case SDLK_6:
            cout << "Key '6' is released." << endl;
            break;
            
        case SDLK_7:
            cout << "Key '7' is released." << endl;
            break;
            
        case SDLK_8:
            cout << "Key '8' is released." << endl;
            break;
            
        case SDLK_9:
            cout << "Key '9' is released." << endl;
            break;
            
        case SDLK_0:
            cout << "Key '0' is released." << endl;
            break;
            
        case SDLK_MINUS:
            cout << "Key '-' is released." << endl;
            break;
            
        case SDLK_EQUALS:
            cout << "Key '=' is released." << endl;
            break;
            
        case SDLK_BACKSPACE:
            cout << "Key 'Backspace' is released." << endl;
            break;
            
        case SDLK_TAB:
            cout << "Key 'Tab' is released." << endl;
            break;
            
        case SDLK_q:
            cout << "Key 'q' is released." << endl;
            break;
            
        case SDLK_w:
            cout << "Key 'w' is released." << endl;
            break;
            
        case SDLK_e:
            cout << "Key 'e' is released." << endl;
            break;
            
        case SDLK_r:
            cout << "Key 'r' is released." << endl;
            break;
            
        case SDLK_t:
            cout << "Key 't' is released." << endl;
            break;
            
        case SDLK_y:
            cout << "Key 'y' is released." << endl;
            break;
            
        case SDLK_u:
            cout << "Key 'u' is released." << endl;
            break;
            
        case SDLK_i:
            cout << "Key 'i' is released." << endl;
            break;
            
        case SDLK_o:
            cout << "Key 'o' is released." << endl;
            break;
            
        case SDLK_p:
            cout << "Key 'p' is released." << endl;
            break;
            
        case SDLK_LEFTBRACKET:
            cout << "Key '[' is released." << endl;
            break;
            
        case SDLK_RIGHTBRACKET:
            cout << "Key ']' is released." << endl;
            break;
            
        case SDLK_BACKSLASH:
            cout << "Key '\\' is released." << endl;
            break;
            
        case SDLK_a:
            cout << "Key 'a' is released." << endl;
            break;
            
        case SDLK_s:
            cout << "Key 's' is released." << endl;
            break;
            
        case SDLK_d:
            cout << "Key 'd' is released." << endl;
            break;
            
        case SDLK_f:
            cout << "Key 'f' is released." << endl;
            break;
            
        case SDLK_g:
            cout << "Key 'g' is released." << endl;
            break;
            
        case SDLK_h:
            cout << "Key 'h' is released." << endl;
            break;
            
        case SDLK_j:
            cout << "Key 'j' is released." << endl;
            break;
            
        case SDLK_k:
            cout << "Key 'k' is released." << endl;
            break;
            
        case SDLK_l:
            cout << "Key 'l' is released." << endl;
            break;
            
        case SDLK_SEMICOLON:
            cout << "Key ';' is released." << endl;
            break;
            
        case SDLK_QUOTE:
            cout << "Key ''' is released." << endl;
            break;
            
        case SDLK_RETURN:
            cout << "Key 'Enter' is released." << endl;
            break;
            
        case SDLK_LSHIFT:
            cout << "Key 'Left Shift' is released." << endl;
            break;
            
        case SDLK_z:
            cout << "Key 'z' is released." << endl;
            break;
            
        case SDLK_x:
            cout << "Key 'x' is released." << endl;
            break;
            
        case SDLK_c:
            cout << "Key 'c' is released." << endl;
            break;
            
        case SDLK_v:
            cout << "Key 'v' is released." << endl;
            break;
            
        case SDLK_b:
            cout << "Key 'b' is released." << endl;
            break;
            
        case SDLK_n:
            cout << "Key 'n' is released." << endl;
            break;
            
        case SDLK_m:
            cout << "Key 'm' is released." << endl;
            break;
            
        case SDLK_COMMA:
            cout << "Key ',' is released." << endl;
            break;
            
        case SDLK_PERIOD:
            cout << "Key '.' is released." << endl;
            break;
            
        case SDLK_SLASH:
            cout << "Key '/' is released." << endl;
            break;
            
        case SDLK_RSHIFT:
            cout << "Key 'Right Shift' is released." << endl;
            break;
            
        case SDLK_LCTRL:
            cout << "Key 'Left Control' is released." << endl;
            break;
            
        case SDLK_LALT:
            cout << "Key 'Left Alt' is released." << endl;
            break;
            
        case SDLK_SPACE:
            cout << "Key 'Space' is released." << endl;
            break;
            
        case SDLK_RALT:
            cout << "Key 'Right Alt' is released." << endl;
            break;
            
        case SDLK_RCTRL:
            cout << "Key 'Right Control' is released." << endl;
            break;
            
        case SDLK_LEFT:
            cout << "Key 'Left' is released." << endl;
            break;
            
        case SDLK_UP:
            cout << "Key 'Up' is released." << endl;
            break;
            
        case SDLK_DOWN:
            cout << "Key 'Down' is released." << endl;
            break;
            
        case SDLK_RIGHT:
            cout << "Key 'Right' is released." << endl;
            break;
        }
    }
    
    //User moves the mouse
    else if(e.type == SDL_MOUSEMOTION)
    {
        cout << "Mouse X: " << e.motion.x << " Mouse Y: " << e.motion.y << endl;
    }
    
    //User presses a mouse button
    else if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        switch(e.button.button)
        {
            case SDL_BUTTON_LEFT:
            cout << "Left Mouse Button pressed." << endl;
            break;
            
            case SDL_BUTTON_RIGHT:
            cout << "Right Mouse Button pressed." << endl;
            break;
        }
    }
    
    //User releases a mouse button
    else if(e.type == SDL_MOUSEBUTTONUP)
    {
        switch(e.button.button)
        {
        case SDL_BUTTON_LEFT:
            cout << "Left Mouse Button released." << endl;
            break;
            
        case SDL_BUTTON_RIGHT:
            cout << "Right Mouse Button released." << endl;
            break;
        }
    }
}

void graph_code()
{
    //Draw verticle and horizontal axis
    draw_grid();
    draw_axis();
    draw_graph();   
}

void draw_axis()
{
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
    for(int i = 0; i <= SCREEN_HEIGHT; ++i)
    {
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
    }
    for(int i = 0; i <= SCREEN_WIDTH; ++i)
    {
        SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
    }
}

void draw_grid()
{
    //Draw grid and left and top borders
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0x00);
    for(int i = 0; i <= SCREEN_HEIGHT; i += (SCREEN_HEIGHT / 20))
    {
        for(int j = 0; j <= SCREEN_WIDTH; ++j)
        {
            SDL_RenderDrawPoint(gRenderer, j, i);
        }    
    }
    for(int i = 0; i <= SCREEN_WIDTH; i += (SCREEN_WIDTH / 20))
    {
        for(int j = 0; j <= SCREEN_HEIGHT; ++j)
        {
            SDL_RenderDrawPoint(gRenderer, i, j);
        }    
    }
    
    //Draw bottom and right borders
    for(int i = 0; i <= SCREEN_HEIGHT; ++i)
    {
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - 1, i);
    }
    for(int i = 0; i <= SCREEN_WIDTH; ++i)
    {
        SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT - 1);
    }
}

void draw_graph()
{
    //Each x line is 96 pixels, each y line is 54 pixels
    //SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
    
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    
    //Draw verticle and horizontal lines
    draw_verticle();
    draw_horizontal();
    
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xFF, 0xFF);
    
    //Trig functions
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0xFF, 0x00);
    draw_sin(1, 1);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0x00);
    draw_cos(1, 1);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0x00);
    draw_tan(1, 1);
    
    //Linear function
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    draw_x(1, 0);
    
    //Quadratic function
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    draw_x2(1, 0, 0);
    
    //Cubic function
    //draw_x3(1, 0, 0, 0);
    //if(first_flag == true)
    //{
    //    graph_switch();
    //}
    //first_flag = true;
}

void draw_verticle()
{
    //x = 2
    for(int y = SCREEN_HEIGHT; y >= 0; --y)
    {
        SDL_RenderDrawPoint(gRenderer, start_x + x_inc, y);
    }
}

void draw_horizontal()
{
        //y = 2
    for(int x = 0; x <= SCREEN_WIDTH; ++x)
    {
        SDL_RenderDrawPoint(gRenderer, x, start_y - y_inc); 
    }
}

void draw_sin(float x_scale, float y_scale)
{
    float current_point = 0;
    for(float x = 0; x <= SCREEN_WIDTH; x += 0.01)
    {
        current_point = start_y - (sin((x - start_x) / (((x_inc / 2) * (2 / 3.14159))) / x_scale) * ((y_inc / 2) * y_scale));
        SDL_RenderDrawPoint(gRenderer, round(x), round(current_point));
    }
}

void draw_cos(float x_scale, float y_scale)
{
    float current_point = 0;
    for(float x = 0; x <= SCREEN_WIDTH; x += 0.01)
    {
        current_point = start_y - (cos((x - start_x) / (((x_inc / 2) * (2 / 3.14159))) / x_scale) * ((y_inc / 2) * y_scale));
        SDL_RenderDrawPoint(gRenderer, round(x), round(current_point));
    }    
}

void draw_tan(float x_scale, float y_scale)
{
    float current_point = 0;
    for(float x = 0; x <= SCREEN_WIDTH; x += 0.01)
    {
        current_point = start_y - (tan((x - start_x) / (((x_inc / 2) * (2 / 3.14159))) / x_scale) * ((y_inc / 2) * y_scale));
        SDL_RenderDrawPoint(gRenderer, round(x), round(current_point));
    }
}

void draw_x(float x_coefficient, float c)
{
    float current_point = 0;
    for(float x = 0; x <= SCREEN_WIDTH; x += 0.01)
    {
        current_point = start_y - ((x_coefficient * (x - start_x)) / ((double) x_inc / (double) y_inc)) - ((double) (y_inc / 2) * c);
        SDL_RenderDrawPoint(gRenderer, round(x), round(current_point));
    }
}

void draw_x2(float x2_coefficient, float x_coefficient, float c)
{
    float current_point = 0;
    for(float x = 0; x <= SCREEN_WIDTH; x += 0.01)
    {
        current_point = start_y;
        current_point -= ((x2_coefficient * (((x - start_x) / 9.8) * ((x - start_x)) / 9.8) / ((double)x_inc / (double)y_inc)));
        current_point -= ((x_coefficient * (x - start_x)) / ((double)x_inc / (double)y_inc));
        current_point -= ((double)(y_inc / 2) * c);
        SDL_RenderDrawPoint(gRenderer, round(x), round(current_point));
    }
}

//void draw_x3(float x3_coefficient, float x2_coefficient, float x_coefficient, float c)
//{
//    float current_point = 0;
//    for(float x = 0; x <= SCREEN_WIDTH; x += 0.01)
//    {
//        current_point = start_y;
//        current_point -= ((x3_coefficient * (((x - start_x) / 25.0) * ((x - start_x)) / 25.0) * ((x - start_x)) / 25.0) / (192.0 / 108.0));
//        current_point -= ((x2_coefficient * (((x - start_x) / 9.8) * ((x - start_x)) / 9.8) / (192.0 / 108.0)));
//        current_point -= ((x_coefficient * (x - start_x)) / (192.0 / 108.0));
//        current_point -= (54.0 * c);
//        SDL_RenderDrawPoint(gRenderer, round(x), round(current_point));
//    }
//}

void system_pause()
{
    string temp;
    cin >> temp;
}

void graph_switch()
{
    
    char choice = 0;
    float arg1 = 0, arg2 = 0, arg3 = 0 , arg4 = 0;
    
    while(true)
    {
        cout << 
        "INPUT OPTION:\n1. Linear Function\n2. Quadratic Function\n3. Horizontal Line\n4. Verticle Line\n5. Sine Function\n6. Cosine Function\n7. Tangent Function\n"
        << endl;
        cin >> choice;
        
        switch(choice)
        {
            case '1':
            {
                cout << "Input X Coefficient: ";
                cin >> arg1;
                cout << "Input Y-Intercept: ";
                cin >> arg2;
                draw_x(arg1, arg2);
                break;
            }   
            case '2':
            {
                break;
            }
            case '3':
            {
                break;
            }
            case '4':
            {
                break;
            }
            case '5':
            {
                break;
            }
            case '6':
            {
                break;
            }
            case '7':
            {
                break;
            }
            default:
            {
                break;
            }

        }
    }
}