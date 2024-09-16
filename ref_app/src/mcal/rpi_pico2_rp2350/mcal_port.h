///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2024.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_PORT_2012_06_27_H_
  #define MCAL_PORT_2012_06_27_H_

  #include <mcal_reg.h>

  #include <cstdint>

  namespace mcal
  {
    namespace port
    {
      typedef void config_type;
      void init(const config_type*);

      template<const unsigned PortIndex>
      class port_pin
      {
      public:
        static void set_direction_output()
        {
          // SIO Structure: Line 27173
        }

        static void set_direction_input()
        {
        }

        static void set_pin_high()
        {
        }

        static void set_pin_low()
        {
        }

        static bool read_input_value()
        {
          return false;
        }

        static void toggle_pin()
        {
        }
      };
    }
  }

#endif // MCAL_PORT_2012_06_27_H_
