/*==============================================================================
Generated on: 2024-03-11 20:33:45.072433
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: ZEEZF7
Manufacturer ID: ZEEZ

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_ZEEZ-ZEEZF7.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-ZEEZ-ZEEZF7"
#define HW_MCU "STM32F7X2"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25N01G"
#define OSD_USE  OSD_USE_MAX7456
#define USE_CAMERA_CONTROL

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0FLIP
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PC14;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI2)
const int HW_PIN_SPI_MISO = PB14;
const int HW_PIN_SPI_MOSI = PB15;
const int HW_PIN_SPI_SCLK = PB13;
const int HW_PIN_IMU_CS   = PB12;
const int HW_PIN_IMU_EXTI = PC9;

//BARO/MAG I2C: (I2C1)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB8,PB7,PB6,PB4};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL2)
const int HW_PIN_GPS_RX   = PA3;
const int HW_PIN_GPS_TX   = PA2;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC2;
const int HW_PIN_BAT_I    = PC3;

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
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB8,PB7,PB6,PB4}

//other pins
#define HW_PIN_BEEPER PB2
#define HW_PIN_PPM PA1
#define HW_PIN_LED_STRIP PB0
//#define HW_PIN_LED PC14
#define HW_PIN_LED_2 PC15
#define HW_PIN_CAMERA_CONTROL PA8
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_CURR PC3
#define HW_PIN_PINIO PB11
#define HW_PIN_FLASH_CS PA4
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PC9
#define HW_PIN_GYRO_CS PB12

//set statements
#define HW_SET_MAG_HARDWARE NONE
#define HW_SET_BARO_HARDWARE NONE
#define HW_SET_SERIALRX_PROVIDER CRSF
#define HW_SET_ADC_DEVICE 3
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_VBAT_SCALE 110
#define HW_SET_IBATA_SCALE 350
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_PINIO_CONFIG 1,1,1,1
#define HW_SET_PINIO_BOX 40,255,255,255
#define HW_SET_BOX_USER_1_NAME VTX
#define HW_SET_FLASH_SPI_BUS 1
#define HW_SET_GYRO_1_SPIBUS 2
#define HW_SET_GYRO_1_SENSOR_ALIGN CW0FLIP
#define HW_SET_GYRO_1_ALIGN_PITCH 1800
#define HW_SET_OSD_CORE_TEMP_ALARM 85


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F7X2 (S7X2) 4.1.2 Dec 22 2019 / 02:21:16 (89051e256) MSP API: 1.42

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_W25N01G
#define USE_MAX7456
#define USE_CAMERA_CONTROL

board_name ZEEZF7
manufacturer_id ZEEZ

# resources
resource BEEPER 1 B02
resource MOTOR 1 B08
resource MOTOR 2 B07
resource MOTOR 3 B06
resource MOTOR 4 B04
resource PPM 1 A01
resource LED_STRIP 1 B00
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource LED 1 C14
resource LED 2 C15
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource CAMERA_CONTROL 1 A08
resource ADC_BATT 1 C02
resource ADC_CURR 1 C03
resource PINIO 1 B11
resource FLASH_CS 1 A04
resource OSD_CS 1 A15
resource GYRO_EXTI 1 C09
resource GYRO_CS 1 B12

# timer
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B00 AF1
# pin B00: TIM1 CH2N (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)

# dma
dma ADC 3 1
# ADC 3: DMA2 Stream 1 Channel 2
dma pin A01 0
# pin A01: DMA1 Stream 6 Channel 3
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0

# feature
feature RX_SERIAL
feature LED_STRIP
feature OSD
feature ESC_SENSOR

# serial
serial 0 1024 115200 57600 0 115200
serial 2 2048 115200 57600 0 115200
serial 3 64 115200 57600 0 115200

# led
led 0 0,15::C:6
led 1 1,15::C:6
led 2 2,15::C:6
led 3 3,15::C:1
led 4 4,15::C:1
led 5 5,15::C:1
led 6 6,15::C:1
led 7 7,15::C:2
led 8 8,15::C:2
led 9 9,15::C:2
led 10 10,15::C:2

# master
set mag_hardware = NONE
set baro_hardware = NONE
set serialrx_provider = CRSF
set adc_device = 3
set blackbox_device = SPIFLASH
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set vbat_scale = 110
set ibata_scale = 350
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 3
set pinio_config = 1,1,1,1
set pinio_box = 40,255,255,255
set box_user_1_name = VTX SWITCH
set flash_spi_bus = 1
set gyro_1_spibus = 2
set gyro_1_sensor_align = CW0FLIP
set gyro_1_align_pitch = 1800
set osd_core_temp_alarm = 85

*/