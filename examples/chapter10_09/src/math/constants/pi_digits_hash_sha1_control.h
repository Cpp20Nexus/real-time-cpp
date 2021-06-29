///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2020.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef PI_DIGITS_HASH_SHA1_CONTROLS_2020_05_14_H_
  #define PI_DIGITS_HASH_SHA1_CONTROLS_2020_05_14_H_

  #include <array>
  #include <cstddef>

  #include <math/checksums/hash/hash_sha1.h>

  namespace math { namespace constants {

  // This is a hard-coded data file. Please do not edit this file.

  // Hash SHA1 results of the ASCII character representations
  // of the digits of pi.

  // |-------------------------------------------------------------|
  // | Digits as chars  | Hash SHA1                                |
  // |-------------------------------------------------------------|
  // |   1001           | A092471FD5FE415120E7DD185B930D053A86F17E |
  // |   5001           | 53C1936F922C570420A2356BAC348225E6D429CE |
  // |  10001           | 4BDF69A5FF25B9BED6BA9802BD2A68306FAB71EC |
  // |  50001           | 8A7595C31618ACE733589B0A15B994F7F65A7A55 |
  // | 100001           | D9D56240EB6B626A8FE179E3054D332F1767071D |
  // |-------------------------------------------------------------|

  struct pi_digits_hash_control_base
  {
    using native_hash_type = math::checksums::hash::hash_sha1<std::uintptr_t>;

    using progmem_hash_result_type =
      std::array<std::uint8_t, std::tuple_size<typename native_hash_type::result_type>::value>;
  };

  template<const std::uintptr_t pi_digits>
  struct pi_digits_hash_control : pi_digits_hash_control_base
  {
  private:
    typename progmem_hash_result_type::const_pointer hash_control() noexcept = delete;
  };

  template<>
  struct pi_digits_hash_control<std::uintptr_t(1001UL)> : pi_digits_hash_control_base
  {
    static typename progmem_hash_result_type::const_pointer hash_control() noexcept
    {
      static const progmem_hash_result_type value =
      {{
        // A092471FD5FE415120E7DD185B930D053A86F17E
        0xA0U, 0x92U, 0x47U, 0x1FU, 0xD5U, 0xFEU, 0x41U, 0x51U,
        0x20U, 0xE7U, 0xDDU, 0x18U, 0x5BU, 0x93U, 0x0DU, 0x05U,
        0x3AU, 0x86U, 0xF1U, 0x7EU
      }};

      return value.data();
    }
  };

  template<>
  struct pi_digits_hash_control<std::uintptr_t(5001UL)> : pi_digits_hash_control_base
  {
    static typename progmem_hash_result_type::const_pointer hash_control() noexcept
    {
      static const progmem_hash_result_type value =
      {{
        // 53C1936F922C570420A2356BAC348225E6D429CE
        0x53U, 0xC1U, 0x93U, 0x6FU, 0x92U, 0x2CU, 0x57U, 0x04U,
        0x20U, 0xA2U, 0x35U, 0x6BU, 0xACU, 0x34U, 0x82U, 0x25U,
        0xE6U, 0xD4U, 0x29U, 0xCEU
      }};

      return value.data();
    }
  };

  template<>
  struct pi_digits_hash_control<std::uintptr_t(10001UL)> : pi_digits_hash_control_base
  {
    static typename progmem_hash_result_type::const_pointer hash_control() noexcept
    {
      static const progmem_hash_result_type value =
      {{
        // 4BDF69A5FF25B9BED6BA9802BD2A68306FAB71EC
        0x4BU, 0xDFU, 0x69U, 0xA5U, 0xFFU, 0x25U, 0xB9U, 0xBEU,
        0xD6U, 0xBAU, 0x98U, 0x02U, 0xBDU, 0x2AU, 0x68U, 0x30U,
        0x6FU, 0xABU, 0x71U, 0xECU
      }};

      return value.data();
    }
  };

  template<>
  struct pi_digits_hash_control<std::uintptr_t(50001UL)> : pi_digits_hash_control_base
  {
    static typename progmem_hash_result_type::const_pointer hash_control() noexcept
    {
      static const progmem_hash_result_type value =
      {{
        // 50001: 8A7595C31618ACE733589B0A15B994F7F65A7A55
        0x8AU, 0x75U, 0x95U, 0xC3U, 0x16U, 0x18U, 0xACU, 0xE7U,
        0x33U, 0x58U, 0x9BU, 0x0AU, 0x15U, 0xB9U, 0x94U, 0xF7U,
        0xF6U, 0x5AU, 0x7AU, 0x55U
      }};

      return value.data();
    }
  };

  template<>
  struct pi_digits_hash_control<std::uintptr_t(100001UL)> : pi_digits_hash_control_base
  {
    static typename progmem_hash_result_type::const_pointer hash_control() noexcept
    {
      static const progmem_hash_result_type value =
      {{
        // 100001: D9D56240EB6B626A8FE179E3054D332F1767071D
        0xD9U, 0xD5U, 0x62U, 0x40U, 0xEBU, 0x6BU, 0x62U, 0x6AU,
        0x8FU, 0xE1U, 0x79U, 0xE3U, 0x05U, 0x4DU, 0x33U, 0x2FU,
        0x17U, 0x67U, 0x07U, 0x1DU
      }};

      return value.data();
    }
  };

  } } // namespace math::constants

#endif // PI_DIGITS_HASH_SHA1_CONTROLS_2020_05_14_H_
