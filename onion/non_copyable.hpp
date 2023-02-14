#ifndef NON_COPYABLE_HPP
#define NON_COPYABLE_HPP

namespace onion {

class NonCopyable
{
public:
    NonCopyable() = default;
    virtual ~NonCopyable() = default;
    NonCopyable( const NonCopyable& ) = delete;
    NonCopyable& operator=( const NonCopyable& ) = delete;
};

}

#endif
