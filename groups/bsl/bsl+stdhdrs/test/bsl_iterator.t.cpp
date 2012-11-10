#undef BSL_OVERRIDES_STD
#include <bsl_iterator.h>
#include <iterator>
#ifdef std
#   error std was not expected to be a macro
#endif

// Verify that iterator adapters get included by bsl_iterator.h

template <typename T, typename ITER_IMP>
class CheckForwardIteratorAdapter
    : BloombergLP::bslstl::ForwardIterator<T, ITER_IMP>
{};

template <typename T, typename ITER_IMP>
class CheckBidirectionalIteratorAdapter
    : BloombergLP::bslstl::BidirectionalIterator<T, ITER_IMP>
{};

template <typename T, typename ITER_IMP>
class CheckRandomAccessIteratorAdapter
    : BloombergLP::bslstl::RandomAccessIterator<T, ITER_IMP>
{};

namespace std { }
int main() { return 0; }

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