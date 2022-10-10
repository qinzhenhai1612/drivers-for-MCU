#ifndef 	_LM75A_H_
#define		_LM75A_H_

#define 	LM75A_ADDR		0X48   	//i2c slave address
#define		REG_TEMP		0X00	//�¶ȣ�ֻ��
#define		REG_CONF		0X01	//����
#define		REG_THYST		0X02	//�ͺ����
#define		REG_TOS			0X03	//���¹رռĴ���

extern void lm75a_init(void);
extern float lm75a_get_temp(void);

#endif
