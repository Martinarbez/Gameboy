#include <gb/gb.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

//generical character structure: id, position, graphics
struct GameCharacter {
	uint8_t spritids[2]; // all characters use 4 sprites
	uint8_t x;
	uint8_t y;
	uint8_t width;
	uint8_t height;
};