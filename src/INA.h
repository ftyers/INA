// clang-format off
/*!
 @file INA.h
 
 @brief INA Class library header file
 
 @mainpage Arduino library to support the INAxxx family of current sensors
 
 @section Library_intro_section Description
 
 Class definition header for the INA class. This library gives a common interface to various INA
 power monitor devices, see https://github.com/Zanduino/INA/wiki or the code below for a full
 list of currently supported devices.  The INA devices have a 3-5V power supply and, depending
 upon the model, can measure voltages up to 26V or 36V. They are devices with High-Side / Low-Side
 Measurement, Bi-Directional Current and Power Monitor with I2C Compatible Interface. The device
 documentation can be found at the following location:\n
 http://www.ti.com/amplifier-circuit/current-sense/power-current-monitors/products.html\n\n
 Detailed library descriptions are on the INA GitHub Wiki pages at
 https://github.com/Zanduino/INA/wiki\n\n The INA devices, apart from the INA250 and INA260,
 require an external shunt of known resistance to be placed across the high-side or low-side
 supply or ground line and they use the small current generated by the shunt to compute the
 amperage passing across the circuit.  This value, coupled with the voltage measurement, allows
 the amperage and wattage to be computed by the INA device and these values can be read from the
 devices using the industry standard I2C protocol.
 
 @section Style Programming
 @subsection Coding Coding and comments
 OK, I admit that I'm "old school" when it comes to programming style. I am used to using a full
 monitor and keyboard for development and testing, plus I like to heavily document code as it
 helps me remember what I did when I revisit code after several months (or years).  I make use of
 the full width (which I've limited to 112 characters here) and put my comments at the end of
 lines.  I prefer to use descriptive variable names, which means that they tend to be long.
 
 @subsection StyleGuide Style Guide
 Different languages have different coding styles. For the Arduino c++ language I've opted to go
 with one of the big players in the industry and have adopted the coding and style rules that
 Google recommends and which are documented at [Google c++ Style
 Guide](https://google.github.io/styleguide/cppguide.html). I have chosen to put braces on their
 own lines and include braces for even 1-liners. End braces are always commented so that
 convoluted code is more easily untangled.
 
 @subsection Documentation
 The comments have been formatted for use with [Doxygen](doxygen.nl), one of the leading
 documentation systems which is not only free but covers just about anything worth documenting.
 The Doxygen system parses the source files of a package and creates documentation. The default
 output is a set of HTML pages although it can produce single documents.
 
 @subsection comments Comment Format
 This package uses [Markdown](https://en.wikipedia.org/wiki/Markdown) syntax for formatting
 comments, which makes for easy reading directly in the source code and well-formatted
 pretty-print in postprocessing.
 
 @subsection ide IDE
 I've opted for using Microsoft Visual Studio (version 16.2.5) for development, the community
 version can be downloaded for free at [Microsoft
 Downloads](https://visualstudio.microsoft.com/downloads/) and I use the fantastic [Visual
 Micro](https://www.visualmicro.com/) package which give the Arduino IDE inside Visual Studio. The
 base version is free or becomes only slightly annoying nagware after 90 days, but the software is
 inexpensive and the price is well worth it for supporting continued development.
 
 @section doxygen doxygen configuration

 This library is built with the standard "Doxyfile", which is located at
 https://github.com/Zanduino/Common/blob/main/Doxygen. As described on that page, there are only 5
 environment variables used, and these are set in the project's actions file, located at
 https://github.com/Zanduino/INA/blob/master/.github/workflows/ci-doxygen.yml
 Edit this file and set the 5 variables -  PRETTYNAME, PROJECT_NAME, PROJECT_NUMBER, PROJECT_BRIEF
 and PROJECT_LOGO so that these values are used in the doxygen documentation.
 The local copy of the doxyfile should be in the project's root directory in order to do local
 doxygen testing, but the file is ignored on upload to GitHub.

 @section clang-format
 Part of the GitHub actions for CI is running every source file through "clang-format" to ensure
 that coding formatting is done the same for all files. The configuration file ".clang-format" is
 located at https://github.com/Zanduino/Common/tree/main/clang-format and this is used for CI tests
 when pushing to GitHub. The local file, if present in the root directory, is ignored when
 committing and uploading.

 @section license GNU General Public License v3.0

 This program is free software: you can redistribute it and/or modify it under the terms of the GNU
 General Public License as published by the Free Software Foundation, either version 3 of the
 License, or (at your option) any later version. This program is distributed in the hope that it
 will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. You should
 have received a copy of the GNU General Public License along with this program.  If not, see
 <http://www.gnu.org/licenses/>.

@section author Author

Written by Arnd <Arnd@Zanduino.Com> at https://www.github.com/SV-Zanshin

@section versions Changelog

| Version | Date       | Developer   | Comments
| ------- | ---------- | ----------- | --------
| 1.1.1   | 2021-03-12 | x3mEr       | Issue #79. Documentation Update
| 1.0.14  | 2020-12-01 | SV-Zanshin  | Issue #72. Allow INA structures to be in memory rather than EEPROM
| 1.0.14  | 2020-11-30 | johntaves   | Issue #64. begin() does not set values on subsequent calls
| 1.0.14  | 2020-11-29 | SV-Zanshin  | Issue #71. Optimize library, cleanup source code
| 1.0.14  | 2020-10-25 | gallium70   | Issue #66. Error in INA226/230/231 value for "power_LSB"
| 1.0.13  | 2020-07-13 | fg89o       | Issue #62. Added "_EEPROM_size" for ESP32 and ESP8266
| 1.0.13  | 2020-07-13 | fg89o       | Issue #62. Incorrect "_EEPROM_offset" computation
| 1.0.12  | 2020-07-13 | SV-Zanshin  | Issue #41. Added "_EEPROM_offset" variable
| 1.0.12  | 2020-07-03 | sages       | Issue #60. Possible Overflow getBus(MicroAmps,MicroWatts)
| 1.0.11  | 2020-06-30 | SV-Zanshin  | Issue #58, changed formatting to use clang-format
| 1.0.11  | 2020-06-29 | SV-Zanshin  | Issue #57. "Alert..." functions should be "alert..."
| 1.0.11  | 2020-05-05 | oliverb68   | Issue #56. Limit of +/- 2kW on getBusMicroWatts
| 1.0.10  | 2020-05-03 | we9v        | Issue #54. Limit of 127A maximum current changed to 1022A
| 1.0.10  | 2020-05-01 | nathancheek | Issue #53. Extraneous conversion on getShuntMicrovolts
| 1.0.10  | 2020-03-24 | nathancheek | Issue #52. Search for all 16 possible devices
| 1.0.10  | 2020-03-22 | alphaarea   | Issue #50. Wiki fix for "begin()" - MaxBusAmps overflow
| 1.0.9   | 2019-12-15 | Steamerzone | Issue #49. Added ifdef for STM32F1 device support
| 1.0.9   | 2019-10-27 | SV-Zanshin  | Cleaned up Doxygen formatting
| 1.0.9   | 2019-10-17 | nathancheek | Issue #47. Added EEPROM support for teensy
| 1.0.8   | 2019-09-03 | miky2k      | Issue #43. Added new method "conversionFinished()"
| 1.0.8   | 2019-05-23 | avaldebe    | Issue #42. Restrict I2C scan to possible devices
| 1.0.8   | 2019-03-24 | mattlogic   | Issue #40. Corrected INA226_CONFIG_SADC_MASK value
| 1.0.8   | 2019-03-17 | SV-Zanshin  | Issue #19. Corrected 4 value ranges in bus/shunt conversion
| 1.0.8   | 2019-02-16 | SV-Zanshin  | Corrected and tested ESP32 implementation
| 1.0.8   | 2019-02-10 | SV-Zanshin  | Issue #39. Allow non-AVR processors without EEPROM to run
| 1.0.8   | 2019-02-09 | SV-Zanshin  | Cleaned up doxygen comment formatting in .h and .cpp files
| 1.0.8   | 2019-02-09 | SV-Zanshin  | Issue #38. Add getDeviceAddress() function
| 1.0.7   | 2019-01-20 | SV-Zanshin  | Issue #36&37. Changed for Travis-CI and automated doxygen
| 1.0.7   | 2018-12-27 | SV-Zanshin  | Issue #33. Change program documentation to doxygen format
| 1.0.6   | 2018-12-13 | delboy711   | Issue #32. Incorrect ESP2866 rather than ESP8266
| 1.0.6   | 2018-10-19 | SV-Zanshin  | Issue #31. Use full 0-32V Range on INA219 all the time
| 1.0.6   | 2018-10-19 | SV-Zanshin  | Issue #30. Added TEENSY support & support large EEPROM
| 1.0.6   | 2018-10-14 | SV-Zanshin  | Added correct wire handling for ESP8266 and ESP32
| 1.0.6   | 2018-10-07 | SV-Zanshin  | Optimized getBusRaw() and getShuntRaw() functions
| 1.0.5   | 2018-10-04 | SV-Zanshin  | Added getBusRaw() and getShuntRaw() functions
| 1.0.5   | 2018-09-29 | SV-Zanshin  | Reformatted comments to different c++ coding style
| 1.0.4   | 2018-09-22 | SV-Zanshin  | Issue #27. EEPROM Calls don't work with ESP32
| 1.0.4   | 2018-09-19 | SV-Zanshin  | Issue #28. Ovef error when >31Amps specified in begin()
| 1.0.3   | 2018-09-04 | delboy711   | Issue #26. Incorrect INA3221 negative current readings
| 1.0.3   | 2018-08-18 | SV-Zanshin  | Issue #22. Reduce EEPROM Footprint
| 1.0.3   | 2018-08-18 | SV-Zanshin  | Issue #21. Rename I2C Constants to avoid redefine STM32F1
| 1.0.2   | 2018-07-22 | SV-Zanshin  | Issue #11. Reduce EEPROM footprint. Removed "deviceName", 8B. Changed datatype in structure to bit-level length defs, saving additional 3 bytes
| 1.0.2   | 2018-07-21 | avaldeve    | Issue #12. Incorrect const datatype for I2C Speeds
| 1.0.2   | 2018-07-12 | coelner     | Issue #9. Esplora doesn't accept "Wire.begin()"
| 1.0.2   | 2018-07-08 | SV-Zanshin  | Issue #2. Finished testing INA3221 across all functions
| 1.0.2   | 2018-07-07 | dnlwgnd     | Issue #4. Guard code used incorrect label
| 1.0.2   | 2018-06-30 | SV-Zanshin  | Issue #3. Adding faster I2C bus support
| 1.0.2   | 2018-06-29 | SV-Zanshin  | Issue #2. Adding INA3221 support to library
| 1.0.2   | 2018-06-29 | SV-Zanshin  | Issue #2. Adding INA3221 support to library
| 1.0.1   | 2018-06-24 | SV-Zanshin  | Removed extraneous elements from ina struct, optimized code
| 1.0.1b  | 2018-06-23 | SV-Zanshin  | Fixed error on multiple devices with ina structure contents
| 1.0.1a  | 2018-06-23 | SV-Zanshin  | Removed debug mode and code
| 1.0.0   | 2018-06-22 | SV-Zanshin  | Initial release
| 1.0.0b  | 2018-06-17 | SV-Zanshin  | Continued coding, tested on INA219 and INA226
| 1.0.0a  | 2018-06-10 | SV-Zanshin  | Initial coding began
*/
#if ARDUINO >= 100 /* Use old library if IDE is prior to V1.0 */
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#ifndef INA__Class_h
/*! Guard code definition to prevent multiple includes */
#define INA__Class_h
/*! typedef contains a packed bit-level defs of information stored per device */
typedef struct {
  uint8_t  type : 4;           ///< 0-15        see enumerated "ina_Type" for details
  uint8_t  operatingMode : 4;  ///< 0-15        Default to continuous mode
  uint32_t address : 7;        ///< 0-127       I2C Address of device
  uint32_t maxBusAmps : 10;    ///< 0-1023      Store initialization value
  uint32_t microOhmR : 20;     ///< 0-1,048,575 Store initialization value
} inaEEPROM;                   // of structure
/*! typedef contains a packed bit-level definition of information stored on a device */
typedef struct inaDet : inaEEPROM {
  uint8_t  busVoltageRegister : 3;    ///< 0- 7, Bus Voltage Register
  uint8_t  shuntVoltageRegister : 3;  ///< 0- 7, Shunt Voltage Register
  uint8_t  currentRegister : 3;       ///< 0- 7, Current Register
  uint16_t shuntVoltage_LSB;          ///< Device dependent LSB factor
  uint16_t busVoltage_LSB;            ///< Device dependent LSB factor
  uint32_t current_LSB;               ///< Amperage LSB
  uint32_t power_LSB;                 ///< Wattage LSB
  inaDet();                           ///< struct constructor
  inaDet(inaEEPROM& inaEE);           ///< for ina = inaEE; assignment
} inaDet;                             // of structure
/*! Enumerated list detailing the names of all supported INA devices. The INA3221 is stored
    as 3 distinct devices each with their own enumerated type. */
enum ina_Type {
  INA219,
  INA226,
  INA230,
  INA231,
  INA260,
  INA3221_0,
  INA3221_1,
  INA3221_2,
  INA_UNKNOWN
};
/*! Enumerated list detailing the operating modes of a given device */
enum ina_Mode {
  INA_MODE_SHUTDOWN,          ///< Device powered down
  INA_MODE_TRIGGERED_SHUNT,   ///< Triggered shunt, no bus
  INA_MODE_TRIGGERED_BUS,     ///< Triggered bus, no shunt
  INA_MODE_TRIGGERED_BOTH,    ///< Triggered bus and shunt
  INA_MODE_POWER_DOWN,        ///< shutdown or power-down
  INA_MODE_CONTINUOUS_SHUNT,  ///< Continuous shunt, no bus
  INA_MODE_CONTINUOUS_BUS,    ///< Continuous bus, no shunt
  INA_MODE_CONTINUOUS_BOTH    ///< Both continuous, default value
};                            // of enumerated type
/************************************************************************************************
** Declare constants used in the class                                                         **
************************************************************************************************/
#ifndef INA_I2C_MODES                             // I2C related constants
#define INA_I2C_MODES                             // Guard code to prevent multiple defs
const uint32_t INA_I2C_STANDARD_MODE{100000};     ///< Default normal I2C 100KHz speed
const uint32_t INA_I2C_FAST_MODE{400000};         ///< Fast mode
const uint32_t INA_I2C_FAST_MODE_PLUS{1000000};   ///< Really fast mode
const uint32_t INA_I2C_HIGH_SPEED_MODE{3400000};  ///< Turbo mode
#endif
const uint8_t  INA_CONFIGURATION_REGISTER{0};       ///< Configuration Register address
const uint8_t  INA_BUS_VOLTAGE_REGISTER{2};         ///< Bus Voltage Register address
const uint8_t  INA_POWER_REGISTER{3};               ///< Power Register address
const uint8_t  INA_CALIBRATION_REGISTER{5};         ///< Calibration Register address
const uint8_t  INA_MASK_ENABLE_REGISTER{6};         ///< Mask enable Register (some devices)
const uint8_t  INA_ALERT_LIMIT_REGISTER{7};         ///< Alert Limit Register (some devices)
const uint8_t  INA_MANUFACTURER_ID_REGISTER{0xFE};  ///< Mfgr ID Register (some devices)
const uint8_t  INA_DIE_ID_REGISTER{0xFF};           ///< Die ID Register (some devices)
const uint16_t INA_RESET_DEVICE{0x8000};            ///< Write to config to reset device
const uint16_t INA_CONVERSION_READY_MASK{0x0080};   ///< Bit 4
const uint16_t INA_CONFIG_MODE_MASK{0x0007};        ///< Bits 0-3
const uint16_t INA_ALERT_MASK{0x03FF};              ///< Mask off bits 0-9
const uint8_t  INA_ALERT_SHUNT_OVER_VOLT_BIT{15};   ///< Register bit
const uint8_t  INA_ALERT_SHUNT_UNDER_VOLT_BIT{14};  ///< Register bit
const uint8_t  INA_ALERT_BUS_OVER_VOLT_BIT{13};     ///< Register bit
const uint8_t  INA_ALERT_BUS_UNDER_VOLT_BIT{12};    ///< Register bit
const uint8_t  INA_ALERT_POWER_OVER_WATT_BIT{11};   ///< Register bit
const uint8_t  INA_ALERT_CONVERSION_RDY_BIT{10};    ///< Register bit
const uint8_t  INA_DEFAULT_OPERATING_MODE{B111};    ///< Default continuous mode
const uint8_t  INA219_SHUNT_VOLTAGE_REGISTER{1};    ///< INA219 Shunt Voltage Register
const uint8_t  INA219_CURRENT_REGISTER{4};          ///< INA219 Current Register
const uint16_t INA219_BUS_VOLTAGE_LSB{400};         ///< INA219 LSB in uV *100 4.00mV
const uint16_t INA219_SHUNT_VOLTAGE_LSB{100};       ///< INA219 LSB in uV *10  10.0uV
const uint16_t INA219_CONFIG_AVG_MASK{0x07F8};      ///< INA219 Bits 3-6, 7-10
const uint16_t INA219_CONFIG_PG_MASK{0xE7FF};       ///< INA219 Bits 11-12 masked
const uint16_t INA219_CONFIG_BADC_MASK{0x0780};     ///< INA219 Bits 7-10  masked
const uint16_t INA219_CONFIG_SADC_MASK{0x0038};     ///< INA219 Bits 3-5
const uint8_t  INA219_BRNG_BIT{13};                 ///< INA219 Bit for BRNG in config reg
const uint8_t  INA219_PG_FIRST_BIT{11};             ///< INA219 1st bit of Programmable Gain
const uint8_t  INA226_SHUNT_VOLTAGE_REGISTER{1};    ///< INA226 Shunt Voltage Register
const uint8_t  INA226_CURRENT_REGISTER{4};          ///< INA226 Current Register
const uint16_t INA226_BUS_VOLTAGE_LSB{125};         ///< INA226 LSB in uV *100 1.25mV
const uint16_t INA226_SHUNT_VOLTAGE_LSB{25};        ///< INA226 LSB in uV *10  2.5uV
const uint16_t INA226_CONFIG_AVG_MASK{0x0E00};      ///< INA226 Bits 9-11
const uint16_t INA226_DIE_ID_VALUE{0x2260};         ///< INA226 Hard-coded Die ID for INA226
const uint16_t INA226_CONFIG_BADC_MASK{0x01C0};     ///< INA226 Bits 6-8 masked
const uint16_t INA226_CONFIG_SADC_MASK{0x0038};     ///< INA226 Bits 3-4
const uint8_t  INA260_SHUNT_VOLTAGE_REGISTER{0};    ///< INA260 Register doesn't exist
const uint8_t  INA260_CURRENT_REGISTER{1};          ///< INA260 Current Register
const uint16_t INA260_BUS_VOLTAGE_LSB{125};         ///< INA260 LSB in uV *100 1.25mV
const uint16_t INA260_CONFIG_BADC_MASK{0x01C0};     ///< INA260 Bits 6-8  masked
const uint16_t INA260_CONFIG_SADC_MASK{0x0038};     ///< INA260 Bits 3-5  masked
const uint8_t  INA3221_SHUNT_VOLTAGE_REGISTER{1};   ///< INA3221 Register number 1
const uint16_t INA3221_BUS_VOLTAGE_LSB{800};        ///< INA3221 LSB in uV *100 8mV
const uint16_t INA3221_SHUNT_VOLTAGE_LSB{400};      ///< INA3221 LSB in uV *10  40uV
const uint16_t INA3221_CONFIG_BADC_MASK{0x01C0};    ///< INA3221 Bits 7-10  masked
const uint8_t  INA3221_MASK_REGISTER{0xF};          ///< INA32219 Mask register
const uint8_t  I2C_DELAY{10};                       ///< Microsecond delay on I2C writes
// clang-format on

class INA_Class {
  /*!
   * @class   INA_Class
   * @brief   Forward definitions for the INA_Class
   */
 public:
  INA_Class(uint8_t expectedDevices = 0);
  ~INA_Class();
  uint8_t     begin(const uint16_t maxBusAmps, const uint32_t microOhmR,
                    const uint8_t deviceNumber = UINT8_MAX);
  void        setI2CSpeed(const uint32_t i2cSpeed = INA_I2C_STANDARD_MODE) const;
  void        setMode(const uint8_t mode, const uint8_t deviceNumber = UINT8_MAX);
  void        setAveraging(const uint16_t averages, const uint8_t deviceNumber = UINT8_MAX);
  void        setBusConversion(const uint32_t convTime, const uint8_t deviceNumber = UINT8_MAX);
  void        setShuntConversion(const uint32_t convTime, const uint8_t deviceNumber = UINT8_MAX);
  uint16_t    getBusMilliVolts(const uint8_t deviceNumber = 0);
  uint16_t    getBusRaw(const uint8_t deviceNumber = 0);
  int32_t     getShuntMicroVolts(const uint8_t deviceNumber = 0);
  int16_t     getShuntRaw(const uint8_t deviceNumber = 0);
  int32_t     getBusMicroAmps(const uint8_t deviceNumber = 0);
  int64_t     getBusMicroWatts(const uint8_t deviceNumber = 0);
  const char* getDeviceName(const uint8_t deviceNumber = 0);
  uint8_t     getDeviceAddress(const uint8_t deviceNumber = 0);
  void        reset(const uint8_t deviceNumber = 0);
  bool        conversionFinished(const uint8_t deviceNumber = 0);
  void        waitForConversion(const uint8_t deviceNumber = UINT8_MAX);
  bool        alertOnConversion(const bool alertState, const uint8_t deviceNumber = UINT8_MAX);
  bool        alertOnShuntOverVoltage(const bool alertState, const int32_t milliVolts,
                                      const uint8_t deviceNumber = UINT8_MAX);
  bool        alertOnShuntUnderVoltage(const bool alertState, const int32_t milliVolts,
                                       const uint8_t deviceNumber = UINT8_MAX);
  bool        alertOnBusOverVoltage(const bool alertState, const int32_t milliVolts,
                                    const uint8_t deviceNumber = UINT8_MAX);
  bool        alertOnBusUnderVoltage(const bool alertState, const int32_t milliVolts,
                                     const uint8_t deviceNumber = UINT8_MAX);
  bool        alertOnPowerOverLimit(const bool alertState, const int32_t milliAmps,
                                    const uint8_t deviceNumber = UINT8_MAX);
  uint16_t    _EEPROM_offset = 0;  ///< Offset to all EEPROM addresses, GitHub issue #41
#if defined(ESP32) || defined(ESP8266)
  uint16_t _EEPROM_size = 512;  ///< Default EEPROM reserved space for ESP32 and ESP8266
#endif
 private:
  int16_t    readWord(const uint8_t addr, const uint8_t deviceAddress) const;
  void       writeWord(const uint8_t addr, const uint16_t data, const uint8_t deviceAddress) const;
  void       readInafromEEPROM(const uint8_t deviceNumber);
  void       writeInatoEEPROM(const uint8_t deviceNumber);
  void       initDevice(const uint8_t deviceNumber);
  uint8_t    _DeviceCount{0};         ///< Total number of devices detected
  uint8_t    _currentINA{UINT8_MAX};  ///< Stores current INA device number
  uint8_t    _expectedDevices{0};     ///< If 0 use EEPROM, otherwise use RAM for INA structures
  inaEEPROM* _DeviceArray;            ///< Pointer to dynamic array of devices if not using EEPROM
  inaEEPROM  inaEE;                   ///< INA device structure
  inaDet     ina;                     ///< INA device structure
#if defined(__AVR__) || defined(CORE_TEENSY) || defined(ESP32) || defined(ESP8266) || (__STM32F1__)
#else
  inaEEPROM _EEPROMEmulation[32];  ///< Actual array of up to 32 devices
#endif
};  // of INA_Class definition
#endif
