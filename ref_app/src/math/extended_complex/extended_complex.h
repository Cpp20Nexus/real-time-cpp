///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2016 - 2018.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Implement templates for an extended complex class and
// its associated functions. These are intended to be used
// with both user-defined types as well as built-in float,
// double and long double.

#ifndef EXTENDED_COMPLEX_2016_02_22_
  #define EXTENDED_COMPLEX_2016_02_22_

  #if defined(__GNUC__)
    #pragma GCC system_header
  #endif

  #if defined(_MSC_VER) && (_MSC_VER <= 1800)
    #define EXTENDED_COMPLEX_CONSTEXPR
  #else
    #define EXTENDED_COMPLEX_CONSTEXPR constexpr
  #endif

  #include <cmath>

  #if !defined(EXTENDED_COMPLEX_DISABLE_IOSTREAM)
    #include <algorithm>
    #include <array>
    #include <iostream>
    #include <regex>
    #include <sstream>
    #include <string>
  #endif

  namespace extended_complex
  {
    // Forward declarations.

    // Class template extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.2.

    template<typename T> class complex;


    // Class template specializations of extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.3.

    template<> class complex<float>;
    template<> class complex<double>;
    template<> class complex<long double>;


    // Non-member operations for extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.6.

    // Unary +/- operators.
    template<typename T> complex<T> operator+(const complex<T>&);
    template<typename T> complex<T> operator-(const complex<T>&);

    // Global add, sub, mul, div operators.
    template<typename T> complex<T> operator+(const complex<T>&, const complex<T>&);
    template<typename T> complex<T> operator-(const complex<T>&, const complex<T>&);
    template<typename T> complex<T> operator*(const complex<T>&, const complex<T>&);
    template<typename T> complex<T> operator/(const complex<T>&, const complex<T>&);

    template<typename T> complex<T> operator+(const complex<T>&, const T&);
    template<typename T> complex<T> operator-(const complex<T>&, const T&);
    template<typename T> complex<T> operator*(const complex<T>&, const T&);
    template<typename T> complex<T> operator/(const complex<T>&, const T&);

    template<typename T> complex<T> operator+(const T&, const complex<T>&);
    template<typename T> complex<T> operator-(const T&, const complex<T>&);
    template<typename T> complex<T> operator*(const T&, const complex<T>&);
    template<typename T> complex<T> operator/(const T&, const complex<T>&);

    // Equality and inequality operators.
    template<typename T> bool operator==(const complex<T>&, const complex<T>&);
    template<typename T> bool operator==(const complex<T>&, const T&);
    template<typename T> bool operator==(const T&,          const complex<T>&);

    template<typename T> bool operator!=(const complex<T>&, const complex<T>&);
    template<typename T> bool operator!=(const complex<T>&, const T&);
    template<typename T> bool operator!=(const T&,          const complex<T>&);

    #if !defined(EXTENDED_COMPLEX_DISABLE_IOSTREAM)

      // I/O stream operators.
      template<typename T, typename char_type, typename traits_type>
      std::basic_istream<char_type, traits_type>& operator>>(std::basic_istream<char_type, traits_type>&, complex<T>&);

      template<typename T, typename char_type, typename traits_type>
      std::basic_ostream<char_type, traits_type>& operator<<(std::basic_ostream<char_type, traits_type>&, const complex<T>&);

    #endif // !EXTENDED_COMPLEX_DISABLE_IOSTREAM


    // Value operations for extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.7.

    template<typename T> T          real (const complex<T>&);
    template<typename T> T          imag (const complex<T>&);

    template<typename T> T          abs  (const complex<T>&);
    template<typename T> T          arg  (const complex<T>&);
    template<typename T> T          norm (const complex<T>&);

    template<typename T> complex<T> conj (const complex<T>&);
    template<typename T> complex<T> proj (const complex<T>&);
    template<typename T> complex<T> polar(const T&, const T& = T(0U));


    // Elementary transcendental functions for extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.8.

    template<typename T> complex<T> acos (const complex<T>&);
    template<typename T> complex<T> asin (const complex<T>&);
    template<typename T> complex<T> atan (const complex<T>&);
    template<typename T> complex<T> asinh(const complex<T>&);
    template<typename T> complex<T> acosh(const complex<T>&);
    template<typename T> complex<T> atanh(const complex<T>&);

    template<typename T> complex<T> cos  (const complex<T>&);
    template<typename T> complex<T> cosh (const complex<T>&);
    template<typename T> complex<T> exp  (const complex<T>&);
    template<typename T> complex<T> log  (const complex<T>&);
    template<typename T> complex<T> log10(const complex<T>&);

    template<typename T> complex<T> pow  (const complex<T>&, int);
    template<typename T> complex<T> pow  (const complex<T>&, const T&);
    template<typename T> complex<T> pow  (const complex<T>&, const complex<T>&);
    template<typename T> complex<T> pow  (const T&, const complex<T>&);

    template<typename T> complex<T> sin  (const complex<T>&);
    template<typename T> complex<T> sinh (const complex<T>&);
    template<typename T> complex<T> sqrt (const complex<T>&);
    template<typename T> complex<T> tan  (const complex<T>&);
    template<typename T> complex<T> tanh (const complex<T>&);

    // Class template extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.2.

    template<typename T>
    class complex
    {
    public:
      typedef T value_type;

      complex(const value_type& __my_x = value_type(),
              const value_type& __my_y = value_type()) : __my_re(__my_x),
                                                         __my_im(__my_y) { }

      complex(const complex& __my_z) : __my_re(__my_z.real()),
                                       __my_im(__my_z.imag()) { }

      template<typename X>
      complex(const complex<X>& __my_z) : __my_re(static_cast<value_type>(__my_z.real())),
                                          __my_im(static_cast<value_type>(__my_z.imag())) { }

      value_type real() const { return __my_re; }
      value_type imag() const { return __my_im; }

      void real(value_type __my_x) { __my_re = __my_x; }
      void imag(value_type __my_y) { __my_im = __my_y; }

      complex& operator=(const value_type& __my_other_x)
      {
        __my_re = __my_other_x;
        __my_im = value_type(0U);

        return *this;
      }

      complex& operator+=(const value_type& __my_x)
      {
        __my_re += __my_x;

        return *this;
      }

      complex& operator-=(const value_type& __my_x)
      {
        __my_re -= __my_x;

        return *this;
      }

      complex& operator*=(const value_type& __my_x)
      {
        __my_re *= __my_x;
        __my_im *= __my_x;

        return *this;
      }

      complex& operator/=(const value_type& __my_x)
      {
        __my_re /= __my_x;
        __my_im /= __my_x;

        return *this;
      }

      complex& operator=(const complex& __my_other_z)
      {
        if(this != &__my_other_z)
        {
          __my_re = __my_other_z.__my_re;
          __my_im = __my_other_z.__my_im;
        }

        return *this;
      }

      template<typename X>
      complex& operator=(const complex<X>& __my_other_z)
      {
        __my_re = static_cast<value_type>(__my_other_z.__my_re);
        __my_im = static_cast<value_type>(__my_other_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator+=(const complex<X>& __my_z)
      {
        __my_re += static_cast<value_type>(__my_z.__my_re);
        __my_im += static_cast<value_type>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator-=(const complex<X>& __my_z)
      {
        __my_re -= static_cast<value_type>(__my_z.__my_re);
        __my_im -= static_cast<value_type>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator*=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator*=(complex<X>(__my_z));
        }
        else
        {
          const value_type __my_tmp_re(__my_re);

          __my_re = (__my_tmp_re * __my_z.real()) - (imag() * __my_z.imag());
          __my_im = (__my_tmp_re * __my_z.imag()) + (imag() * __my_z.real());

          return *this;
        }
/*
        const value_type __my_ac(__my_re * __my_z.real());
        const value_type __my_bd(__my_im * __my_z.imag());

        // Do not change the order of the following two lines.
        __my_im = ((__my_re + __my_im) * (__my_z.real() + __my_z.imag())) - (__my_ac + __my_bd);
        __my_re =   __my_ac - __my_bd;

        return *this;
*/
      }

      template<typename X>
      complex& operator/=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator/=(complex<X>(__my_z));
        }
        else
        {
          using std::fabs;

          if(fabs(__my_z.real()) < fabs(__my_z.imag()))
          {
            const value_type __my_c_over_d = __my_z.real() / __my_z.imag();

            const value_type __my_denominator = (__my_z.real() * __my_c_over_d) + __my_z.imag();

            const value_type __my_tmp_re(__my_re);
            __my_re = ((__my_tmp_re * __my_c_over_d) + __my_im)     / __my_denominator;
            __my_im = ((__my_im     * __my_c_over_d) - __my_tmp_re) / __my_denominator;
          }
          else
          {
            const value_type __my_d_over_c = __my_z.imag() / __my_z.real();

            const value_type __my_denominator = (__my_z.imag() * __my_d_over_c) + __my_z.real();

            const value_type __my_tmp_re(__my_re);
            __my_re = (( __my_im     * __my_d_over_c) + __my_tmp_re) / __my_denominator;
            __my_im = ((-__my_tmp_re * __my_d_over_c) + __my_im)     / __my_denominator;
          }

          return *this;
        }
      }

    private:
      value_type __my_re;
      value_type __my_im;
    };


    // Specialization of class template extended_complex::complex<float>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.3.

    template<>
    class complex<float>
    {
    public:
      typedef float value_type;

      EXTENDED_COMPLEX_CONSTEXPR complex(float __my_x = 0.0F,
                                         float __my_y = 0.0F) : __my_re(__my_x),
                                                                __my_im(__my_y) { }

      explicit EXTENDED_COMPLEX_CONSTEXPR complex(const complex<double>&);
      explicit EXTENDED_COMPLEX_CONSTEXPR complex(const complex<long double>&);

      EXTENDED_COMPLEX_CONSTEXPR float real() const { return __my_re; }
      EXTENDED_COMPLEX_CONSTEXPR float imag() const { return __my_im; }

      void real(float __my_x) { __my_re = __my_x; }
      void imag(float __my_y) { __my_im = __my_y; }

      complex& operator=(float __my_other_x)
      {
        __my_re = __my_other_x;
        __my_im = 0.0F;

        return *this;
      }

      complex& operator+=(float __my_x)
      {
        __my_re += __my_x;

        return *this;
      }

      complex& operator-=(float __my_x)
      {
        __my_re -= __my_x;

        return *this;
      }

      complex& operator*=(float __my_x)
      {
        __my_re *= __my_x;
        __my_im *= __my_x;

        return *this;
      }

      complex& operator/=(float __my_x)
      {
        __my_re /= __my_x;
        __my_im /= __my_x;

        return *this;
      }

      complex& operator=(const complex& __my_other_z)
      {
        if(this != &__my_other_z)
        {
          __my_re = __my_other_z.__my_re;
          __my_im = __my_other_z.__my_im;
        }

        return *this;
      }

      template<typename X>
      complex& operator=(const complex<X>& __my_other_z)
      {
        __my_re = static_cast<float>(__my_other_z.__my_re);
        __my_im = static_cast<float>(__my_other_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator+=(const complex<X>& __my_z)
      {
        __my_re += static_cast<float>(__my_z.__my_re);
        __my_im += static_cast<float>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator-=(const complex<X>& __my_z)
      {
        __my_re -= static_cast<float>(__my_z.__my_re);
        __my_im -= static_cast<float>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator*=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator*=(complex<X>(__my_z));
        }
        else
        {
          const float __my_tmp_re(real());

          real((__my_tmp_re * __my_z.real()) - (imag() * __my_z.imag()));
          imag((__my_tmp_re * __my_z.imag()) + (imag() * __my_z.real()));

          return *this;
        }
      }

      template<typename X>
      complex& operator/=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator/=(complex<X>(__my_z));
        }
        else
        {
          using std::fabs;

          if(fabs(__my_z.real()) < fabs(__my_z.imag()))
          {
            const float __my_c_over_d = __my_z.real() / __my_z.imag();

            const float __my_denominator = (__my_z.real() * __my_c_over_d) + __my_z.imag();

            const float __my_tmp_re(__my_re);
            real(((__my_tmp_re * __my_c_over_d) + __my_im)     / __my_denominator);
            imag(((__my_im     * __my_c_over_d) - __my_tmp_re) / __my_denominator);
          }
          else
          {
            const float __my_d_over_c = __my_z.imag() / __my_z.real();

            const float __my_denominator = (__my_z.imag() * __my_d_over_c) + __my_z.real();

            const float __my_tmp_re(__my_re);
            real((( __my_im     * __my_d_over_c) + __my_tmp_re) / __my_denominator);
            imag(((-__my_tmp_re * __my_d_over_c) + __my_im)     / __my_denominator);
          }

          return *this;
        }
      }

    private:
      float __my_re;
      float __my_im;
    };


    // Specialization of class template extended_complex::complex<double>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.3.

    template<>
    class complex<double>
    {
    public:
      typedef double value_type;

      EXTENDED_COMPLEX_CONSTEXPR complex(double __my_x = 0.0,
                                         double __my_y = 0.0) : __my_re(__my_x),
                                                                __my_im(__my_y) { }

      EXTENDED_COMPLEX_CONSTEXPR complex(const complex<float>& __my_f) : __my_re(double(__my_f.real())),
                                                                         __my_im(double(__my_f.imag())) { }

      explicit EXTENDED_COMPLEX_CONSTEXPR complex(const complex<long double>&);

      EXTENDED_COMPLEX_CONSTEXPR double real() const { return __my_re; }
      EXTENDED_COMPLEX_CONSTEXPR double imag() const { return __my_im; }

      void real(double __my_x) { __my_re = __my_x; }
      void imag(double __my_y) { __my_im = __my_y; }

      complex& operator=(double __my_other_x)
      {
        __my_re = __my_other_x;
        __my_im = 0.0;

        return *this;
      }

      complex& operator+=(double __my_x)
      {
        __my_re += __my_x;

        return *this;
      }

      complex& operator-=(double __my_x)
      {
        __my_re -= __my_x;

        return *this;
      }

      complex& operator*=(double __my_x)
      {
        __my_re *= __my_x;
        __my_im *= __my_x;

        return *this;
      }

      complex& operator/=(double __my_x)
      {
        __my_re /= __my_x;
        __my_im /= __my_x;

        return *this;
      }

      complex& operator=(const complex& __my_other_z)
      {
        if(this != &__my_other_z)
        {
          __my_re = __my_other_z.__my_re;
          __my_im = __my_other_z.__my_im;
        }

        return *this;
      }

      template<typename X>
      complex& operator=(const complex<X>& __my_other_z)
      {
        __my_re = static_cast<double>(__my_other_z.__my_re);
        __my_im = static_cast<double>(__my_other_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator+=(const complex<X>& __my_z)
      {
        __my_re += static_cast<double>(__my_z.__my_re);
        __my_im += static_cast<double>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator-=(const complex<X>& __my_z)
      {
        __my_re -= static_cast<double>(__my_z.__my_re);
        __my_im -= static_cast<double>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator*=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator*=(complex<X>(__my_z));
        }
        else
        {
          const double __my_tmp_re(real());

          real((__my_tmp_re * __my_z.real()) - (imag() * __my_z.imag()));
          imag((__my_tmp_re * __my_z.imag()) + (imag() * __my_z.real()));

          return *this;
        }
      }

      template<typename X>
      complex& operator/=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator/=(complex<X>(__my_z));
        }
        else
        {
          using std::fabs;

          if(fabs(__my_z.real()) < fabs(__my_z.imag()))
          {
            const double __my_c_over_d = __my_z.real() / __my_z.imag();

            const double __my_denominator = (__my_z.real() * __my_c_over_d) + __my_z.imag();

            const double __my_tmp_re(__my_re);
            real(((__my_tmp_re * __my_c_over_d) + __my_im)     / __my_denominator);
            imag(((__my_im     * __my_c_over_d) - __my_tmp_re) / __my_denominator);
          }
          else
          {
            const double __my_d_over_c = __my_z.imag() / __my_z.real();

            const double __my_denominator = (__my_z.imag() * __my_d_over_c) + __my_z.real();

            const double __my_tmp_re(__my_re);
            real((( __my_im     * __my_d_over_c) + __my_tmp_re) / __my_denominator);
            imag(((-__my_tmp_re * __my_d_over_c) + __my_im)     / __my_denominator);
          }

          return *this;
        }
      }

    private:
      double __my_re;
      double __my_im;
    };

    // Specialization of class template extended_complex::complex<long double>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.3.

    template<>
    class complex<long double>
    {
    public:
      typedef long double value_type;

      EXTENDED_COMPLEX_CONSTEXPR complex(long double __my_x = 0.0L,
                                         long double __my_y = 0.0L) : __my_re(__my_x),
                                                                      __my_im(__my_y) { }

      EXTENDED_COMPLEX_CONSTEXPR complex(const complex<float>& __my_f) : __my_re(static_cast<long double>(__my_f.real())),
                                                                         __my_im(static_cast<long double>(__my_f.imag())) { }

      EXTENDED_COMPLEX_CONSTEXPR complex(const complex<double>& __my_d) : __my_re(static_cast<long double>(__my_d.real())),
                                                                          __my_im(static_cast<long double>(__my_d.imag())) { }

      EXTENDED_COMPLEX_CONSTEXPR long double real() const { return __my_re; }
      EXTENDED_COMPLEX_CONSTEXPR long double imag() const { return __my_im; }

      void real(long double __my_x) { __my_re = __my_x; }
      void imag(long double __my_y) { __my_im = __my_y; }

      complex& operator=(long double __my_other_x)
      {
        __my_re = __my_other_x;
        __my_im = 0.0L;

        return *this;
      }

      complex& operator+=(long double __my_x)
      {
        __my_re += __my_x;

        return *this;
      }

      complex& operator-=(long double __my_x)
      {
        __my_re -= __my_x;

        return *this;
      }

      complex& operator*=(long double __my_x)
      {
        __my_re *= __my_x;
        __my_im *= __my_x;

        return *this;
      }

      complex& operator/=(long double __my_x)
      {
        __my_re /= __my_x;
        __my_im /= __my_x;

        return *this;
      }

      complex& operator=(const complex& __my_other_z)
      {
        if(this != &__my_other_z)
        {
          __my_re = __my_other_z.__my_re;
          __my_im = __my_other_z.__my_im;
        }

        return *this;
      }

      template<typename X>
      complex& operator=(const complex<X>& __my_other_z)
      {
        __my_re = static_cast<long double>(__my_other_z.__my_re);
        __my_im = static_cast<long double>(__my_other_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator+=(const complex<X>& __my_z)
      {
        __my_re += static_cast<long double>(__my_z.__my_re);
        __my_im += static_cast<long double>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator-=(const complex<X>& __my_z)
      {
        __my_re -= static_cast<long double>(__my_z.__my_re);
        __my_im -= static_cast<long double>(__my_z.__my_im);

        return *this;
      }

      template<typename X>
      complex& operator*=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator*=(complex<X>(__my_z));
        }
        else
        {
          const long double __my_tmp_re(real());

          real((__my_tmp_re * __my_z.real()) - (imag() * __my_z.imag()));
          imag((__my_tmp_re * __my_z.imag()) + (imag() * __my_z.real()));

          return *this;
        }
      }

      template<typename X>
      complex& operator/=(const complex<X>& __my_z)
      {
        if(this == &__my_z)
        {
          return operator/=(complex<X>(__my_z));
        }
        else
        {
          using std::fabs;

          if(fabs(__my_z.real()) < fabs(__my_z.imag()))
          {
            const long double __my_c_over_d = __my_z.real() / __my_z.imag();

            const long double __my_denominator = (__my_z.real() * __my_c_over_d) + __my_z.imag();

            const long double __my_tmp_re(__my_re);
            real(((__my_tmp_re * __my_c_over_d) + __my_im)     / __my_denominator);
            imag(((__my_im     * __my_c_over_d) - __my_tmp_re) / __my_denominator);
          }
          else
          {
            const long double __my_d_over_c = __my_z.imag() / __my_z.real();

            const long double __my_denominator = (__my_z.imag() * __my_d_over_c) + __my_z.real();

            const long double __my_tmp_re(__my_re);
            real((( __my_im     * __my_d_over_c) + __my_tmp_re) / __my_denominator);
            imag(((-__my_tmp_re * __my_d_over_c) + __my_im)     / __my_denominator);
          }

          return *this;
        }
      }

    private:
      long double __my_re;
      long double __my_im;
    };

    // These constructors are located here because they need to be
    // implemented after the template specializations have been declared.

    EXTENDED_COMPLEX_CONSTEXPR complex<float >::complex(const complex<double>&      __my_d ) : __my_re(float ( __my_d.real())), __my_im(float ( __my_d.imag())) { }
    EXTENDED_COMPLEX_CONSTEXPR complex<float >::complex(const complex<long double>& __my_ld) : __my_re(float (__my_ld.real())), __my_im(float (__my_ld.imag())) { }
    EXTENDED_COMPLEX_CONSTEXPR complex<double>::complex(const complex<long double>& __my_ld) : __my_re(double(__my_ld.real())), __my_im(double(__my_ld.imag())) { }

    // Non-member operations for extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.6.

    // Unary +/- operators.
    template<typename T> complex<T> operator+(const complex<T>& __my_u) { return __my_u; }
    template<typename T> complex<T> operator-(const complex<T>& __my_u) { return complex<T>(-__my_u.real(), -__my_u.imag()); }

    // Global add, sub, mul, div operators.
    template<typename T> complex<T> operator+(const complex<T>& __my_u, const complex<T>& __my_v) { return complex<T>(__my_u.real() + __my_v.real(), __my_u.imag() + __my_v.imag()); }
    template<typename T> complex<T> operator-(const complex<T>& __my_u, const complex<T>& __my_v) { return complex<T>(__my_u.real() - __my_v.real(), __my_u.imag() - __my_v.imag()); }

    template<typename T> complex<T> operator*(const complex<T>& __my_u, const complex<T>& __my_v)
    {
      return complex<T>((__my_u.real() * __my_v.real()) - (__my_u.imag() * __my_v.imag()),
                        (__my_u.real() * __my_v.imag()) + (__my_u.imag() * __my_v.real()));
    }

    template<typename T> complex<T> operator/(const complex<T>& __my_u, const complex<T>& __my_v)
    {
      using std::fabs;

      complex<T> __my_result;

      if(fabs(__my_v.real()) < fabs(__my_v.imag()))
      {
        const T __my_c_over_d = __my_v.real() / __my_v.imag();

        const T __my_denominator = (__my_v.real() * __my_c_over_d) + __my_v.imag();

        __my_result = complex<T>(((__my_u.real() * __my_c_over_d) + __my_u.imag()) / __my_denominator,
                                 ((__my_u.imag() * __my_c_over_d) - __my_u.real()) / __my_denominator);
      }
      else
      {
        const T __my_d_over_c = __my_v.imag() / __my_v.real();

        const T __my_denominator = (__my_v.imag() * __my_d_over_c) + __my_v.real();

        __my_result = complex<T>((( __my_u.imag() * __my_d_over_c) + __my_u.real()) / __my_denominator,
                                 ((-__my_u.real() * __my_d_over_c) + __my_u.imag()) / __my_denominator);
      }

      return __my_result;
    }

    template<typename T> complex<T> operator+(const complex<T>& __my_u, const T& __my_v)  { return complex<T>(__my_u.real() + __my_v, __my_u.imag()); }
    template<typename T> complex<T> operator-(const complex<T>& __my_u, const T& __my_v)  { return complex<T>(__my_u.real() - __my_v, __my_u.imag()); }
    template<typename T> complex<T> operator*(const complex<T>& __my_u, const T& __my_v)  { return complex<T>(__my_u.real() * __my_v, __my_u.imag() * __my_v); }
    template<typename T> complex<T> operator/(const complex<T>& __my_u, const T& __my_v)  { return complex<T>(__my_u.real() / __my_v, __my_u.imag() / __my_v); }

    template<typename T> complex<T> operator+(const T& __my_u, const complex<T>& __my_v) { return complex<T>(__my_u + __my_v.real(),  __my_v.imag()); }
    template<typename T> complex<T> operator-(const T& __my_u, const complex<T>& __my_v) { return complex<T>(__my_u - __my_v.real(), -__my_v.imag()); }
    template<typename T> complex<T> operator*(const T& __my_u, const complex<T>& __my_v) { return complex<T>(__my_u * __my_v.real(),  __my_v.imag() * __my_u); }

    template<typename T> complex<T> operator/(const T& __my_u, const complex<T>& __my_v)
    {
      using std::fabs;

      complex<T> __my_result;

      if(fabs(__my_v.real()) < fabs(__my_v.imag()))
      {
        const T __my_c_over_d = __my_v.real() / __my_v.imag();

        const T __my_denominator = (__my_v.real() * __my_c_over_d) + __my_v.imag();

        __my_result = complex<T>(( __my_u * __my_c_over_d) / __my_denominator,
                                  -__my_u                  / __my_denominator);
      }
      else
      {
        const T __my_d_over_c = __my_v.imag() / __my_v.real();

        const T __my_denominator = (__my_v.imag() * __my_d_over_c) + __my_v.real();

        __my_result = complex<T>(  __my_u                  / __my_denominator,
                                 (-__my_u * __my_d_over_c) / __my_denominator);
      }

      return __my_result;
    }

    // Equality and inequality operators.
    template<typename T> bool operator==(const complex<T>& __my_u, const complex<T>& __my_v) { return ((__my_u.real() == __my_v.real()) && (__my_u.imag() == __my_v.imag())); }
    template<typename T> bool operator==(const complex<T>& __my_u, const T&          __my_v) { return ((__my_u.real() == __my_v)        && (__my_u.imag() == T(0))); }
    template<typename T> bool operator==(const T&          __my_u, const complex<T>& __my_v) { return ((__my_u == __my_v.real())        && (__my_v.imag() == T(0))); }

    template<typename T> bool operator!=(const complex<T>& __my_u, const complex<T>& __my_v) { return ((__my_u.real() != __my_v.real()) || (__my_u.imag() != __my_v.imag())); }
    template<typename T> bool operator!=(const complex<T>& __my_u, const T&          __my_v) { return ((__my_u.real() != __my_v)        || (__my_u.imag() != T(0))); }
    template<typename T> bool operator!=(const T&          __my_u, const complex<T>& __my_v) { return ((__my_u != __my_v.real())        || (__my_v.imag() != T(0))); }

    #if !defined(EXTENDED_COMPLEX_DISABLE_IOSTREAM)

      // I/O stream operators.
      template<typename T, typename char_type, typename traits_type>
      std::basic_istream<char_type, traits_type>& operator>>(std::basic_istream<char_type, traits_type>& __my_istream, complex<T>& __my_z)
      {
        // Parse an (extended) complex number of any of the forms u, (u) or (u,v).

        const std::array<std::regex, 3U> __my_regexes =
        {{
          // A regular expression for an (extended) complex number of the form (u,v).
          std::regex(  std::string("\\({1}")                             // One open parentheses.
                     + std::string("([\\+\\-]{0,1}[0-9]*\\.*[0-9]*)")    // Possible +-, decimal point and digits 0-9.
                     + std::string("([eE]{0,1}[\\+\\-]{0,1}[0-9]*)")     // Possible exponent field.
                     + std::string("\\,{1}")                             // One comma character.
                     + std::string("([\\+\\-]{0,1}[0-9]*\\.*[0-9]*)")    // Possible +-, decimal point and digits 0-9.
                     + std::string("([eE]{0,1}[\\+\\-]{0,1}[0-9]*)")     // Possible exponent field.
                     + std::string("\\){1}")),                           // One close parentheses.

          // A regular expression for an (extended) complex number of the form (u).
          std::regex(  std::string("\\({1}")                             // One open parentheses.
                     + std::string("([\\+\\-]{0,1}[0-9]*\\.*[0-9]*)")    // Possible +-, decimal point and digits 0-9.
                     + std::string("([eE]{0,1}[\\+\\-]{0,1}[0-9]*)")     // Possible exponent field.
                     + std::string("\\){1}")),                           // One close parentheses.

          // A regular expression for an (extended) complex number of the form u.
          std::regex(  std::string("([\\+\\-]{0,1}[0-9]*\\.*[0-9]*)")    // Possible +-, decimal point and digits 0-9.
                     + std::string("([eE]{0,1}[\\+\\-]{0,1}[0-9]*)"))    // Possible exponent field.
        }};

        T __my_real_input(0U);
        T __my_imag_input(0U);

        bool __my_input_has_error = false;

        std::string __my_input_str;

        __my_istream >> __my_input_str;

        std::match_results<std::string::const_iterator> __my_mr;

        auto __my_it_regex_match =
          std::find_if(__my_regexes.cbegin(),
                       __my_regexes.cend(),
                       [&__my_input_str, &__my_mr](const std::regex& __my_rx) -> bool
                       {
                         return std::regex_match(__my_input_str, __my_mr, __my_rx);
                       });

        if(__my_it_regex_match == __my_regexes.cend())
        {
          // The input does not match any of the regular expressions.
          // Set the error flag and take no other action.

          __my_input_has_error = true;
        }
        else if(__my_it_regex_match == __my_regexes.cbegin())
        {
          // The input matches __the_regexes[0U], corresponding to the form (u,v).
          // This represents a complex number real and imaginary parts.

          // Rule out erroneous match of invalid mantissa or exponent parts.
          const std::string __my_str1(__my_mr[1U]);
          const std::string __my_str2(__my_mr[2U]);
          const std::string __my_str3(__my_mr[3U]);
          const std::string __my_str4(__my_mr[4U]);

          const std::string __my_decimal_digits("0123456789");

          const bool __my_str1_has_error = ((__my_str1.length() != std::size_t(0U)) && (__my_str1.find_first_of(__my_decimal_digits) == std::string::npos));
          const bool __my_str2_has_error = ((__my_str2.length() != std::size_t(0U)) && (__my_str2.find_first_of(__my_decimal_digits) == std::string::npos));
          const bool __my_str3_has_error = ((__my_str3.length() != std::size_t(0U)) && (__my_str3.find_first_of(__my_decimal_digits) == std::string::npos));
          const bool __my_str4_has_error = ((__my_str4.length() != std::size_t(0U)) && (__my_str4.find_first_of(__my_decimal_digits) == std::string::npos));

          if(__my_str1_has_error || __my_str2_has_error || __my_str3_has_error || __my_str4_has_error)
          {
            __my_input_has_error = true;
          }
          else
          {
            // Extract the real part of the complex number.
            {
              std::stringstream __my_stringstream;

              __my_stringstream << __my_mr[1U] << __my_mr[2U];
              __my_stringstream >> __my_real_input;
            }

            // Extract the imaginary part of the complex number.
            {
              std::stringstream __my_stringstream;

              __my_stringstream << __my_mr[3U] << __my_mr[4U];
              __my_stringstream >> __my_imag_input;
            }
          }
        }
        else if(   (__my_it_regex_match == (__my_regexes.cbegin() + 1U))
                || (__my_it_regex_match == (__my_regexes.cbegin() + 2U)))
        {
          // The input matches the_regexes[1U] or the_regexes[2U],
          // corresponding to either of the forms (u) or u.
          // This represents a complex number having only
          // a pure real part.

          // Rule out erroneous match of invalid mantissa or exponent parts.
          const std::string __my_str1(__my_mr[1U]);
          const std::string __my_str2(__my_mr[2U]);

          const std::string __my_decimal_digits("0123456789");

          if(   ((__my_str1.length() != std::size_t(0U)) && (__my_str1.find_first_of(__my_decimal_digits) == std::string::npos))
             || ((__my_str2.length() != std::size_t(0U)) && (__my_str2.find_first_of(__my_decimal_digits) == std::string::npos)))
          {
            __my_input_has_error = true;
          }
          else
          {
            // Extract the real part of the complex number.
            std::stringstream __my_stringstream;

            __my_stringstream << __my_mr[1U] << __my_mr[2U];
            __my_stringstream >> __my_real_input;

            __my_imag_input = T(0U);
          }
        }

        if(__my_input_has_error)
        {
          // Error case: Restore the characters in the input stream
          // and set the fail bit in the input stream.
          std::for_each(__my_input_str.cbegin(),
                        __my_input_str.cend(),
                        [&__my_istream](const char& __my_c)
                        {
                          __my_istream.putback(__my_c);
                        });

          __my_istream.setstate(std::ios_base::failbit);
        }
        else
        {
          __my_z = complex<T>(__my_real_input, __my_imag_input);
        }

        return __my_istream;
      }

      template<class T, class char_type, class traits_type>
      std::basic_ostream<char_type, traits_type>& operator<<(std::basic_ostream<char_type, traits_type>& __my_ostream, const complex<T>& __my_z)
      {
        std::basic_ostringstream<char_type, traits_type> __my_tmp_ostream;

        __my_tmp_ostream.flags    (__my_ostream.flags());
        __my_tmp_ostream.imbue    (__my_ostream.getloc());
        __my_tmp_ostream.precision(__my_ostream.precision());

        __my_tmp_ostream << '('
                         << __my_z.real()
                         << ','
                         << __my_z.imag()
                         << ')';

        return (__my_ostream << __my_tmp_ostream.str());
      }

    #endif // !EXTENDED_COMPLEX_DISABLE_IOSTREAM


    // Value operations for extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.7.

    template<typename T> T real(const complex<T>& __my_z) { return __my_z.real(); }
    template<typename T> T imag(const complex<T>& __my_z) { return __my_z.imag(); }

    template<typename T> T abs (const complex<T>& __my_z) { using std::sqrt;  return sqrt(norm(__my_z)); }
    template<typename T> T arg (const complex<T>& __my_z) { using std::atan2; return atan2(__my_z.imag(), __my_z.real()); }

    template<typename T> T norm(const complex<T>& __my_z)
    {
      using std::fabs;

      T __my_result;

      if(fabs(__my_z.real()) < fabs(__my_z.imag()))
      {
        const T __my_a_over_b = __my_z.real() / __my_z.imag();

        __my_result = (__my_z.imag() * __my_z.imag()) * (1 + (__my_a_over_b * __my_a_over_b));
      }
      else
      {
        const T __my_b_over_a = __my_z.imag() / __my_z.real();

        __my_result = (__my_z.real() * __my_z.real()) * (1 + (__my_b_over_a * __my_b_over_a));
      }

      return __my_result;
    }

    template<typename T> complex<T> conj(const complex<T>& __my_z)
    {
      return complex<T>(__my_z.real(), -__my_z.imag());
    }

    template<typename T> complex<T> proj(const complex<T>& __my_z)
    {
      const T __my_denominator(norm(__my_z) + 1U);

      const T __my_real_part((__my_z.real() * 2U) / __my_denominator);
      const T __my_imag_part((__my_z.imag() * 2U) / __my_denominator);

      return complex<T>(__my_real_part, __my_imag_part);
    }

    template<typename T> complex<T> polar(const T& __my_rho, const T& __my_theta)
    {
      using std::cos;
      using std::sin;

      return complex<T>(__my_rho * cos(__my_theta), __my_rho * sin(__my_theta));
    }


    // Elementary transcendental functions for extended_complex::complex<T>.
    // See also ISO/IEC 14882:2011 Sect. 26.4.8.

    template<typename T> complex<T> acos(const complex<T>& __my_z)
    {
      using std::asin;

      const T half_pi = asin(T(1U));

      return half_pi - asin(__my_z);
    }

    template<typename T> complex<T> asin(const complex<T>& __my_z)
    {
      const complex<T> __my_z_times_i(-__my_z.imag(), __my_z.real());

      const complex<T> __my_pre_result(log(__my_z_times_i + sqrt(T(1U) - (__my_z * __my_z))));

      return complex<T>(__my_pre_result.imag(), -__my_pre_result.real());
    }

    template<typename T> complex<T> atan(const complex<T>& __my_z)
    {
      const complex<T> __my_z_times_i(-__my_z.imag(), __my_z.real());

      const complex<T> __my_pre_result(log(T(1U) - __my_z_times_i) - log(T(1U) + __my_z_times_i));

      return complex<T>(-__my_pre_result.imag() / 2U, __my_pre_result.real() / 2U);
    }

    template<typename T> complex<T> acosh(const complex<T>& __my_z)
    {
      const complex<T> __my_zp(__my_z.real() + 1U, __my_z.imag());
      const complex<T> __my_zm(__my_z.real() - 1U, __my_z.imag());

      return log(__my_z + (__my_zp * sqrt(__my_zm / __my_zp)));
    }

    template<typename T> complex<T> asinh(const complex<T>& __my_z)
    {
      return log(__my_z + sqrt((__my_z * __my_z) + T(1U)));
    }

    template<typename T> complex<T> atanh(const complex<T>& __my_z)
    {
      const complex<T> __my_result = (log(T(1U) + __my_z) - log(T(1U) - __my_z));

      return complex<T>(__my_result.real() / 2U,
                        __my_result.imag() / 2U);
    }

    template<typename T> complex<T> cos(const complex<T>& __my_z)
    {
      using std::cos;
      using std::cosh;
      using std::sin;
      using std::sinh;

      return complex<T>(  cos(__my_z.real()) * cosh(__my_z.imag()),
                        -(sin(__my_z.real()) * sinh(__my_z.imag())));
    }

    template<typename T> complex<T> cosh(const complex<T>& __my_z)
    {
      using std::cos;
      using std::cosh;
      using std::sin;
      using std::sinh;

      return complex<T>(cos(__my_z.imag()) * cosh(__my_z.real()),
                        sin(__my_z.imag()) * sinh(__my_z.real()));
    }

    template<typename T> complex<T> exp(const complex<T>& __my_z)
    {
      using std::cos;
      using std::exp;
      using std::sin;

      return complex<T>(cos(__my_z.imag()), sin(__my_z.imag())) * T(exp(__my_z.real()));
    }

    template<typename T> complex<T> log(const complex<T>& __my_z)
    {
      using std::atan2;
      using std::log;

      const T __my_real_part(log(norm(__my_z)) / 2U);
      const T __my_imag_part(atan2(__my_z.imag(), __my_z.real()));

      return complex<T>(__my_real_part, __my_imag_part);
    }

    template<typename T> complex<T> log10(const complex<T>& __my_z)
    {
      using std::log;

      return log(__my_z) / log(T(10));
    }

    template<typename T> complex<T> pow(const complex<T>& __my_z, int __my_pn)
    {
      if     (__my_pn <  0) { return  T(1U) / pow(__my_z, -__my_pn); }
      else if(__my_pn == 0) { return  complex<T>(T(1U)); }
      else if(__my_pn == 1) { return  __my_z; }
      else if(__my_pn == 2) { return  __my_z * __my_z; }
      else if(__my_pn == 3) { return (__my_z * __my_z) * __my_z; }
      else if(__my_pn == 4) { const complex<T> __my_z2(__my_z * __my_z); return (__my_z2 * __my_z2); }
      else
      {
        // The variable xn stores the binary powers of __my_z.
        complex<T> __my_result(((__my_pn % 2U) != 0U) ? __my_z : complex<T>(T(1U)));
        complex<T> __my_xn      (__my_z);

        unsigned int __my_p2 = static_cast<unsigned int>(__my_pn);

        while((__my_p2 /= 2U) != 0U)
        {
          // Square xn for each binary power.
          __my_xn *= __my_xn;

          const bool __my_p2_has_binary_power = ((__my_p2 % 2U) != 0U);

          if(__my_p2_has_binary_power)
          {
            // Multiply the result with each binary power contained in the exponent.
            __my_result *= __my_xn;
          }
        }

        return __my_result;
      }
    }

    template<typename T> complex<T> pow(const complex<T>& __my_z, const T& __my_a)
    {
      return exp(__my_a * log(__my_z));
    }

    template<typename T> complex<T> pow(const complex<T>& __my_z, const complex<T>& __my_a)
    {
      return exp(__my_a * log(__my_z));
    }

    template<typename T> complex<T> pow(const T& __my_z, const complex<T>& __my_a)
    {
      using std::log;

      return exp(__my_a * T(log(__my_z)));
    }

    template<typename T> complex<T> sin(const complex<T>& __my_z)
    {
      using std::cos;
      using std::cosh;
      using std::sin;
      using std::sinh;

      return complex<T>(sin(__my_z.real()) * cosh(__my_z.imag()),
                        cos(__my_z.real()) * sinh(__my_z.imag()));
    }

    template<typename T> complex<T> sinh(const complex<T>& __my_z)
    {
      using std::cos;
      using std::cosh;
      using std::sin;
      using std::sinh;

      return complex<T>(cos (__my_z.imag()) * sinh(__my_z.real()),
                        cosh(__my_z.real()) * sin (__my_z.imag()));
    }

    template<typename T> complex<T> sqrt(const complex<T>& __my_z)
    {
      using std::sqrt;

      // Use the following:
      // sqrt(z) = (s, zi / 2s)       for zr >= 0
      //           (|zi| / 2s, +-s)   for zr <  0
      // where s = sqrt{ [ |zr| + sqrt(zr^2 + zi^2) ] / 2 },
      // and the +- sign is the same as the sign of zi.

      const bool __my_real_part_is_neg(__my_z.real() < 0U);

      const T __my_real_part_fabs((__my_real_part_is_neg == false) ? __my_z.real() : -__my_z.real());
      const T __my_sqrt_part     (sqrt((__my_real_part_fabs + abs(__my_z)) / 2U));

      if(__my_real_part_is_neg == false)
      {
        return complex<T>(__my_sqrt_part,
                          __my_z.imag() / (__my_sqrt_part * 2U));
      }
      else
      {
        const bool __my_imag_part_is_neg(__my_z.imag() < 0U);

        const T __my_imag_part_fabs((__my_imag_part_is_neg == false) ? __my_z.imag() : -__my_z.imag());

        return complex<T>( __my_imag_part_fabs / (__my_sqrt_part * 2U),
                         ((__my_imag_part_is_neg == false) ? __my_sqrt_part : -__my_sqrt_part));
      }
    }

    template<typename T> complex<T> tan(const complex<T>& __my_z)
    {
      return sin(__my_z) / cos(__my_z);
    }

    template<typename T> complex<T> tanh(const complex<T>& __my_z)
    {
      return sinh(__my_z) / cosh(__my_z);
    }

    #if defined(__GNUC__)
    EXTENDED_COMPLEX_CONSTEXPR complex<float>       operator""if(long double imag_literal)        { return complex<float>      {0.0F, static_cast<float>      (imag_literal)}; }
    EXTENDED_COMPLEX_CONSTEXPR complex<double>      operator""i (long double imag_literal)        { return complex<double>     {0.0,  static_cast<double>     (imag_literal)}; }
    EXTENDED_COMPLEX_CONSTEXPR complex<long double> operator""il(long double imag_literal)        { return complex<long double>{0.0L, static_cast<long double>(imag_literal)}; }

    EXTENDED_COMPLEX_CONSTEXPR complex<float>       operator""if(unsigned long long imag_literal) { return complex<float>      {0.0F, static_cast<float>      (imag_literal)}; }
    EXTENDED_COMPLEX_CONSTEXPR complex<double>      operator""i (unsigned long long imag_literal) { return complex<double>     {0.0,  static_cast<double>     (imag_literal)}; }
    EXTENDED_COMPLEX_CONSTEXPR complex<long double> operator""il(unsigned long long imag_literal) { return complex<long double>{0.0L, static_cast<long double>(imag_literal)}; }
    #endif
  } // namespace extended_complex

  /*
  8-bit microcontroller @ 16MHz

  std::complex<float> x(1.23F, 3.45F);
  std::complex<float> y(0.77F, 0.22F);

  function     run time [micro-sec]    code size [byte]
   x * y               63                    880
  sqrt (x)            190                  1,600
  sin  (x)            590                  1,700
  log  (x)            400                  1,900
  exp  (x)            400                  1,600
  acosh(x)            830                  3,200
  */

#endif // EXTENDED_COMPLEX_2016_02_22_
