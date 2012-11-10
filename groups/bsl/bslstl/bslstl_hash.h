// bslstl_hash.h                                                      -*-C++-*-
#ifndef INCLUDED_BSLSTL_HASH
#define INCLUDED_BSLSTL_HASH

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a namespace for hash functions.
//
//@CLASSES:
//  bsl::hash: hash function for fundamental types
//
//@SEE_ALSO: bsl+stdhdrs
//
//@DESCRIPTION: This component provides a template unary functor,
//'bsl::hash', implementing the 'std::hash' functor.  'bsl::hash' applies a C++
//standard compliant, implementation defined, hash function to fundamental
//types returning the result of such application.
//
/// Standard Hash Function
// According to the C++ standard the requirements of a standard hash function
// 'h' are:
//
//: 1 Return a 'size_t' value between 0 and
//:   'numeric_limits<std::size_t>::max()'
//:
//: 2 The value returned must depend only on the argument 'k'.  For multiple
//:   evaluations with the same argument 'k', the value returned must be
//:   always the same.
//:
//: 3 The function should not modify it's argument.
//
///Usage
///-----
// This component is for use by the 'bsl+stdhdrs' package.


// Prevent 'bslstl' headers from being included directly in 'BSL_OVERRIDES_STD'
// mode.  Doing so is unsupported, and is likely to cause compilation errors.
#if defined(BSL_OVERRIDES_STD) && !defined(BSL_STDHDRS_PROLOGUE_IN_EFFECT)
#error "<bslstl_hash.h> header can't be included directly in \
BSL_OVERRIDES_STD mode"
#endif

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

#ifndef INCLUDED_BSLALG_HASHUTIL
#include <bslalg_hashutil.h>
#endif

#ifndef INCLUDED_BSLMF_ISBITWISEMOVEABLE
#include <bslmf_isbitwisemoveable.h>
#endif

#ifndef INCLUDED_BSLMF_ISTRIVIALLYCOPYABLE
#include <bslmf_istriviallycopyable.h>
#endif

#ifndef INCLUDED_BSLMF_ISTRIVIALLYDEFAULTCONSTRUCTIBLE
#include <bslmf_istriviallydefaultconstructible.h>
#endif


#ifndef INCLUDED_BSLS_COMPILERFEATURES
#include <bsls_compilerfeatures.h>
#endif

#ifndef INCLUDED_CSTDDEF
#include <cstddef>  // for 'std::size_t'
#define INCLUDED_CSTDDEF
#endif

namespace bsl {

                          // ==================
                          // class bslstl::hash
                          // ==================

template <class TYPE>
struct hash;
    // Empty base class for hashing.  No general hash struct defined, each type
    // requires a specialization.  Leaving this struct declared but undefined
    // will generate error messages that are more clear when someone tries to
    // use a key that does not have a corresponding hash function.

// ============================================================================
//                                TYPE TRAITS
// ============================================================================

// Type traits for STL *sequence* containers:
//: o A sequence container defines STL iterators.
//: o A sequence container is bitwise moveable if the allocator is bitwise
//:     moveable.
//: o A sequence container uses 'bslma' allocators if the parameterized
//:     'ALLOCATOR' is convertible from 'bslma::Allocator*'.

template <class TYPE>
struct is_trivially_default_constructible<hash<TYPE> >
: bsl::true_type
{};

template <class TYPE>
struct is_trivially_copyable<hash<TYPE> >
: bsl::true_type
{};

}  // close namespace bsl

namespace BloombergLP {
namespace bslmf {

template <class TYPE>
struct IsBitwiseMoveable<bsl::hash<TYPE> >
: bsl::true_type
{};

}
}  // namespace BloombergLP

namespace bsl {

// ============================================================================
//                  SPECIALIZATIONS FOR FUNDAMENTAL TYPES
// ============================================================================

template <class BSLSTL_KEY>
struct hash<const BSLSTL_KEY> : hash<BSLSTL_KEY> {
    // This class provides hashing functionality for constant key types, by
    // delegating to the same function for non-constant key types.
};

template <class TYPE>
struct hash<TYPE *> {
    // Specialization of 'hash' for pointers.

    // STANDARD TYPEDEFS
    typedef TYPE *argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(TYPE *x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<bool> {
    // Specialization of 'hash' for 'bool' values.

    // STANDARD TYPEDEFS
    typedef bool argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(bool x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<char> {
    // Specialization of 'hash' for 'char' values.

    // STANDARD TYPEDEFS
    typedef char argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(char x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<signed char> {
    // Specialization of 'hash' for 'signed' 'char' values.

    // STANDARD TYPEDEFS
    typedef signed char argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(signed char x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<unsigned char> {
    // Specialization of 'hash' for 'unsigned' 'char' values.

    // STANDARD TYPEDEFS
    typedef unsigned char argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(unsigned char x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<wchar_t> {
    // Specialization of 'hash' for 'wchar_t' values.

    // STANDARD TYPEDEFS
    typedef wchar_t argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(wchar_t x) const;
        // Return a hash value computed using the specified 'x'.
};

#if defined BSLS_COMPILERFEATURES_SUPPORT_UNICODE_CHAR_TYPES
template <>
struct hash<char16_t> {
    // Specialization of 'hash' for 'char16_t' values.

    // STANDARD TYPEDEFS
    typedef char16_t argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(char16_t x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<char32_t> {
    // Specialization of 'hash' for 'char32_t' values.

    // STANDARD TYPEDEFS
    typedef char32_t argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(char32_t x) const;
        // Return a hash value computed using the specified 'x'.
};
#endif

template <>
struct hash<short> {
    // Specialization of 'hash' for 'short' values.

    // STANDARD TYPEDEFS
    typedef short argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(short x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<unsigned short> {
    // Specialization of 'hash' for 'unsigned' 'short' values.

    // STANDARD TYPEDEFS
    typedef unsigned short argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(unsigned short x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<int> {
    // Specialization of 'hash' for 'int' values.

    // STANDARD TYPEDEFS
    typedef int argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(int x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<unsigned int> {
    // Specialization of 'hash' for 'unsigned' 'int' values.

    // STANDARD TYPEDEFS
    typedef unsigned int argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(unsigned int x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<long> {
    // Specialization of 'hash' for 'long' values.

    // STANDARD TYPEDEFS
    typedef long argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(long x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<unsigned long> {
    // Specialization of 'hash' for 'unsigned' 'long' values.

    // STANDARD TYPEDEFS
    typedef unsigned long argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(unsigned long x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<long long> {
    // Specialization of 'hash' for 'long long' values.

    // STANDARD TYPEDEFS
    typedef long long argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(long long x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<unsigned long long> {
    // Specialization of 'hash' for 'unsigned' 'long long' values.

    // STANDARD TYPEDEFS
    typedef unsigned long long argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(unsigned long long x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<float> {
    // Specialization of 'hash' for 'float' values.

    // STANDARD TYPEDEFS
    typedef float argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(float x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<double> {
    // Specialization of 'hash' for 'double' values.

    // STANDARD TYPEDEFS
    typedef double argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(double x) const;
        // Return a hash value computed using the specified 'x'.
};

template <>
struct hash<long double> {
    // Specialization of 'hash' for 'long double' values.

    // STANDARD TYPEDEFS
    typedef long double argument_type;
    typedef std::size_t result_type;

    //! hash() = default;
        // Create a 'hash' object.

    //! hash(const hash& original) = default;
        // Create a 'hash' object.  Note that as 'hash' is an empty (stateless)
        // type, this operation will have no observable effect.

    //! ~hash() = default;
        // Destroy this object.

    // MANIPULATORS
    //! hash& operator=(const hash& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.  Note
        // that as 'hash' is an empty (stateless) type, this operation will
        // have no observable effect.

    // ACCESSORS
    std::size_t operator()(long double x) const;
        // Return a hash value computed using the specified 'x'.
};

// ===========================================================================
//                  TEMPLATE AND INLINE FUNCTION DEFINITIONS
// ===========================================================================

template<typename TYPE>
inline
std::size_t hash<TYPE *>::operator()(TYPE *x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<bool>::operator()(bool x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<char>::operator()(char x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<signed char>::operator()(signed char x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<unsigned char>::operator()(unsigned char x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<wchar_t>::operator()(wchar_t x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

#if defined BSLS_COMPILERFEATURES_SUPPORT_UNICODE_CHAR_TYPES
inline
std::size_t hash<char>::operator()(char16_t x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<char>::operator()(char32_t x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}
#endif

inline
std::size_t hash<short>::operator()(short x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<unsigned short>::operator()(unsigned short x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<int>::operator()(int x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<unsigned int>::operator()(unsigned int x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<long>::operator()(long x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<unsigned long>::operator()(unsigned long x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<long long>::operator()(long long x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<unsigned long long>::operator()(unsigned long long x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<float>::operator()(float x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<double>::operator()(double x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash(x);
}

inline
std::size_t hash<long double>::operator()(long double x) const
{
    return ::BloombergLP::bslalg::HashUtil::computeHash((double)x);
}

}  // close namespace bsl

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2012 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------