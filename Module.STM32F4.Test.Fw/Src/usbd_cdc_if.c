#include "usbd_cdc_if.h"
#define APP_RX_DATA_SIZE  4
#define APP_TX_DATA_SIZE  4

uint8_t UserRxBufferHS[APP_RX_DATA_SIZE];

uint8_t UserTxBufferHS[APP_TX_DATA_SIZE];
extern USBD_HandleTypeDef hUsbDeviceHS;  
static int8_t CDC_Init_HS     (void);
static int8_t CDC_DeInit_HS   (void);
static int8_t CDC_Control_HS  (uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t CDC_Receive_HS  (uint8_t* pbuf, uint32_t *Len);

USBD_CDC_ItfTypeDef USBD_Interface_fops_HS = 
{
  CDC_Init_HS,
  CDC_DeInit_HS,
  CDC_Control_HS,  
  CDC_Receive_HS
};


static int8_t CDC_Init_HS(void)
{ 
  USBD_CDC_SetTxBuffer(&hUsbDeviceHS, UserTxBufferHS, 0);
  USBD_CDC_SetRxBuffer(&hUsbDeviceHS, UserRxBufferHS);
  return (USBD_OK);
}

static int8_t CDC_DeInit_HS(void)
{
  return (USBD_OK);
}

static int8_t CDC_Control_HS  (uint8_t cmd, uint8_t* pbuf, uint16_t length)
{ 
  /* USER CODE BEGIN 10 */
  switch (cmd)
  {
  case CDC_SEND_ENCAPSULATED_COMMAND:
 
    break;

  case CDC_GET_ENCAPSULATED_RESPONSE:
 
    break;

  case CDC_SET_COMM_FEATURE:
 
    break;

  case CDC_GET_COMM_FEATURE:

    break;

  case CDC_CLEAR_COMM_FEATURE:

    break;
  case CDC_SET_LINE_CODING:   
	
    break;

  case CDC_GET_LINE_CODING:     

    break;

  case CDC_SET_CONTROL_LINE_STATE:

    break;

  case CDC_SEND_BREAK:
 
    break;    
    
  default:
    break;
  }

  return (USBD_OK);
  /* USER CODE END 10 */
}

static int8_t CDC_Receive_HS (uint8_t* Buf, uint32_t *Len)
{
	if(Buf[0]=='1'){
			uint8_t *data;
			data[0]='A';
			CDC_Transmit_HS((uint8_t *)data, 1);
	}
	if(Buf[0]=='2'){
			for(int i=0;i<6;i++){
					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);
					HAL_Delay(250);
					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_11);
					HAL_Delay(250);
					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_12);
					HAL_Delay(250);
					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
					HAL_Delay(250);
			}
	}
	if(Buf[0]=='3'){
			
	}
	if(Buf[0]=='4'){
		
	}
	if(Buf[0]=='5'){
		
	}
					
  USBD_CDC_SetRxBuffer(&hUsbDeviceHS, &Buf[0]);
  USBD_CDC_ReceivePacket(&hUsbDeviceHS);
  return (USBD_OK); 
}

uint8_t CDC_Transmit_HS(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceHS.pClassData;
  if (hcdc->TxState != 0){
    return USBD_BUSY;
  }
  USBD_CDC_SetTxBuffer(&hUsbDeviceHS, Buf, Len);
  result = USBD_CDC_TransmitPacket(&hUsbDeviceHS);
  return result;
}



