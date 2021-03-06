// The long term plan is to have a single soc_caps.h for all peripherals.
// During the refactoring and multichip support development process, we
// separate these information into periph_caps.h for each peripheral and
// include them here to avoid developing conflicts.

#pragma once

/*-------------------------- COMMON CAPS ---------------------------------------*/
#define SOC_PCNT_SUPPORTED              1
#define SOC_TWAI_SUPPORTED              1
#define SOC_GDMA_SUPPORTED              1
#define SOC_DEDICATED_GPIO_SUPPORTED    1
#define SOC_CPU_CORES_NUM               2
#define SOC_CACHE_SUPPORT_WRAP          1
#define SOC_ULP_SUPPORTED               1
#define SOC_RTC_SLOW_MEM_SUPPORTED      1
#define SOC_CCOMP_TIMER_SUPPORTED       1


/*-------------------------- ADC CAPS ----------------------------------------*/
#include "adc_caps.h"

/*-------------------------- BROWNOUT CAPS -----------------------------------*/
#include "brownout_caps.h"

/*-------------------------- CPU CAPS ----------------------------------------*/
#include "cpu_caps.h"

/*-------------------------- DAC CAPS ----------------------------------------*/
#include "dac_caps.h"

/*-------------------------- GDMA CAPS ---------------------------------------*/
#include "gdma_caps.h"

/*-------------------------- GPIO CAPS ---------------------------------------*/
#include "gpio_caps.h"

/*-------------------------- Dedicated GPIO CAPS -----------------------------*/
#define SOC_DEDIC_GPIO_OUT_CHANNELS_NUM (4) /*!< 4 outward channels on each CPU core */
#define SOC_DEDIC_GPIO_IN_CHANNELS_NUM  (4) /*!< 4 inward channels on each CPU core */

/*-------------------------- I2C CAPS ----------------------------------------*/
#include "i2c_caps.h"

/*-------------------------- I2S CAPS ----------------------------------------*/
#include "i2s_caps.h"

/*-------------------------- LEDC CAPS ---------------------------------------*/
#include "ledc_caps.h"

/*-------------------------- MPU CAPS ----------------------------------------*/
#include "mpu_caps.h"

/*-------------------------- PCNT CAPS ---------------------------------------*/
#define SOC_PCNT_PORT_NUM         (1)
#define SOC_PCNT_UNIT_NUM         (4)
#define SOC_PCNT_UNIT_CHANNEL_NUM (2)

/*-------------------------- RMT CAPS ----------------------------------------*/
#define SOC_RMT_CHANNEL_MEM_WORDS       (48) /*!< Each channel owns 48 words memory (1 word = 4 Bytes) */
#define SOC_RMT_TX_CHANNELS_NUM         (4)  /*!< Number of channels that capable of Transmit */
#define SOC_RMT_RX_CHANNELS_NUM         (4)  /*!< Number of channels that capable of Receive */
#define SOC_RMT_CHANNELS_NUM            (8)  /*!< Total 8 channels (each channel can be configured to either TX or RX) */
#define SOC_RMT_SUPPORT_RX_PINGPONG     (1)  /*!< Support Ping-Pong mode on RX path */
#define SOC_RMT_SUPPORT_RX_DEMODULATION (1)  /*!< Support signal demodulation on RX path (i.e. remove carrier) */
#define SOC_RMT_SUPPORT_TX_LOOP_COUNT   (1)  /*!< Support transmit specified number of cycles in loop mode */
#define SOC_RMT_SUPPORT_TX_GROUP        (1)  /*!< Support a group of TX channels to transmit simultaneously */
#define SOC_RMT_SUPPORT_XTAL            (1)  /*!< Support set XTAL clock as the RMT clock source */

/*-------------------------- RTCIO CAPS --------------------------------------*/
#include "rtc_io_caps.h"

/*-------------------------- SIGMA DELTA CAPS --------------------------------*/
#define SOC_SIGMADELTA_NUM         (1) // 1 sigma-delta peripheral
#define SOC_SIGMADELTA_CHANNEL_NUM (8) // 8 channels

/*-------------------------- SPI CAPS ----------------------------------------*/
#include "spi_caps.h"

/*-------------------------- SPIRAM CAPS ----------------------------------------*/
#define SOC_SPIRAM_SUPPORTED            1

/*-------------------------- SYS TIMER CAPS ----------------------------------*/
#include "systimer_caps.h"

/*-------------------------- TIMER GROUP CAPS --------------------------------*/
#define SOC_TIMER_GROUP_SUPPORT_XTAL       (1)
#define SOC_TIMER_GROUP_COUNTER_BIT_WIDTH  (54)
#define SOC_TIMER_GROUP_PRESCALE_BIT_WIDTH (16)
#define SOC_TIMER_GROUPS                   (2)
#define SOC_TIMER_GROUP_TIMERS_PER_GROUP   (2)
#define SOC_TIMER_GROUP_TOTAL_TIMERS (SOC_TIMER_GROUPS * SOC_TIMER_GROUP_TIMERS_PER_GROUP)
#define SOC_TIMER_GROUP_LAYOUT             {2,2}

/*-------------------------- TOUCH SENSOR CAPS -------------------------------*/
#include "touch_sensor_caps.h"

/*-------------------------- TWAI CAPS ---------------------------------------*/
#include "twai_caps.h"

/*-------------------------- UART CAPS ---------------------------------------*/
#include "uart_caps.h"

#define SOC_UART_SUPPORT_RTC_CLK    (1)     /*!< Support RTC clock as the clock source */
#define SOC_UART_SUPPORT_XTAL_CLK   (1)     /*!< Support XTAL clock as the clock source */

/*--------------------------- SHA CAPS ---------------------------------------*/
/* Max amount of bytes in a single DMA operation is 4095,
   for SHA this means that the biggest safe amount of bytes is
   31 blocks of 128 bytes = 3968
*/
#define SOC_SHA_DMA_MAX_BUFFER_SIZE     (3968)
#define SOC_SHA_SUPPORT_DMA             (1)

/* The SHA engine is able to resume hashing from a user supplied context */
#define SOC_SHA_SUPPORT_RESUME          (1)

/* Has a centralized DMA, which is shared with all peripherals */
#define SOC_SHA_GENERAL_DMA             (1)

/* Supported HW algorithms */
#define SOC_SHA_SUPPORT_SHA1            (1)
#define SOC_SHA_SUPPORT_SHA224          (1)
#define SOC_SHA_SUPPORT_SHA256          (1)
#define SOC_SHA_SUPPORT_SHA384          (1)
#define SOC_SHA_SUPPORT_SHA256          (1)
#define SOC_SHA_SUPPORT_SHA512          (1)
#define SOC_SHA_SUPPORT_SHA512_224      (1)
#define SOC_SHA_SUPPORT_SHA512_256      (1)
#define SOC_SHA_SUPPORT_SHA512_T        (1)

/* Supported HW algorithms */
#define SOC_SHA_SUPPORT_SHA1            (1)
#define SOC_SHA_SUPPORT_SHA256          (1)
#define SOC_SHA_SUPPORT_SHA384          (1)
#define SOC_SHA_SUPPORT_SHA512          (1)


/*--------------------------- RSA CAPS ---------------------------------------*/
#define SOC_RSA_MAX_BIT_LEN    (4096)


/*-------------------------- AES CAPS -----------------------------------------*/
#define SOC_AES_SUPPORT_DMA     (1)

/* Has a centralized DMA, which is shared with all peripherals */
#define SOC_AES_GENERAL_DMA     (1)

#define SOC_AES_SUPPORT_AES_128 (1)
#define SOC_AES_SUPPORT_AES_256 (1)

// Attention: These fixed DMA channels are temporarily workaround before we have a centralized DMA controller API to help alloc the channel dynamically
// Remove them when GDMA driver API is ready
#define SOC_GDMA_SPI2_DMA_CHANNEL (1)
#define SOC_GDMA_SPI3_DMA_CHANNEL (2)
#define SOC_GDMA_SHA_DMA_CHANNEL  (3)
#define SOC_GDMA_AES_DMA_CHANNEL  (4)
