
/*
 * File      : ds18b20.c
 * 
 * This file is part of simulative onewire.
 * COPYRIGHT (C) 2018-
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-01-10     Acuity      first version.
 */
 
#include "onewire_hw.h"
#include "ds18b20.h"

static uint8_t ds18b20_start(void)
{   	
	char reg;
	ops_onewire_reset(&onewire1_dev); 	   

	reg = 0xcc;	/* ����ROM */
	ops_onewire_write(&onewire1_dev,&reg,1);
	reg = 0x44;	/* �¶�ת��ָ�� */
	ops_onewire_write(&onewire1_dev,&reg,1); 
	
	return 0;
}

/**
  * @brief  ��ȡ�¶�
  * @param  none
  * @retval �¶�ֵ��������
*/
float ds18b20_readtemp(void)
{
    uint8_t 	tl,th,sign;
	uint16_t	reg_temp;	
	char reg;
	float temp;
	
	ds18b20_start();													
	ops_onewire_reset(&onewire1_dev); 
	reg = 0xcc;
	ops_onewire_write(&onewire1_dev,&reg,1);	/* ����ROM */
	reg = 0xbe;
	ops_onewire_write(&onewire1_dev,&reg,1);	/* ��ȡRAM */
	ops_onewire_read(&onewire1_dev,&tl,1);		/* ��8λ���� */
	ops_onewire_read(&onewire1_dev,&th,1); 		/* ��8λ���� */
	//TL = 0x5e;
	//TH = 0xFf;
	if(th > 7)
	{/* - */
		th = ~th;
		tl = ~tl + 1; 
		sign = 0;											  
	}
	else 
	{/* + */
		sign = 1;			
	}		
	reg_temp = (th<<8) | tl;
	temp = reg_temp * 0.0625f; 
	if(sign)
	{
		return temp; 					 
	}
	else 
	{
		return -temp;   
	}
}
 
/**
  * @brief  ��Ψһ���к�
  * @param  rom �������кŻ���
  * @retval none
*/
void ds18b20_readrom(char *rom)
{
	uint8_t i;
	char reg;

	ops_onewire_reset(&onewire1_dev);
	reg = 0x33;
	ops_onewire_write(&onewire1_dev,&reg,1);
	for (i = 0;i < 8;i++)
	{
		ops_onewire_read(&onewire1_dev,&rom[i],1);		
	}	
}
