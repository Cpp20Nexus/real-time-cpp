/******************************************************************************************
  Filename    : mtimer.c
  
  Core        : RV32IMAC
  
  MCU         : FE310-G002 (SiFive)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 11.12.2022
  
  Description : mtimer driver implementation
  
******************************************************************************************/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-align"
#endif

//=========================================================================================
// Includes
//=========================================================================================
#include "mtimer.h"
#include "riscv-csr.h"

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void mtimer_ReloadTimer(uint64 timeout)
{
  /* set the reload value */
  MTIMECMP64 = MTIME64 + timeout;
}

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void mtimer_StartTimer(uint64 timeout)
{
  /* configure the timer counters */
  MTIMECMP64 = MTIME64 + timeout;

  /* enable the timer interrupt */
  csr_set_bits_mie(MIE_MTI_BIT_MASK);
}

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
void mtimer_StopTimer(void)
{
  /* stop the timer (will never overflow) */
  MTIMECMP64 = (uint64)-1;
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
