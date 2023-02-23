/** @file onion/Random.cpp
 *  @brief Implementation of the global RandomEngine object.
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#include "onion/Random.hpp"
#include "onion/RandomSTL.hpp"

using namespace onion;

RandomEngine* RandomEngineProxy::_engine = new RandomSTL<>();
