
/*
 * File      : onewire_bitops.c
 * 
 * This file is part of simulative onewire.
 * COPYRIGHT (C) 2018-
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-01-10     Acuity      first version.
 */
 
#include "onewire_bitops.h"

/**
  * @brief  �����߸�λʱ��
  * @param  onewire ���߽ṹ��ָ��
  * @retval �ɹ�����0
*/
uint8_t ops_onewire_reset(struct ops_onewire_dev *onewire)
{
	uint8_t ret = 0;

	onewire->set_sdo(1);
	onewire->delayus(50);
	onewire->set_sdo(0);
	onewire->delayus(500);
	onewire->set_sdo(1);
	onewire->delayus(40);
	ret = onewire->get_sdo();
	onewire->delayus(500);
	onewire->set_sdo(1);

	return ret;
}

/**
  * @brief  �����߶�ȡһ�ֽ�����
  * @param  onewire ���߽ṹ��ָ��
  * @retval ���ض�ȡ������
*/
static char ops_onewire_read_byte(struct ops_onewire_dev *onewire)
{
	char data = 0;
	uint8_t i;

	for(i=8;i>0;i--)
	{
		data >>= 1;
		onewire->set_sdo(0);
		onewire->delayus(5);
		onewire->set_sdo(1);
		onewire->delayus(5);
		if(onewire->get_sdo())
			data |= 0x80;
		else
			data &= 0x7f;
		onewire->delayus(65);
		onewire->set_sdo(1);
	}
	return data;
}

/**
  * @brief  ��ȡ���ֽ�
  * @param  onewire ���߽ṹ��ָ��
	* @param  buff ������ݻ���
	* @param  size ���ݴ�С
  * @retval ���ض�ȡ�������ݴ�С
*/
int ops_onewire_read(struct ops_onewire_dev *onewire,void *buff,int size)
{
	int i;
	char *p = (char*)buff;
	
	for(i=0;i<size;i++)
		p[i++]=ops_onewire_read_byte(onewire);
	return i;
}

/**
  * @brief  ������дһ�ֽ�
  * @param  onewire ���߽ṹ��ָ��
	* @param  data ��д����
  * @retval ���ض�ȡ������
*/
static int ops_onewire_write_byte(struct ops_onewire_dev *onewire,char data)
{
	uint8_t i;

	for(i=8;i>0;i--)
	{
		onewire->set_sdo(0);
		onewire->delayus(5);
		if(data&0x01)
			onewire->set_sdo(1);
		else
			onewire->set_sdo(0);
		onewire->delayus(65);
		onewire->set_sdo(1);
		onewire->delayus(2);
		data >>= 1;
	}
	return 0;
}

/**
  * @brief  д���ֽ�
  * @param  onewire ���߽ṹ��ָ��
	* @param  buff ��д���ݵ�ַ
	* @param  size ���ݴ�С
  * @retval д�����ݴ�С
*/
int ops_onewire_write(struct ops_onewire_dev *onewire,void *buff,int size)
{
	int i;
	char *p = (char*)buff;

	for(i=0;i<size;i++)
	{
		if(ops_onewire_write_byte(onewire,p[i]) != 0)
			break;
	}
	return i;
}
