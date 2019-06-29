/*****************************************************************************/
/** 
 * \file        uart-Hc05ToP1.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       show content of data which from HC-05 module(via UART) to GPIO1
 * \note        
 * \test-board  TS51-V2.0
 * \test-mcu    STC89C52RC
 * \version     v0.1
 * \ingroup     example
******************************************************************************/

#include "conf.h"

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    UART_configTypeDef uc;
    
    uc.baudrate          = 9600;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = DISABLE;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
    enableAllInterrupts();
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     
 * \remarks     
******************************************************************************/
void main(void)
{
    sys_init();
    while(true);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       interrupt service function for UART
 * \param[in]   
 * \return      none
 * \ingroup     
 * \remarks     
******************************************************************************/
void uart_isr(void) __interrupt SI0_VECTOR
{
    P1 = SBUF;
    RI = RESET;
}

