#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Map.h"
#include "Player.h"

int main(void)
{
	//==============================================
	//SHELL VARIABLES
	//==============================================
	bool done = false;
	bool mouseDown = false;
	int frameCount = 0;
	
	//==============================================
	//PROJECT VARIABLES
	//==============================================
	Map map1;
	Player player;

	//==============================================
	//ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	//==============================================
	//ALLEGRO INIT FUNCTIONS
	//==============================================
	if(!al_init())
		return -1;
	display = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	if(!display)
		return -1;

	//==============================================
	//ADDON INSTALL
	//==============================================
	al_init_primitives_addon();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();

	//==============================================
	//TIMER INIT AND STARTUP
	//==============================================
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	
	al_start_timer(timer);

	while(!done)
	{
		if(map1.ReturnGameMenu().startPause.GetPaused())
			al_stop_timer(timer);
		else
			al_start_timer(timer);

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//==============================================
		//INPUT
		//==============================================
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
			done = true;
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			map1.ButtonPressCheck(ev.mouse.x, ev.mouse.y, player);
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			map1.ButtonPressCheck(ev.mouse.x, ev.mouse.y, player);
		}
		
		//==============================================
		//GAME UPDATE
		//==============================================
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			map1.UpdateMapElements(frameCount, player); //HHMHMHMHMMM
			frameCount++;
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			map1.SetMousePos(ev.mouse.x, ev.mouse.y);
		}

		//==============================================
		//RENDER
		//==============================================
		if(al_is_event_queue_empty(event_queue))
		{
			map1.DrawMapElements(player);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}
	
	//==============================================
	//DESTROY PROJECT OBJECTS
	//==============================================
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	al_destroy_timer(timer);
	map1.ReturnGameMenu().displayScreen.Destroy();
	map1.ReturnGameMenu().startPause.Destroy();

	return 0;
}
