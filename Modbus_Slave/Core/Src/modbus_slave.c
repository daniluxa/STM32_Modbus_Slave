#include "modbus_slave.h"

extern TIM_HandleTypeDef htim5;
extern UART_HandleTypeDef huart3;

volatile USHORT usRegInputStart = REG_INPUT_START;
volatile USHORT usRegInputBuf[REG_INPUT_NREGS] = {'M', 'o', 'd', 'b', 'u', 's', 0, 0};

void modbusInit()
{
	MT_PORT_SetTimerModule(&htim5);
	MT_PORT_SetUartModule(&huart3);
	eMBErrorCode eStatus;
	eStatus = eMBInit(MB_RTU, MY_ADDRESS, 0, 115200, MB_PAR_NONE);
	eStatus = eMBEnable();
	if (eStatus != MB_ENOERR)
	{
	// Error handling
	}
}

/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
                           eMBRegisterMode eMode)
{
  return MB_ENOREG;
}

/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegDiscreteCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
  return MB_ENOREG;
}

/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegHoldingCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                             eMBRegisterMode eMode)
{
  return MB_ENOREG;
}

/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegInputCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
	return MB_ENOREG;
}
