#pragma once
#include <nlohmann/json.hpp>
#include "Complect.h"

using json = nlohmann::json;


void to_json(json&, const Question&);
void to_json(json&, const Test&);
void to_json(json&, const Level&);
void to_json(json&, const Complect&);
void from_json(const json&, Question&);
void from_json(const json&, Test&);
void from_json(const json&, Level&);
void from_json(const json&, Complect&);