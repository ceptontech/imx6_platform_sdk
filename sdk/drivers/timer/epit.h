/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//! @addtogroup diag_epit
//! @{

/*!
 * @file epit.h
 * @brief EPIT driver public interface.
 */

#ifndef __EPIT_H__
#define __EPIT_H__

#include "sdk.h"
#include "timer.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Free running reload mode.
//!
//! When the counter reaches zero it rolls over to 0xFFFF_FFFF.
#define FREE_RUNNING    0

//! @brief Set and forget reload mode.
//!
//! When the counter reaches zero it reloads from the modulus register.
#define SET_AND_FORGET  1

//! @brief Pass to epit_counter_enable() to enable interrupts.
#define IRQ_MODE 1

////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the EPIT timer.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   clock_src Source clock of the counter: CLKSRC_OFF, CLKSRC_IPG_CLK,
 *                      CLKSRC_PER_CLK, CLKSRC_CKIL.
 * @param   prescaler Prescaler of source clock from 1 to 4096.
 * @param   reload_mode Counter reload mode: FREE_RUNNING or SET_AND_FORGET.
 * @param   load_val Load value from where the counter start.
 * @param   low_power_mode Low power during which the timer is enabled:
 *                           WAIT_MODE_EN and/or STOP_MODE_EN.
 */
void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode);

/*!
 * @brief Setup EPIT interrupt.
 *
 * It enables or disables the related HW module interrupt, and attached the related sub-routine
 * into the vector table.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   enableIt True to enable the interrupt, false to disable.
 */
void epit_setup_interrupt(struct hw_module *port, bool enableIt);

/*!
 * @brief Enable the EPIT module. 
 *
 * Used typically when the epit_init is done, and other interrupt related settings are ready.
 *
 * In interrupt mode, when the interrupt fires you should call epit_get_compare_event() to
 * clear the compare flag.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   load_val Load value from where the counter starts.
 * @param   irq_mode Interrupt mode: IRQ_MODE or POLLING_MODE.
 */
void epit_counter_enable(struct hw_module *port, uint32_t load_val, uint32_t irq_mode);

/*!
 * @brief Disable the counter.
 *
 * It saves energy when not used.
 *
 * @param   port Pointer to the EPIT module structure.
 */
void epit_counter_disable(struct hw_module *port);

/*!
 * @brief Get the output compare status flag and clear it if set.
 * 
 * This function can typically be used for polling method, but
 * is also used to clear the status compare flag in IRQ mode.
 *
 * @param   port Pointer to the EPIT module structure.
 * @return  Value of the compare event flag.
 */
uint32_t epit_get_compare_event(struct hw_module *port);

/*!
 * @brief Set the output compare register.
 * 
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   Value of the compare register.
 */
void epit_set_compare_event(struct hw_module *port, uint32_t compare_val);

/*!
 * @brief Get the counter value.
 * 
 *
 * @param   port Pointer to the EPIT module structure.
 * @return  Value of the counter register.
 */
uint32_t epit_get_counter_value(struct hw_module *port);

/*!
 * @brief Reload the counter with a known value.
 *
 * @param port Pointer to the EPIT module structure.
 * @param load_val Value loaded into the timer counter.
 */
void epit_reload_counter(struct hw_module *port, uint32_t load_val);

#if defined(__cplusplus)
}
#endif

//! @}

#endif //__EPIT_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
