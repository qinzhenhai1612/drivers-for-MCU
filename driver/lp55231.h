#ifndef _LP55231_H_
#define _LP55231_H_
#include <stm32f10x.h>

#define	LP55231_SLAVE0	0x32
#define	LP55231_SLAVE1	0x33
#define	LP55231_SLAVE2	0x34
#define	LP55231_SLAVE3	0x35				//ͬһi2c�����������4��lp55231

//�Ĵ���
#define 	REG_CNTRL1			0X00
#define		REG_CNTRL2			0X01
#define		REG_OUT_DIM_MSB		0X02		//ʹ�ܵ���������D9,�Ĵ���ֵxxxxxxx0
#define		REG_OUT_DIM_LSB		0X03		//ʹ�ܵ���������D1����D7
#define		REG_OUT_EN_MSB		0X04		//����/�ر����D9���Ĵ���xxxxxxx1
#define		REG_OUT_EN_LSB		0X05		//����/�ر����D1-D7

#define		REG_D1_CONTROL		0X06
#define		REG_D2_CONTROL		0X07
#define		REG_D3_CONTROL		0X08
#define		REG_D4_CONTROL		0X09
#define		REG_D5_CONTROL		0X0A
#define		REG_D6_CONTROL		0X0B
#define		REG_D7_CONTROL		0X0C
#define		REG_D8_CONTROL		0X0D
#define		REG_D9_CONTROL		0X0E	
//0X0F����0X15 reserved
#define		REG_D1_PWM			0X16
#define		REG_D2_PWM			0X17
#define		REG_D3_PWM			0X18
#define		REG_D4_PWM			0X19
#define		REG_D5_PWM			0X1A
#define		REG_D6_PWM			0X1B
#define		REG_D7_PWM			0X1C
#define		REG_D8_PWM			0X1D
#define		REG_D9_PWM			0X1E
//0X1F����0X25 reserved
#define		REG_D1_CURRENT		0X26		//�������ƣ�Ĭ��17.5ma
#define		REG_D2_CURRENT		0X27
#define		REG_D3_CURRENT		0X28
#define		REG_D4_CURRENT		0X29
#define		REG_D5_CURRENT		0X2A
#define		REG_D6_CURRENT		0X2B
#define		REG_D7_CURRENT		0X2C
#define		REG_D8_CURRENT		0X2D
#define		REG_D9_CURRENT		0X2E
//0X2F����0X35 reserved
#define		REG_MISC			0X36
#define		REG_ENGINE1_PC		0X37
#define		REG_ENGINE2_PC		0X38
#define		REG_ENGINE3_PC		0X39
#define		REG_STATUS			0X3A		//״̬λ
#define		REG_INT_GPPO		0X3B		//����gpio����
#define		REG_VARIABLE		0X3C
#define		REG_RESET			0X3D		//��λic
#define		REG_TEMP_CONTROL	0X3E		//�¶�ת���趨
#define		REG_READ_TEMP		0X3F		//��ȡ�¶�
#define		REG_WRITE_TEMP		0X3F		
#define		REG_LED_TEST_CON	0X41
#define		REG_LED_TEST_ADC	0X42
//0X43 0X44 reserved
#define		REG_ENGINE1_VALUE	0X45
#define		REG_ENGINE2_VALUE	0X46
#define		REG_ENGINE3_VALUE	0X47
#define		REG_MASTER_FADER1	0X48
#define		REG_MASTER_FADER2	0X49
#define		REG_MASTER_FADER3	0X4A
//0X4B	reserved
#define		REG_ENG1_START_A	0X4C
#define		REG_ENG2_START_A	0X4D
#define		REG_ENG3_START_A	0X4E
#define		REG_MEM_PAGE_SEL	0X4F

/* Bit description in registers */
#define 	LP55231_ENABLE			0x40
#define 	LP55231_AUTO_INC		0x40
#define 	LP55231_PWR_SAVE		0x20
#define 	LP55231_PWM_PWR_SAVE	0x04
#define 	LP55231_CP_AUTO			0x18
#define 	LP55231_AUTO_CLK		0x02

/*�ⲿ����*/
extern void lp55231_init(void);
extern void lp55231_set_led(u8 lp55231_no,u16 led_bit,u8 led_state);
extern void lp55231_set_led_pwm(u8 lp55231_no,u8 led_no,u8 led_pwm);
extern void lp55231_set_led_current(u8 lp55231_no,u8 led_no,u8 led_current);
extern void light_control(u8 led_no,u8 bright);

#endif
