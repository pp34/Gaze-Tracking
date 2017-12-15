#include "connect.h"

char CMD_FLAG=0;
uint8_t pp[2]={0,0};
uint8_t command[2]={0,0};

uint8_t _A1[CMDLEN] = "A1";
uint8_t _A2[CMDLEN] = "A2";
uint8_t _A3[CMDLEN] = "A3";
uint8_t _A4[CMDLEN] = "A4";
	 
uint8_t _B1[CMDLEN] = "B1";
uint8_t _B2[CMDLEN] = "B2";
uint8_t _B3[CMDLEN] = "B3";
uint8_t _B4[CMDLEN] = "B4";
uint8_t _B5[CMDLEN] = "B5";
uint8_t _B6[CMDLEN] = "B6";
uint8_t _B7[CMDLEN] = "B7";
uint8_t _B8[CMDLEN] = "B8";	 

uint8_t PP[2] = "PP";

uint8_t PPstrAnswer[]="\nPP String GET!\r";
uint8_t PPstrError[]="\nError: PP String\n";

uint8_t CMDstrAnswer[]="\nCMD GET:\t";
uint8_t CMDstrError[]="\nError: CMD String\n";

uint8_t	_allsidesoff[] = "Turn Off all LEDs\n";
uint8_t	_allsideson[] = "Turn On all LEDs\n";

uint8_t	_insideon[] = "Turn On inside LEDs\n";
uint8_t	_outsideon[] = "Turn On outside LEDs\n";

uint8_t	D4on[] = "Turn On D4\n";
uint8_t	D5on[] = "Turn On D5\n";
uint8_t	D17on[] = "Turn On D17\n";
uint8_t	D18on[] = "Turn On D18\n";

uint8_t	D39on[] = "Turn On D39\n";
uint8_t	D40on[] = "Turn On D40\n";
uint8_t	D61on[] = "Turn On D61\n";
uint8_t	D62on[] = "Turn On D62\n";

void Ack(const uint8_t ppstr[], const uint8_t cmdstr[]){
	
	int tmp = 0;
//	uint8_t *tmpbuf;
	tmp = pp_match(ppstr, PP);
	if(tmp == 0)	
		HAL_UART_Transmit(&huart1, PPstrError, sizeof(PPstrError) / sizeof(PPstrError[0]), 0xff);
	else if(tmp == 1){
		HAL_UART_Transmit(&huart1, PPstrAnswer, sizeof(PPstrAnswer) / sizeof(PPstrAnswer[0]), 0xff);
	
		cmd_match(cmdstr);
		switch(CMD_FLAG){
			case 0:	
				HAL_UART_Transmit(&huart1, CMDstrError, sizeof(CMDstrError) / sizeof(CMDstrError[0]), 0xff);
				break;
			case 1:		// ALL_OFF
				Pastcommand(_all_off[0], _all_off[1], 0);
				SendtoNO1(pastcmd[0]);
				SendtoNO2(pastcmd[1]);
				//tmpbuf=pp_numcat(CMDstrAnswer, _allsidesoff);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]),0xff);
				HAL_UART_Transmit(&huart1, _allsidesoff, sizeof(_allsidesoff) / sizeof(_allsidesoff[0]),0xff);
				Led1_Off;
				Led2_Off;
				break;
			case 2:		// ALL_ON
				Pastcommand(_all_on[0], _all_on[1], 0);
				SendtoNO1(pastcmd[0]);
				SendtoNO2(pastcmd[1]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, _allsideson, sizeof(_allsideson) / sizeof(_allsideson[0]), 0xff);
				Led1_On;
				Led2_On;
				break;
			case 3:		// IN_ON
				Pastcommand(_in_on[0], _in_on[1], 1);
				SendtoNO1(pastcmd[0]);
				SendtoNO2(pastcmd[1]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, _insideon, sizeof(_insideon) / sizeof(_insideon[0]), 0xff);
				Led1_On;
				break;
			case 4:		// OUT_ON
				Pastcommand(_out_on[0], _out_on[1], 1);
				SendtoNO1(pastcmd[0]);
				SendtoNO2(pastcmd[1]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, _outsideon, sizeof(_outsideon) / sizeof(_outsideon[0]), 0xff);
				Led2_On;
				break;
			case 5:		// PIN1_ON
				Pastcommand(_pin1, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D4on, sizeof(D4on) / sizeof(D4on[0]), 0xff);
				break;
			case 6:		// PIN2_ON
				Pastcommand(_pin2, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D5on, sizeof(D5on) / sizeof(D5on[0]), 0xff);
				break;
			case 7:		// PIN3_ON
				Pastcommand(_pin3, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D17on, sizeof(D17on) / sizeof(D17on[0]), 0xff);
				break;
			case 8:		// PIN4_ON
				Pastcommand(_pin4, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D18on, sizeof(D18on) / sizeof(D18on[0]), 0xff);
				break;
			case 9:		// PIN5_ON
				Pastcommand(_pin5, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D39on, sizeof(D39on) / sizeof(D39on[0]), 0xff);
				break;
			case 10:	// PIN6_ON
				Pastcommand(_pin6, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D40on, sizeof(D40on) / sizeof(D40on[0]), 0xff);
				break;
			case 11:	// PIN7_ON
				Pastcommand(_pin7, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D61on, sizeof(D61on) / sizeof(D61on[0]), 0xff);
				break;
			case 12:	// PIN8_ON
				Pastcommand(_pin8, 0x00, 1);
				SendtoNO1(pastcmd[0]);
				HAL_UART_Transmit(&huart1, CMDstrAnswer, sizeof(CMDstrAnswer) / sizeof(CMDstrAnswer[0]), 0xff);
				HAL_UART_Transmit(&huart1, D62on, sizeof(D62on) / sizeof(D62on[0]), 0xff);
				break;
			default: 
				HAL_UART_Transmit(&huart1, CMDstrError, sizeof(CMDstrError) / sizeof(CMDstrError[0]), 0xff);
				break;
		}
	}else;
	CMD_FLAG = 0;
}



void data_transfer(void){
	
	char i=0;
	TX_FLAG = 0;
	
	//	从接收buf中识别指令，并返回应答
	for(i=0; i<2; i++){
		pp[i] = usart1_idle.rxbuf[i];
	}
	for(i=0; i<2; i++){
		command[i] = usart1_idle.rxbuf[i+2];
	}
	for(i=0; i<4; i++){
		usart1_idle.rxbuf[i] = 0;
	}
	//	判断指令
	Ack(pp, command);
}
