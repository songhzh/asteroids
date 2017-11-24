#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include <Arduino.h>
#include <Adafruit_ILI9341.h>

#include "common.h"
#include "inputs.h"
#include "bullet.h"

#define SPACESHIP_RADIUS 5
#define SPACESHIP_COLOR ILI9341_WHITE
#define SPACESHIP_VEL_MAG_MAX 1.5
#define SPACESHIP_ACC_MAG 0.1

class Spaceship {
public:
	void init(Adafruit_ILI9341* tft);
	void init(Adafruit_ILI9341* tft, float dx, float dy);
	void init(Adafruit_ILI9341* tft, float dx, float dy,
		float vx, float vy, float ax, float ay);

	void update(float &x, float &y);

private:
	float dx_, dy_; // displacement
	float vx_, vy_; // velocity
	float ax_, ay_; // acceleration
	float ux_, uy_; // unit vector of ship direction

	Adafruit_ILI9341* tft_;

	void draw(uint16_t color);
	void updateAcceleration();
	void updateVelocity();
	void updateDisplacement();
	void fire();

};

#endif
