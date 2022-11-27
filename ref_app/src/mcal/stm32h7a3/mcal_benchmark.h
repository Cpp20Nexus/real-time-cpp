﻿///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2022.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_BENCHMARK_2022_08_03_H_
  #define MCAL_BENCHMARK_2022_08_03_H_

  #include <cstdint>
  #include <mcal_port.h>
  #include <mcal_reg.h>

  namespace mcal
  {
    namespace benchmark
    {
      using benchmark_port_type = mcal::port::port_pin<std::uint32_t,
                                                       std::uint32_t,
                                                       mcal::reg::gpiod_base,
                                                       UINT32_C(3)>;
    }
  }

#endif // MCAL_BENCHMARK_2022_08_03_H_
