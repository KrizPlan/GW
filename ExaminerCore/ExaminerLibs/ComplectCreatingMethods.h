#pragma once
#include "Complect.h"
#include <wx/dir.h>
#include <wx/string.h>
#include "JsonFileManipulation.h"
#include <fstream>

Complect creatingDefaultComplect();
std::vector<Complect> creatingComplectsVector();
std::vector<Complect> getComplectVectorFromFiles();