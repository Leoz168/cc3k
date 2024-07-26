#pragma once

#ifndef TILECHARMAPPING
#define TILECHARMAPPING

#include "../Game/tileIDs.h"
#include <iostream>
#include <map>
#include <string>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string YELLOW = "\033[33m";

std::string IDToChar(int id);

#endif
