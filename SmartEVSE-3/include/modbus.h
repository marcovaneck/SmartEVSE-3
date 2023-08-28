/*
;	 Project:       Smart EVSE
;
;
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/

#ifndef __EVSE_MODBUS
#define __EVSE_MODBUS

#include <ModbusClient.h>

struct ModBus {
    uint8_t Address;
    uint8_t Function;
    uint16_t Register;
    uint16_t RegisterCount;
    uint16_t Value;
    uint8_t *Data;
    uint8_t DataLength;
    uint8_t Type;
    uint8_t RequestAddress;
    uint8_t RequestFunction;
    uint16_t RequestRegister;
    uint8_t Exception;
};

uint8_t mapModbusRegister2ItemID(uint16_t Register, uint16_t RegisterCount);

// ########################### Modbus main functions ###########################

void ModbusReadInputRequest(ModbusClient *client, uint8_t address, uint8_t function, uint16_t reg, uint16_t quantity);
void ModbusReadInputResponse(uint8_t address, uint8_t function, uint16_t *values, uint8_t count);
void ModbusWriteSingleRequest(ModbusClient *client, uint8_t address, uint16_t reg, uint16_t value);
void ModbusWriteMultipleRequest(ModbusClient *client, uint8_t address, uint16_t reg, uint16_t *values, uint8_t count);
void ModbusException(uint8_t address, uint8_t function, uint8_t exception);
void ModbusDecode(ModBus * MD, uint8_t *buf, uint8_t len);

// ########################### EVSE modbus functions ###########################

signed int receiveMeasurement(ModbusClient *client, uint8_t *buf, uint8_t pos, uint8_t Endianness, MBDataType dataType, signed char Divisor);
void requestMeasurement(ModbusClient *client, uint8_t Meter, uint8_t Address, uint16_t Register, uint8_t Count);
void requestCurrentMeasurement(ModbusClient *client, uint8_t Meter, uint8_t Address);
uint8_t receiveCurrentMeasurement(ModbusClient *client, uint8_t *buf, uint8_t Meter, signed int *var);

//void ReadItemValueResponse(void);
//void WriteItemValueResponse(void);
//void WriteMultipleItemValueResponse(void);


#endif
