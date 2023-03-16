/** @file onion/Random.cpp
 *  @brief Implementation of the global RandomEngine object.
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#include "Random.hpp"
#include "RandomSTL.hpp"

using namespace onion;

RandomEngine* RandomEngineProxy::_engine = new RandomSTL<>();
