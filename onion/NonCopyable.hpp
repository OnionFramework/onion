#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H
/** @file onion/NonCopyable.hpp
 *  @brief Contains the declaration of the NonCopyable class.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
namespace onion {

/** @class NonCopyable
 *  @brief Class to make other classes non-copyable.
 *
 *  In many situations its not reasonable or logical to let applications
 *  create or set objects like copies of another objects.
 *  Structurally, this usually applies to classes whose behaviour depends on
 *  some internal state or to classes that encapsulate some kind of resource.
 *  Logically, this applies to objects that are unique in some particular context.
 *  The later is the case for many components of the Onion Framework
 *
 *  The purpose of the NonCopyable class is just to make this behaviour
 *  a little bit more simple to implement and evident to read.
 *
 */
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
