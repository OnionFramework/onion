#ifndef ONION_RANDOM_H
#define ONION_RANDOM_H

#include <random>
#include <functional>
#include <ctime>

namespace onion{

class random{

public:

    using int_t = unsigned int;
    using real_t = double;

    virtual ~random() = default;
    virtual int_t uniform_int() noexcept = 0;
    virtual int_t uniform_int_between(int_t min, int_t max) noexcept = 0;
    virtual real_t uniform_real_01() noexcept = 0;
    virtual void seed() noexcept = 0;

};

class random_legacy_c : public random{

public:

    random_legacy_c() noexcept {
        seed();
    }

    virtual ~random_legacy_c() = default;

    virtual int_t uniform_int() noexcept {
        return static_cast<int_t> (std::rand());
    }

    virtual int_t uniform_int_between(int_t min, int_t max) noexcept {
        auto range = max-min+1;
        return uniform_int() % range + min;
    }

    virtual real_t uniform_real_01() noexcept {
        return static_cast<real_t>( std::rand() ) / RAND_MAX ;
    }

    virtual void seed() noexcept {
        std::srand( static_cast<unsigned int>( std::time(nullptr) ) );
    }

};

template< class random_engine_t = std::mt19937 >
class random_cpp11 : public random{

public:

    random_cpp11() noexcept {
        seed();
    }

    virtual ~random_cpp11() = default;

    virtual inline int_t uniform_int() noexcept {
        return std::uniform_int_distribution<int_t>()(random_engine);
    }

    virtual inline int_t uniform_int_between(int_t min, int_t max) noexcept {
        return std::uniform_int_distribution<int_t>(min,max)(random_engine);
    }

    virtual inline real_t uniform_real_01() noexcept {
        return std::uniform_real_distribution<real_t>(0.0,1.0)(random_engine);
    }

    virtual void seed() noexcept {
        std::random_device r;
        random_engine.seed( r() );
    }

private:

    random_engine_t random_engine;

};

}


#endif // RANDOM_HPP
