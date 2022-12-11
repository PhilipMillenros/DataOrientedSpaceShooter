#pragma once
#include <iostream>
#include <bitset>

using Entity = std::uint32_t;

const Entity MAX_ENTITIES = 4096;

using ComponentType = std::uint32_t;
const ComponentType MAX_COMPONENTS = 64;

using Signature = std::bitset<MAX_COMPONENTS>;