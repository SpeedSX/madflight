/*==============================================================================
Generated on: 2024-03-11 20:33:43.791614
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: GEMEF411
Manufacturer ID: GFPV

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_GFPV-GEMEF411.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-GFPV-GEMEF411"
#define HW_MCU "STM32F411"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "M25P16"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PC13;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC15;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = PB8;
const int HW_PIN_I2C_SCL  = PB9;

//Outputs:
const int HW_OUT_COUNT    = 6;
const int HW_PIN_OUT[]    = {PA8,PB4,PB0,PB5,PA9,PA10};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PB3;
const int HW_PIN_RCIN_TX  = PA15;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PA1;
const int HW_PIN_BAT_I    = PB1;

//Include Libraries
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "madflight/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 4
#define HW_PIN_SERIAL { {1,PA15,PB3,-1}, {2,PA2,PA3,-1}, {11,PB10,PB10,-1}, {12,PB6,PB6,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 6
#define HW_MOTOR_OUT {PA8,PB4,PB0,PB5,PA9,PA10}

//other pins
#define HW_PIN_BEEPER PC14
#define HW_PIN_PPM PA2
#define HW_PIN_LED_STRIP PA0
//#define HW_PIN_LED PC13
#define HW_PIN_ADC_BATT PA1
#define HW_PIN_ADC_CURR PB1
#define HW_PIN_FLASH_CS PB2
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PC15
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_DSHOT_BITBANG ON
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_DSHOT_BURST AUTO
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 800
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_1_ALIGN_YAW 1800


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.3.0 Jun 14 2022 / 00:48:04 (229ac66) MSP API: 1.44

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_BMI270
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

board_name GEMEF411
manufacturer_id GFPV

# resources
resource BEEPER 1 C14
resource MOTOR 1 A08
resource MOTOR 2 B04
resource MOTOR 3 B00
resource MOTOR 4 B05
resource MOTOR 5 A09
resource MOTOR 6 A10
resource PPM 1 A02
resource LED_STRIP 1 A00
resource SERIAL_TX 1 A15
resource SERIAL_TX 2 A02
resource SERIAL_TX 11 B10
resource SERIAL_TX 12 B06
resource SERIAL_RX 1 B03
resource SERIAL_RX 2 A03
resource SERIAL_RX 11 B10
resource SERIAL_RX 12 B06
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource ADC_BATT 1 A01
resource ADC_CURR 1 B01
resource FLASH_CS 1 B02
resource OSD_CS 1 B12
resource GYRO_EXTI 1 C15
resource GYRO_CS 1 A04

# timer
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin A10 0
# pin A10: DMA2 Stream 6 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3

# feature
feature SOFTSERIAL
feature LED_STRIP
feature OSD
feature RX_SERIAL

# serial
serial 1 64 115200 57600 0 115200
serial 30 2048 115200 57600 0 115200

# master
set dshot_bitbang = ON
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set blackbox_device = SPIFLASH
set serialrx_provider = SBUS
set dshot_burst = AUTO
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 800
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW180
set gyro_1_align_yaw = 1800

*/