
#include "main.h"
#include "st25dv.h"

static const  unsigned char aucCRCHi[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1,
    0x81, 0x40, 0x01,
    0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
    0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80,
    0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01,
    0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
    0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81,
    0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1,
    0x81, 0x40, 0x01,
    0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01,
    0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01,
    0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
    0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81,
    0x40
};

static const  unsigned char aucCRCLo[] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7,
    0x05, 0xC5, 0xC4,
    0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB,
    0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE,
    0xDF, 0x1F, 0xDD,
    0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2,
    0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32,
    0x36, 0xF6, 0xF7,
    0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E,
    0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B,
    0x2A, 0xEA, 0xEE,
    0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27,
    0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1,
    0x63, 0xA3, 0xA2,
    0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD,
    0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8,
    0xB9, 0x79, 0xBB,
    0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4,
    0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0,
    0x50, 0x90, 0x91,
    0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94,
    0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59,
    0x58, 0x98, 0x88,
    0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D,
    0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83,
    0x41, 0x81, 0x80,
    0x40
};



#define AdminId_Address		 	0x8007000
#define AdminPass_Address		0x8007008
#define Keys_Address		 	0x8007020

#define Funtion_NewAdmin  		0x01
#define Funtion_AdminLogin		0x02
#define Funtion_SoftReset		0x03
#define Funtion_LogEnable		0x04
#define Funtion_NewKey			0x10
#define Funtion_DeleteKey		0x11
#define Funtion_OpenDoor		0x12


#define OK					0x80
#define	ADMIN_ALREADY		0x01
#define KEY_ALREADY			0x02
#define WRONG_ID			0x03
#define WRONG_Pass			0x04
#define WRONG_CRC			0x05
#define KEY_NOT_EXIST		0x06



#define EMPTY_AdminID			0xFFFFFFFFFFFFFFFF
#define EMPTY_AdminPass			0xFFFFFFFFFFFFFFFF
#define EMPTY_Key				0xFFFFFFFF

#define DOORDELAY				500


uint32_t Timer=0,Log_Timer=0;


int res=-1 ;
uint8_t buffer[30],uid[12];
uint8_t EMPTY_FRAME[30]={0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t flag=0;
uint32_t Keys[256];
uint64_t Admin_Id,Admin_Pass;

ST25DV_PASSWD pass;
ST25DV_MB_CTRL_DYN_STATUS status;


IWDG_HandleTypeDef hiwdg;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_IWDG_Init(void);

HAL_StatusTypeDef Flash_write32(uint32_t Address,uint32_t Data);
HAL_StatusTypeDef Flash_write64(uint32_t Address,uint64_t Data);
HAL_StatusTypeDef Flash_Erase(uint32_t PageAddress);
uint32_t Flash_Read32(uint32_t Address);
uint64_t Flash_Read64(uint32_t Address);
uint16_t CRC16( unsigned char * pucFrame, unsigned int usLen);
uint32_t Make32(uint8_t* Array, uint8_t index);
uint64_t Make64(uint8_t* Array, uint8_t index);

void Read_Data();
HAL_StatusTypeDef Write_Data();

void NewAdmin();
void AdminLogin();
void SoftReset();
void NewKey();
void DeleteKey();
void OpenDoor();
void Response(uint8_t result);
void Door_Log();
void Admin_Log(uint8_t index);
void Reset_Memory();
void GetUID();
void NFCTAG_Init();




int main(void)
{
	pass.LsbPasswd=0;
	pass.MsbPasswd=0;

	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_IWDG_Init();
	res=CUSTOM_NFCTAG_Init(0);
	HAL_IWDG_Refresh(&hiwdg);
	HAL_Delay(10);
	NFCTAG_Init();
	GetUID();

	Read_Data();


	Timer=HAL_GetTick();
	while (1)
	{

		if((HAL_GetTick()-Timer) >6000)
		{
			HAL_IWDG_Refresh(&hiwdg);
			Timer=HAL_GetTick();
		}


		if(flag==1)
		{
			HAL_IWDG_Refresh(&hiwdg);
			Timer=HAL_GetTick();
			switch(buffer[0])
			{
				case Funtion_NewAdmin:
				  NewAdmin();
				  break;

				case Funtion_AdminLogin:
				  AdminLogin();
				  break;

				case Funtion_SoftReset:
				  SoftReset();
				  break;

				case Funtion_NewKey:
				  NewKey();
				  break;

				case Funtion_DeleteKey:
				  DeleteKey();
				  break;

				case Funtion_OpenDoor:
				  OpenDoor();
				  break;
			}
			flag=0;
		}
	}
}


void NFCTAG_Init()
{
	ST25DV_EN_STATUS md;
	buffer[0]=0x90;
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteRegister(0, &buffer, 0, 1);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_ENABLE);
	HAL_Delay(10);
	CUSTOM_NFCTAG_SetMBEN_Dyn(0);
	//CUSTOM_NFCTAG_ReadMBMode(0,md);
	//res=CUSTOM_NFCTAG_WriteMBWDG(4);
	HAL_Delay(100);

}


HAL_StatusTypeDef Flash_write32(uint32_t Address,uint32_t Data)
{

	HAL_StatusTypeDef res=HAL_ERROR;

	if(HAL_FLASH_Unlock()==HAL_OK)
	{
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
		res= HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Address,Data);
		HAL_FLASH_Lock();
	}

	return res;
}

HAL_StatusTypeDef Flash_write64(uint32_t Address,uint64_t Data)
{
	HAL_StatusTypeDef res=HAL_ERROR;

	if(HAL_FLASH_Unlock()==HAL_OK)
	{
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
		res= HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD,Address,Data);
		HAL_FLASH_Lock();
	}

	return res;
}

HAL_StatusTypeDef Flash_Erase(uint32_t PageAddress)
{
	FLASH_EraseInitTypeDef pEraseInit;
	uint32_t PageError=0;
	HAL_StatusTypeDef res=HAL_ERROR;

	if(HAL_FLASH_Unlock()==HAL_OK)
	{

	  pEraseInit.NbPages=1;
	  pEraseInit.PageAddress=PageAddress;
	  pEraseInit.TypeErase=FLASH_TYPEERASE_PAGES;
	  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);

	  res=HAL_FLASHEx_Erase(&pEraseInit,&PageError);

	  HAL_FLASH_Lock();
	}

	return res;
}

uint32_t Flash_Read32(uint32_t Address)
{
	return *((uint32_t*)Address);

}

uint64_t Flash_Read64(uint32_t Address)
{
	return *((uint64_t*)Address);
}

uint16_t CRC16( unsigned char * pucFrame, unsigned int usLen)
{
	uint8_t           ucCRCHi = 0xFF;
	uint8_t           ucCRCLo = 0xFF;
    int             iIndex;

    while( usLen-- )
    {
        iIndex = ucCRCLo ^ *( pucFrame++ );
        ucCRCLo = ucCRCHi ^  aucCRCHi[iIndex];
        ucCRCHi = aucCRCLo[iIndex];
    }

    return (uint16_t) (ucCRCHi) << 8 | (ucCRCLo);

}

uint32_t Make32(uint8_t* Array, uint8_t index)
{
	uint32_t tmp=(Array[index+3])  |
			(Array[index+2]) << 8  |
			(Array[index+1]) << 16 |
			(Array[index]) << 24 ;

	return tmp;
}
uint64_t Make64(uint8_t* Array, uint8_t index)
{
	uint64_t tmpL=0,tmpH=0;
	tmpL=	((Array[index+7]))  |
			((Array[index+6]) << 8)  |
			((Array[index+5]) << 16) |
			((Array[index+4]) << 24);

	tmpL=tmpL & 0xFFFFFFFF;

	tmpH= 	((Array[index+3])) 		  |
			((Array[index+2]) << 8)   |
			((Array[index+1]) << 16)  |
			((Array[index])   << 24)  ;

	tmpH=tmpH << 16;
	tmpH=tmpH << 16;


	return tmpL | tmpH;
}



void NewAdmin()
{
	uint16_t CRC_t=0;
	CRC_t=(uint16_t) (buffer[17]) << 8 | (buffer[18]);

	if( CRC16(buffer,17)==CRC_t )
	{
		if(Admin_Id==EMPTY_AdminID)
		{
			Admin_Id = Make64(buffer,1);
			Admin_Pass = Make64(buffer,9);
			Response(OK);
			HAL_Delay(1000);
			Write_Data();
		}
		else Response(ADMIN_ALREADY);
	}
	else Response(WRONG_CRC);

}


void AdminLogin()
{
	uint16_t CRC_t=0,crc=0;
	CRC_t=(uint16_t) (buffer[20]) << 8 | (buffer[21]);
	crc=CRC16(buffer,20);
	if( crc==CRC_t )
	{
		if(Admin_Id == Make64(buffer,1))
		{
			if(Admin_Pass == Make64(buffer,9))
			{
				Response(OK);
				HAL_Delay(1000);
				Admin_Log(17);
			}
			else
				Response(WRONG_Pass);
		}
		else Response(WRONG_ID);
	}
	else Response(WRONG_CRC);
}



void SoftReset()
{
	uint16_t CRC_t=0;

	CRC_t=(uint16_t) (buffer[17]) << 8 | (buffer[18]);

	if( CRC16(buffer,17)==CRC_t )
	{
		if(Admin_Id == Make64(buffer,1))
		{
			if(Admin_Pass == Make64(buffer,9))
			{
				Admin_Id=EMPTY_AdminID;
				Admin_Pass=EMPTY_AdminPass;
				for(int i=0; i<256; i++) Keys[i]=EMPTY_Key;
				Response(OK);
				HAL_Delay(1000);
				Reset_Memory();
				Write_Data();
			}
			else Response(WRONG_Pass);
		}
		else Response(WRONG_ID);
	}
	else Response(WRONG_CRC);
}




void NewKey()
{
	uint16_t CRC_t=0,crc=0;
	CRC_t=(uint16_t) (buffer[22]) << 8 | (buffer[23]);
	crc=CRC16(buffer,22);

	if( crc==CRC_t )
	{
		if(Admin_Id == Make64(buffer,1))
		{
			if(Admin_Pass == Make64(buffer,9))
			{
				if(Keys[buffer[17]] == EMPTY_Key)
				{
					Keys[buffer[17]]=Make32(buffer, 18);
					Response(OK);
					HAL_Delay(1000);
					Write_Data();
				}
				else Response(KEY_ALREADY);
			}
			else Response(WRONG_Pass);
		}
		else Response(WRONG_ID);
	}
	else Response(WRONG_CRC);
}


void DeleteKey()
{
	uint16_t CRC_t=0,crc=0;
	CRC_t=(uint16_t) (buffer[18]) << 8 | (buffer[19]);
	crc=CRC16(buffer,18);

	if( crc==CRC_t )
	{
		if(Admin_Id == Make64(buffer,1))
		{
			if(Admin_Pass == Make64(buffer,9))
			{
				if(Keys[buffer[17]] != EMPTY_Key)
				{
					Keys[buffer[17]]=EMPTY_Key;
					Response(OK);
					HAL_Delay(1000);
					Write_Data();
				}
				else Response(KEY_NOT_EXIST);
			}
			else Response(WRONG_Pass);
		}
		else Response(WRONG_ID);
	}
	else Response(WRONG_CRC);
}


void OpenDoor()
{
	uint16_t CRC_t=0,crc=0;
	CRC_t=(uint16_t) (buffer[9]) << 8 | (buffer[10]);
	crc=CRC16(buffer,9);

	if( crc==CRC_t )
	{
		if(Keys[buffer[5]] == Make32(buffer,1))
		{
			HAL_GPIO_WritePin(GPIOA, Relay_Pin, GPIO_PIN_SET);
			Response(OK);
			HAL_Delay(DOORDELAY);
			HAL_GPIO_WritePin(GPIOA, Relay_Pin, GPIO_PIN_RESET);
			Door_Log();
		}
		else Response(WRONG_Pass);
	}
	else Response(WRONG_CRC);
}




void Response(uint8_t result)
{
	uint8_t frame[16];
	uint16_t crc=0;
	frame[0]=0xF0;
	frame[1]=result;
	for(int i=0; i<12 ; i++) frame[i+2]=uid[i];
	crc=CRC16(frame, 14);
	frame[14]=(crc >> 8) & 0xFF;
	frame[15]=(crc & 0xFF);
	CUSTOM_NFCTAG_WriteMailboxData(0, frame, 16);
}

void Door_Log()
{
	uint8_t frame[4],add=0;
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(5);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_DISABLE);
	HAL_Delay(10);
	CUSTOM_NFCTAG_ReadData(0, frame, 400, 1);
	add=frame[0];
	if(add>62) add=0;
	else add+=1;
	for(int i=0;i<4;i++) frame[i]=buffer[5+i];
	CUSTOM_NFCTAG_WriteData(0, frame, (add*4), 4);
	frame[0]=add;
	CUSTOM_NFCTAG_WriteData(0, frame, 400, 1);
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_ENABLE);
	HAL_Delay(5);
	CUSTOM_NFCTAG_SetMBEN_Dyn(0);
}

void Admin_Log(uint8_t index)
{
	uint8_t frame[4],add=0;
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(5);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_DISABLE);
	HAL_Delay(10);
	CUSTOM_NFCTAG_ReadData(0, frame, 401, 1);
	add=frame[0];
	if(add>3) add=0;
	else add+=1;
	for(int i=0;i<3;i++) frame[i+1]=buffer[index+i];
	frame[0]=buffer[0];
	res=CUSTOM_NFCTAG_WriteData(0, frame,(add*4)+256, 4);
	frame[0]=add;
	CUSTOM_NFCTAG_WriteData(0, frame, 401, 1);
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_ENABLE);
	HAL_Delay(5);
	CUSTOM_NFCTAG_SetMBEN_Dyn(0);
}

void Reset_Memory()
{
	uint8_t mem[140];
	for(int i=0;i<140;i++) mem[i]=0;
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(5);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_DISABLE);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteData(0, mem,0, 140);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteData(0, mem,140, 140);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_WriteData(0, mem,400, 4);
	HAL_Delay(10);
	res=CUSTOM_NFCTAG_PresentI2CPassword(0, pass);
	HAL_Delay(5);
	res=CUSTOM_NFCTAG_WriteMBMode(0,ST25DV_ENABLE);
	HAL_Delay(5);
	CUSTOM_NFCTAG_SetMBEN_Dyn(0);
}

void GetUID()
{
	uint32_t tmp;
	tmp=HAL_GetUIDw0();
	uid[0]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[1]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[2]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[3]=tmp & 0xFF;

	tmp=HAL_GetUIDw1();
	uid[4]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[5]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[6]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[7]=tmp & 0xFF;

	tmp=HAL_GetUIDw2();
	uid[8]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[9]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[10]=tmp & 0xFF;
	tmp=tmp >> 8;
	uid[11]=tmp & 0xFF;

}


void Read_Data()
{
	Admin_Id=Flash_Read64(AdminId_Address);
	Admin_Pass=Flash_Read64(AdminPass_Address);
	for(int i=0;i<256;i++)
	{
		Keys[i]=Flash_Read32(Keys_Address+i*4);
	}
}

HAL_StatusTypeDef Write_Data()
{
	if(Flash_Erase(AdminId_Address)==HAL_OK)
	{
		Flash_write64(AdminId_Address, Admin_Id);
		Flash_write64(AdminPass_Address, Admin_Pass);
		for(int i=0;i<256;i++)
		{
			Flash_write32( (Keys_Address+i*4) , Keys[i]);
		}
	}

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */

  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_64;
  hiwdg.Init.Window = 4095;
  hiwdg.Init.Reload = 4095;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */

  /* USER CODE END IWDG_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Relay_Pin|LPD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Relay_Pin LPD_Pin */
  GPIO_InitStruct.Pin = Relay_Pin|LPD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : NFC_GPO_Pin */
  GPIO_InitStruct.Pin = NFC_GPO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(NFC_GPO_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
