///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2024.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_port.h>
#include <mcal_reg.h>

void mcal::port::init(const config_type*)
{
  // Enable the GPIO peripheral clock portb + portc energy.

  // RCC->APB2PCENR.bit.IOPBEN = 1u;
  mcal::reg::reg_access_static<std::uint32_t,
                                 std::uint32_t,
                                 mcal::reg::rcc_apb2pcenr,
                                 UINT32_C(3)>::bit_set();

  // RCC->APB2PCENR.bit.IOPCEN = 1u;
  mcal::reg::reg_access_static<std::uint32_t,
                                 std::uint32_t,
                                 mcal::reg::rcc_apb2pcenr,
                                 UINT32_C(4)>::bit_set();
}
