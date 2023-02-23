#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

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
