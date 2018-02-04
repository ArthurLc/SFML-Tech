// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
//

#pragma once

#include "targetver.h"

// C++
#include <stdio.h>
#include <tchar.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

// SFML
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

#include "system.h"
#include "sprite.h"
#include "text.h"
#include "audio.h"
#include "math.h"

enum GAME_STATE
{
	E_Menu,
	E_Game
};

// Engine
#include "sfCursor.h"
#include "sfTransform.h"
#include "sfButton.h"

using namespace std;

// TODO: faites référence ici aux en-têtes supplémentaires nécessaires au programme
