#pragma once
#include "Projectile.h"
#include <math.h>
#include <allegro5/allegro_primitives.h>

Projectile::Projectile()
{
	live = false;
	monsterID = 0;
	damage = 10;
	speed = 4;
	slow = 0;
}
float Projectile::CollideMonster(int mx, int my)
{
	if(abs(xCenter - mx) < 3 && abs(yCenter - my) < 3)
	{
		live = false;
		return damage;
	}
	return 0;
}
void Projectile::DrawProjectile()
{
	al_draw_circle(xCenter, yCenter, 5, al_map_rgb(255, 255, 255), 1);
}
void Projectile::UpdatePosition(int mx, int my)
{
	float xinc = mx-xCenter;
	float yinc = my-yCenter;
	float hypot = sqrt(pow(xinc, 2)+pow(yinc, 2));
	xCenter = xCenter + xinc/hypot*speed;
	yCenter = yCenter + yinc/hypot*speed;
}
