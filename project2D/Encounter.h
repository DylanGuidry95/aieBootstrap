#pragma once
#include "Entity.h"

enum Encounters
{
	item,
	enemy,
	null
};

struct Encounter
{
	Entity *encounter;
	Encounters encounterType;
};
