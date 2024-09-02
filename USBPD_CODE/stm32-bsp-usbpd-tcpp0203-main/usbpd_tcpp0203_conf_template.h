/**
  ******************************************************************************
  * @file    usbpd-tcpp0203_conf_template.h
  * @author  MCD Application Team
  * @brief   USBPD-TCPP0203 driver configuration template file.
  *          This file should be copied to the application folder and renamed
  *          to usbpd-tcpp0203_conf.h.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef USBPD_TCPP0203_CONF_TEMPLATE_H__
#define USBPD_TCPP0203_CONF_TEMPLATE_H__

#ifdef __cplusplus
extern "C" {
#endif
    
#include"../src/config/default/peripheral/port/plib_port.h"
#include"../src/config/default/peripheral/adc/plib_adc.h"
#include"../src/config/default/peripheral/adc/plib_adc_common.h"

/* Includes ------------------------------------------------------------------*/
/* Replace the header file names with the ones of the target platform */
#if defined(USE_STM32G4XX_NUCLEO)
#include "stm32g4xx_nucleo.h"
#include "stm32g4xx_ll_adc.h"
#include "stm32g4xx_ll_dma.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_exti.h"
#include "stm32g4xx_ll_system.h"
#include "stm32g4xx_nucleo_errno.h"
#elif defined(USE_STM32G0XX_NUCLEO)
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_gpio.h"
#include "stm32g0xx_ll_exti.h"
#include "stm32g0xx_ll_system.h"
#include "stm32g0xx_ll_adc.h"
#include "stm32g0xx_ll_dma.h"
#include "stm32g0xx_nucleo.h"
/* STM32G0 series using BSP V1 framework, no conf template file, no error definitions, ... */
#elif defined(_SAMD21G17D_H_)

#else
//#warning "Please select include files according to HW setup"
#endif /* USE_STM32G4XX_NUCLEO */


/** @addtogroup USBPD-TCPP0203
  * @{
  */

/** @addtogroup USBPD-TCPP0203_CONFIG
  * @{
  */

/** @addtogroup USBPD-TCPP0203_CONFIG_Exported_Constants Exported Constants
  * @{
  */

/* I2C BUS definitions */
#define BUS_I2C_INSTANCE                 I2C1

#ifndef BUS_I2C_FREQUENCY
#define BUS_I2C_FREQUENCY                400000U /* Frequency of I2Cn = 400 kHz*/
#endif /* !BUS_I2C_FREQUENCY */

#define BUS_I2C_CLK_ENABLE()             __HAL_RCC_I2C1_CLK_ENABLE()
#define BUS_I2C_CLK_DISABLE()            __HAL_RCC_I2C1_CLK_DISABLE()
#define BUS_I2C_FORCE_RESET()            __HAL_RCC_I2C1_FORCE_RESET()
#define BUS_I2C_RELEASE_RESET()          __HAL_RCC_I2C1_RELEASE_RESET()

#define BUS_I2C_SCL_GPIO_PIN             GPIO_PIN_8
#define BUS_I2C_SCL_GPIO_PORT            GPIOB
#if defined(USE_STM32G4XX_NUCLEO)
#define BUS_I2C_SCL_GPIO_AF              GPIO_AF4_I2C1
#elif defined(USE_STM32G0XX_NUCLEO)
#define BUS_I2C_SCL_GPIO_AF              GPIO_AF6_I2C1
#endif /* USE_STM32G4XX_NUCLEO */
#define BUS_I2C_SCL_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_I2C_SCL_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOB_CLK_DISABLE()
#define BUS_I2C_SDA_GPIO_PIN             GPIO_PIN_9
#define BUS_I2C_SDA_GPIO_PORT            GPIOB
#if defined(USE_STM32G4XX_NUCLEO)
#define BUS_I2C_SDA_GPIO_AF              GPIO_AF4_I2C1
#elif defined(USE_STM32G0XX_NUCLEO)
#define BUS_I2C_SDA_GPIO_AF              GPIO_AF6_I2C1
#endif /* USE_STM32G4XX_NUCLEO */
#define BUS_I2C_SDA_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_I2C_SDA_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOB_CLK_DISABLE()

#define BUS_I2C_POLL_TIMEOUT             0x1000U

//#define VISENSE_DMA_INSTANCE            DMA1 /* Common for VSENSE and ISENSE */
//#define VISENSE_DMA_CHANNEL             LL_DMA_CHANNEL_1
//#define VISENSE_DMA_REQ                 LL_DMAMUX_REQ_ADC1 /* Select ADC as DMA transfer request */
#if defined(USE_STM32G0XX_NUCLEO)
#define VISENSE_DMAMUX_CHANNEL          LL_DMAMUX_CHANNEL_0 /* Channel needs to be VISENSE_DMA_CHANNEL - 1 */
#endif /* USE_STM32G0XX_NUCLEO */

#define VISENSE_ADC_INSTANCE            ADC1 /* Common for VSENSE and ISENSE */

#define VSENSE_ADC_COMMON               ADC12_COMMON
#define VSENSE_ADC_RANK                 LL_ADC_REG_RANK_1
#if defined(USE_STM32G4XX_NUCLEO)
#define VSENSE_ADC_CHANNEL              LL_ADC_CHANNEL_1
#elif defined(USE_STM32G0XX_NUCLEO)
#define VSENSE_ADC_CHANNEL              LL_ADC_CHANNEL_0
#endif /* USE_STM32G4XX_NUCLEO */

#define ISENSE_ADC_COMMON               ADC12_COMMON
#define ISENSE_ADC_RANK                 LL_ADC_REG_RANK_2
#if defined(USE_STM32G4XX_NUCLEO)
#define ISENSE_ADC_CHANNEL              LL_ADC_CHANNEL_7
#elif defined(USE_STM32G0XX_NUCLEO)
#define ISENSE_ADC_CHANNEL              LL_ADC_CHANNEL_15
#endif /* USE_STM32G4XX_NUCLEO */

#define VISENSE_ADC_BUFFER_SIZE         2u /* Number of ADC channels used */

/**
  * @brief TCPP0203_FLGn pin
  * To be defined for each Port, protected by a TCPP0203 component
  */
#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_FLG_GPIO_CLK_ENABLE()        LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
#define TCPP0203_PORT0_FLG_GPIO_CLK_DISABLE()       LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_FLG_GPIO_CLK_ENABLE()        LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC)
#define TCPP0203_PORT0_FLG_GPIO_CLK_DISABLE()       LL_IOP_GRP1_DisableClock(LL_IOP_GRP1_PERIPH_GPIOC)
#endif /* USE_STM32G4XX_NUCLEO */
#define TCPP0203_PORT0_FLG_GPIO_PORT                1//GPIOC
#define TCPP0203_PORT0_FLG_GPIO_PIN                 1//LL_GPIO_PIN_5
#define TCPP0203_PORT0_FLG_GPIO_MODE                1//LL_GPIO_MODE_INPUT
#define TCPP0203_PORT0_FLG_GPIO_PUPD                1//LL_GPIO_PULL_UP
#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_FLG_SET_EXTI()               LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTC, LL_SYSCFG_EXTI_LINE5);
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_FLG_SET_EXTI()               LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTC, LL_EXTI_CONFIG_LINE5);
#endif /* USE_STM32G4XX_NUCLEO */
#define TCPP0203_PORT0_FLG_EXTI_LINE               1// LL_EXTI_LINE_5
#define TCPP0203_PORT0_FLG_EXTI_ENABLE()            1//LL_EXTI_EnableIT_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);
#define TCPP0203_PORT0_FLG_EXTI_DISABLE()           1//LL_EXTI_DisableIT_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);
#define TCPP0203_PORT0_FLG_TRIG_ENABLE()            1//LL_EXTI_EnableFallingTrig_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);
#define TCPP0203_PORT0_FLG_TRIG_DISABLE()           1//LL_EXTI_DisableFallingTrig_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);
#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_FLG_EXTI_IS_ACTIVE_FLAG()    LL_EXTI_IsActiveFlag_0_31(TCPP0203_PORT0_FLG_EXTI_LINE)
#define TCPP0203_PORT0_FLG_EXTI_CLEAR_FLAG()        LL_EXTI_ClearFlag_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);
#define TCPP0203_PORT0_FLG_EXTI_IRQN                EXTI9_5_IRQn
#define TCPP0203_PORT0_FLG_EXTI_IRQHANDLER          EXTI9_5_IRQHandler
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_FLG_EXTI_IS_ACTIVE_FLAG()    LL_EXTI_IsActiveFallingFlag_0_31(TCPP0203_PORT0_FLG_EXTI_LINE)
#define TCPP0203_PORT0_FLG_EXTI_CLEAR_FLAG()        LL_EXTI_ClearFallingFlag_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);
#define TCPP0203_PORT0_FLG_EXTI_IRQN                EXTI4_15_IRQn
#define TCPP0203_PORT0_FLG_EXTI_IRQHANDLER          EXTI4_15_IRQHandler
#endif /* USE_STM32G4XX_NUCLEO */

#define TCPP0203_PORT0_FLG_IT_PRIORITY              (12U)
#define TCPP0203_PORT0_FLG_GENERATE_IT()            LL_EXTI_GenerateSWI_0_31(TCPP0203_PORT0_FLG_EXTI_LINE);

/**
  * @brief TCPP0203_PWRENn pin
  */
#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_ENABLE_GPIO_CLK_ENABLE()     LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
#define TCPP0203_PORT0_ENABLE_GPIO_CLK_DISABLE()    LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_ENABLE_GPIO_CLK_ENABLE()     LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC)
#define TCPP0203_PORT0_ENABLE_GPIO_CLK_DISABLE()    LL_IOP_GRP1_DisableClock(LL_IOP_GRP1_PERIPH_GPIOC)
#elif defined(_SAMD21G17D_H_)
#define TCPP0203_PORT0_ENABLE_GPIO_PORT             1//GPIOC
#define TCPP0203_PORT0_ENABLE_GPIO_PIN              EN_PIN
#define TCPP0203_PORT0_ENABLE_GPIO_MODE             EN_OutputEnable()
#define TCPP0203_PORT0_ENABLE_GPIO_OUTPUT           NULL//LL_GPIO_OUTPUT_PUSHPULL
#define TCPP0203_PORT0_ENABLE_GPIO_PUPD             NULL
#define TCPP0203_PORT0_ENABLE_GPIO_DEFVALUE()       EN_Clear()
#define TCPP0203_PORT0_ENABLE_GPIO_SET()            EN_Set()
#define TCPP0203_PORT0_ENABLE_GPIO_RESET()          EN_Clear() 
#else
#define TCPP0203_PORT0_ENABLE_GPIO_PORT             1//GPIOC
#define TCPP0203_PORT0_ENABLE_GPIO_PIN              EN_PIN
#define TCPP0203_PORT0_ENABLE_GPIO_MODE             EN_OutputEnable()
#define TCPP0203_PORT0_ENABLE_GPIO_OUTPUT           NULL//LL_GPIO_OUTPUT_PUSHPULL
#define TCPP0203_PORT0_ENABLE_GPIO_PUPD             NULL
#define TCPP0203_PORT0_ENABLE_GPIO_DEFVALUE()       EN_Clear()
#define TCPP0203_PORT0_ENABLE_GPIO_SET()            EN_Set()
#define TCPP0203_PORT0_ENABLE_GPIO_RESET()          EN_Clear() 
#endif /* USE_STM32G4XX_NUCLEO */

#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_IANA_GPIO_CLK_ENABLE()       LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
#define TCPP0203_PORT0_IANA_GPIO_CLK_DISABLE()      LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
#define TCPP0203_PORT0_IANA_GPIO_PORT               GPIOC
#define TCPP0203_PORT0_IANA_GPIO_PIN                LL_GPIO_PIN_1
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_IANA_GPIO_CLK_ENABLE()       LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB)
#define TCPP0203_PORT0_IANA_GPIO_CLK_DISABLE()      LL_IOP_GRP1_DisableClock(LL_IOP_GRP1_PERIPH_GPIOB)
#define TCPP0203_PORT0_IANA_GPIO_PORT               GPIOB
#define TCPP0203_PORT0_IANA_GPIO_PIN                LL_GPIO_PIN_11
#endif /* USE_STM32G4XX_NUCLEO */
#define TCPP0203_PORT0_IANA_GPIO_MODE               LL_GPIO_MODE_ANALOG

#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_VBUSC_GPIO_CLK_ENABLE()      LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
#define TCPP0203_PORT0_VBUSC_GPIO_CLK_DISABLE()     LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_VBUSC_GPIO_CLK_ENABLE()      LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA)
#define TCPP0203_PORT0_VBUSC_GPIO_CLK_DISABLE()     LL_IOP_GRP1_DisableClock(LL_IOP_GRP1_PERIPH_GPIOA)
#endif /* USE_STM32G4XX_NUCLEO */
#define TCPP0203_PORT0_VBUSC_GPIO_PORT              GPIOA
#define TCPP0203_PORT0_VBUSC_GPIO_PIN               LL_GPIO_PIN_0
#define TCPP0203_PORT0_VBUSC_GPIO_MODE              LL_GPIO_MODE_ANALOG

#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_VBUSPROV_GPIO_CLK_ENABLE()   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
#define TCPP0203_PORT0_VBUSPROV_GPIO_CLK_DISABLE()  LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_VBUSPROV_GPIO_CLK_ENABLE()   LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA)
#define TCPP0203_PORT0_VBUSPROV_GPIO_CLK_DISABLE()  LL_IOP_GRP1_DisableClock(LL_IOP_GRP1_PERIPH_GPIOA)
#endif /* USE_STM32G4XX_NUCLEO */
#define TCPP0203_PORT0_VBUSPROV_GPIO_PORT           GPIOA
#define TCPP0203_PORT0_VBUSPROV_GPIO_PIN            LL_GPIO_PIN_1
#define TCPP0203_PORT0_VBUSPROV_GPIO_MODE           LL_GPIO_MODE_ANALOG

#if defined(USE_STM32G4XX_NUCLEO)
#define TCPP0203_PORT0_VBUSCONS_GPIO_CLK_ENABLE()   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
#define TCPP0203_PORT0_VBUSCONS_GPIO_CLK_DISABLE()  LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
#elif defined(USE_STM32G0XX_NUCLEO)
#define TCPP0203_PORT0_VBUSCONS_GPIO_CLK_ENABLE()   LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA)
#define TCPP0203_PORT0_VBUSCONS_GPIO_CLK_DISABLE()  LL_IOP_GRP1_DisableClock(LL_IOP_GRP1_PERIPH_GPIOA)
#endif /* USE_STM32G4XX_NUCLEO */
#define TCPP0203_PORT0_VBUSCONS_GPIO_PORT           GPIOA
#define TCPP0203_PORT0_VBUSCONS_GPIO_PIN            LL_GPIO_PIN_4
#define TCPP0203_PORT0_VBUSCONS_GPIO_MODE           LL_GPIO_MODE_ANALOG

#define USBPD_TCPP0203_VSENSE_RA                            200u /* VBUS voltage divider RA in milliohm */
#define USBPD_TCPP0203_VSENSE_RB                            40u  /* VBUS voltage divider RB in milliohm */

#define USBPD_TCPP0203_ISENSE_GA                            42u  /* Current measure gain In V/V */
#define USBPD_TCPP0203_ISENSE_RS                            7u   /* Current measure shunt resistor in milliohm */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* USBPD-TCPP0203_CONF_H__*/

