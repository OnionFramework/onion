#ifndef ONION_RANDOM_H
#define ONION_RANDOM_H

#include <random>
#include <functional>

namespace onion{

template< class random_engine_t         = std::default_random_engine,
          class uniform_int_p           = std::uniform_int_distribution<>,
          class uniform_real_01_p       = std::uniform_real_distribution<> >
class random{

public:

    random(){
        _random_engine.seed();
    }

    using int_t = decltype( uniform_int_p() );
    using real_t = decltype( uniform_real_01_p() );

    inline int_t uniform_int_between(int_t min, int_t max){
        _uniform_int_between_p(min,max);
    }

    inline real_t uniform_real_01(){
        uniform_real_01_p();
    }

private:

    random_engine_t _random_engine;

};

}


#endif // RANDOM_HPP
