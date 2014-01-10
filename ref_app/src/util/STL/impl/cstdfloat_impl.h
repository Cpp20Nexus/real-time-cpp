///////////////////////////////////////////////////////////////////////////////
// Copyright Christopher Kormanyos 2014.
// Copyright John Maddock 2014.
// Copyright Paul Bristow 2014.
// Distributed under the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _CSTDFLOAT_IMPL_2014_01_09_H_
  #define _CSTDFLOAT_IMPL_2014_01_09_H_

  #include <float.h>
  #include <limits>

  // <cstdfloat.hpp> implements floating-point typedefs having
  // specified widths, as described in N3626 (proposed for C++14).
  // See: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3626.pdf

  // This is the beginning of the preamble.

  // In this preamble, the preprocessor is used to query certain
  // preprocessor definitions from <float.h>. Based on the results
  // of these queries, an attempt is made to automatically detect
  // the presence of built-in floating-point types having specified
  // widths. These are *thought* to be conformant with IEEE-754,
  // whereby an unequivocal test based on numeric_limits follows below.

  #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH  0

  #define CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  0
  #define CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  0
  #define CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  0
  #define CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE 0

  #define CSTDFLOAT_FLOAT32_NATIVE_TYPE  float
  #define CSTDFLOAT_FLOAT64_NATIVE_TYPE  float
  #define CSTDFLOAT_FLOAT80_NATIVE_TYPE  float
  #define CSTDFLOAT_FLOAT128_NATIVE_TYPE float

  #define FLOAT32_C(x)  (x ## F)
  #define FLOAT64_C(x)  (x ## F)
  #define FLOAT80_C(x)  (x ## F)
  #define FLOAT128_C(x) (x ## F)

  #if (!defined(FLT_RADIX) && (FLT_RADIX != 2))
    #error The compiler does not support radix-2 floating-point types for <cstdfloat>.
  #endif

  // Check if built-in float is equivalent to float32_t, float64_t, float80_t, or float128_t.
  #if(defined(FLT_MANT_DIG) && defined(FLT_MAX_EXP))
    #if  ((FLT_MANT_DIG == 24) && (FLT_MAX_EXP == 128))
      #undef  CSTDFLOAT_FLOAT32_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT32_NATIVE_TYPE float
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 32
      #undef  CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  1
      #undef  FLOAT32_C
      #define FLOAT32_C(x)  (x ## F)
    #elif((FLT_MANT_DIG == 53) && (FLT_MAX_EXP == 1024))
      #undef  CSTDFLOAT_FLOAT64_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT64_NATIVE_TYPE float
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 64
      #undef  CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  1
      #undef  FLOAT64_C
      #define FLOAT64_C(x)  (x ## F)
    #elif((FLT_MANT_DIG == 63) && (FLT_MAX_EXP == 16384))
      #undef  CSTDFLOAT_FLOAT80_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT80_NATIVE_TYPE float
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 80
      #undef  CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  1
      #undef  FLOAT80_C
      #define FLOAT80_C(x)  (x ## F)
    #elif((FLT_MANT_DIG == 113) && (FLT_MAX_EXP == 16384))
      #undef  CSTDFLOAT_FLOAT128_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT128_NATIVE_TYPE float
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 128
      #undef  CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE  1
      #undef  FLOAT128_C
      #define FLOAT128_C(x)  (x ## F)
    #endif
  #endif

  // Check if built-in double is equivalent to float32_t, float64_t, float80_t, or float128_t.
  #if(defined(DBL_MANT_DIG) && defined(DBL_MAX_EXP))
    #if  ((DBL_MANT_DIG == 24) && (DBL_MAX_EXP == 128))
      #undef  CSTDFLOAT_FLOAT32_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT32_NATIVE_TYPE double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 32
      #undef  CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  1
      #undef  FLOAT32_C
      #define FLOAT32_C(x)  (x)
    #elif((DBL_MANT_DIG == 53) && (DBL_MAX_EXP == 1024))
      #undef  CSTDFLOAT_FLOAT64_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT64_NATIVE_TYPE double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 64
      #undef  CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  1
      #undef  FLOAT64_C
      #define FLOAT64_C(x)  (x)
    #elif((DBL_MANT_DIG == 63) && (DBL_MAX_EXP == 16384))
      #undef  CSTDFLOAT_FLOAT80_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT80_NATIVE_TYPE double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 80
      #undef  CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  1
      #undef  FLOAT80_C
      #define FLOAT80_C(x)  (x)
    #elif((DBL_MANT_DIG == 113) && (DBL_MAX_EXP == 16384))
      #undef  CSTDFLOAT_FLOAT128_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT128_NATIVE_TYPE double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 128
      #undef  CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE  1
      #undef  FLOAT128_C
      #define FLOAT128_C(x)  (x)
    #endif
  #endif

  // Check if built-in long double is equivalent to float32_t, float64_t, float80_t, or float128_t.
  #if(defined(LDBL_MANT_DIG) && defined(LDBL_MAX_EXP))
    #if  ((LDBL_MANT_DIG == 24) && (LDBL_MAX_EXP == 128))
      #undef  CSTDFLOAT_FLOAT32_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT32_NATIVE_TYPE long double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 32
      #undef  CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  1
      #undef  FLOAT32_C
      #define FLOAT32_C(x)  (x ## L)
    #elif((LDBL_MANT_DIG == 53) && (LDBL_MAX_EXP == 1024))
      #undef  CSTDFLOAT_FLOAT64_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT64_NATIVE_TYPE long double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 64
      #undef  CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  1
      #undef  FLOAT64_C
      #define FLOAT64_C(x)  (x ## L)
    #elif((LDBL_MANT_DIG == 63) && (LDBL_MAX_EXP == 16384))
      #undef  CSTDFLOAT_FLOAT80_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT80_NATIVE_TYPE long double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 80
      #undef  CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  1
      #undef  FLOAT80_C
      #define FLOAT80_C(x)  (x ## L)
    #elif((LDBL_MANT_DIG == 113) && (LDBL_MAX_EXP == 16384))
      #undef  CSTDFLOAT_FLOAT128_NATIVE_TYPE
      #define CSTDFLOAT_FLOAT128_NATIVE_TYPE long double
      #undef  CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 128
      #undef  CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE
      #define CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE  1
      #undef  FLOAT128_C
      #define FLOAT128_C(x)  (x ## L)
    #endif
  #endif

  #if (   (CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  == 0) \
       && (CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  == 0) \
       && (CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  == 0) \
       && (CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 0))
    #error The compiler does not support any of the required floating-point types for <cstdfloat>.
  #endif

  // This is the end of the preamble and the beginning of the type definitions.

  // Here, we define the floating-point typedefs having specified widths
  // based on the proeprocessor analysis from the preamble above.

  // These type definitions are defined in the global namespace,
  // and the corresponding types are prefixed with "_boost".

  // For simplicity, the least and fast types are type defined identically
  // as the corresponding fixed-width type. This behavior can, however,
  // be modified in order to be optimized for a given compiler implementation.

  // In addition, a clear assessment of IEEE-754 comformance is carried out
  // using compile-time assertion.

  #if(CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 1)
  typedef CSTDFLOAT_FLOAT32_NATIVE_TYPE  float32_t;
  typedef float32_t float_fast32_t;
  typedef float32_t float_least32_t;
  static_assert(std::numeric_limits< ::float32_t>::is_iec559    == true, "The 32-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float32_t>::radix        ==    2, "The 32-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float32_t>::digits       ==   24, "The 32-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float32_t>::max_exponent ==  128, "The 32-bit floating-point type is not IEEE-754 conformant.");
  #endif

  #if(CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 1)
  typedef CSTDFLOAT_FLOAT64_NATIVE_TYPE  float64_t;
  typedef float64_t float_fast64_t;
  typedef float64_t float_least64_t;
  static_assert(std::numeric_limits< ::float64_t>::is_iec559    == true, "The 64-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float64_t>::radix        ==    2, "The 64-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float64_t>::digits       ==   53, "The 64-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float64_t>::max_exponent == 1024, "The 64-bit floating-point type is not IEEE-754 conformant.");
  #endif

  #if(CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 1)
  typedef CSTDFLOAT_FLOAT80_NATIVE_TYPE  float80_t;
  typedef float80_t float_fast80_t;
  typedef float80_t float_least80_t;
  static_assert(std::numeric_limits< ::float80_t>::is_iec559    ==  true, "The 80-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float80_t>::radix        ==     2, "The 80-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float80_t>::digits       ==    63, "The 80-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float80_t>::max_exponent == 16384, "The 80-bit floating-point type is not IEEE-754 conformant.");
  #endif

  #if(CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 1)
  typedef CSTDFLOAT_FLOAT128_NATIVE_TYPE float128_t;
  typedef float128_t float_fast128_t;
  typedef float128_t float_least128_t;
  static_assert(std::numeric_limits< ::float128_t>::is_iec559    ==  true, "The 128-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float128_t>::radix        ==     2, "The 128-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float128_t>::digits       ==   113, "The 128-bit floating-point type is not IEEE-754 conformant.");
  static_assert(std::numeric_limits< ::float128_t>::max_exponent == 16384, "The 128-bit floating-point type is not IEEE-754 conformant.");
  #endif

  // The following section contains the first group of macros that
  // are used for initializing floating-point literal values.
  // The types of all three forms (fixed-width, least-width, and fast-width)
  // in precisions of 32, 64, 80, 128 are handled.

  #if(CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 1)
  #define FLOAT_32_MIN       FLOAT32_C(1.175494351e-38)
  #define FLOAT_FAST32_MIN   FLOAT_32_MIN
  #define FLOAT_LEAST32_MIN  FLOAT_32_MIN
  #define FLOAT_32_MAX       FLOAT32_C(3.402823466e+38)
  #define FLOAT_FAST32_MAX   FLOAT_32_MAX
  #define FLOAT_LEAST32_MAX  FLOAT_32_MAX
  #endif

  #if(CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 1)
  #define FLOAT_64_MIN       FLOAT64_C(2.2250738585072014e-308)
  #define FLOAT_FAST64_MIN   FLOAT_64_MIN
  #define FLOAT_LEAST64_MIN  FLOAT_64_MIN
  #define FLOAT_64_MAX       FLOAT64_C(1.7976931348623158e+308)
  #define FLOAT_FAST64_MAX   FLOAT_64_MAX
  #define FLOAT_LEAST64_MAX  FLOAT_64_MAX
  #endif

  #if(CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 1)
  #define FLOAT_80_MIN       FLOAT80_C(3.3621031431120935062627E-4932)
  #define FLOAT_FAST80_MIN   FLOAT_80_MIN
  #define FLOAT_LEAST80_MIN  FLOAT_80_MIN
  #define FLOAT_80_MAX       FLOAT80_C(1.1897314953572317650213E+4932)
  #define FLOAT_FAST80_MAX   FLOAT_80_MAX
  #define FLOAT_LEAST80_MAX  FLOAT_80_MAX
  #endif

  #if(CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 1)
  #define FLOAT_128_MIN       FLOAT128_C(3.362103143112093506262677817321752603E-4932)
  #define FLOAT_FAST128_MIN   FLOAT_128_MIN
  #define FLOAT_LEAST128_MIN  FLOAT_128_MIN
  #define FLOAT_128_MAX       FLOAT128_C(1.189731495357231765085759326628007016E+4932)
  #define FLOAT_FAST128_MAX   FLOAT_128_MAX
  #define FLOAT_LEAST128_MAX  FLOAT_128_MAX
  #endif

  // The following section contains the second group of macros that
  // are used for initializing floating-point literal values.
  // floating-point typedefs having specified widths.
  // The types of the max-form are handled.

  #if  (CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 32)
  typedef float32_t     floatmax_t;
  #define FLOATMAX_C(x) FLOAT32_C(x)
  #define FLOATMAX_MIN  FLOAT_32_MIN
  #define FLOATMAX_MAX  FLOAT_32_MAX
  #elif(CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 64)
  typedef float64_t     floatmax_t;
  #define FLOATMAX_C(x) FLOAT64_C(x)
  #define FLOATMAX_MIN  FLOAT_64_MIN
  #define FLOATMAX_MAX  FLOAT_64_MAX
  #elif(CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 80)
  typedef float80_t     floatmax_t;
  #define FLOATMAX_C(x) FLOAT80_C(x)
  #define FLOATMAX_MIN  FLOAT_80_MIN
  #define FLOATMAX_MAX  FLOAT_80_MAX
  #elif(CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 128)
  typedef float128_t    floatmax_t;
  #define FLOATMAX_C(x) FLOAT128_C(x)
  #define FLOATMAX_MIN  FLOAT_128_MIN
  #define FLOATMAX_MAX  FLOAT_128_MAX
  #else
  #error The maximum available floating-point width for cstdfloat is undefined.
  #endif

  // Here, we define floating-point typedefs having specified widths
  // within the namespace boost.
  namespace std
  {
    #if(CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 1)
    using ::float32_t;
    using ::float_fast32_t;
    using ::float_least32_t;
    #endif

    #if(CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 1)
    using ::float64_t;
    using ::float_fast64_t;
    using ::float_least64_t;
    #endif

    #if(CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 1)
    using ::float80_t;
    using ::float_fast80_t;
    using ::float_least80_t;
    #endif

    #if(CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 1)
    using ::float128_t;
    using ::float_fast128_t;
    using ::float_least128_t;
    #endif

    typedef ::floatmax_t floatmax_t;
  }

#endif // _CSTDFLOAT_IMPL_2014_01_09_H_
