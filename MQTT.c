/*
 * MQTT.c
 *
 * Created: 7/19/2020 11:16:21 AM
 *  Author: Khalid
 */ 

#include "MQTT.h"
const INT8U PrtocolName[]="MQTT";
void MQTT_Init(void){UART_Init(UART_0 , 9600);}
	
	INT8U RemLength=2+(2+strlen(topic))+1;
}
void MQTT_Publish(INT8U* topic , INT8U* pu8Msg , INT16U MsgSize, INT8U QoS )
{
	INT8U counter=0;
	INT8U RemLength=(2+strlen(topic))+MsgSize;
	if(QoS > 0 )
	{
		UART_SendByte(UART_0,0x32); /*PACKET TYPE*/
		RemLength=RemLength+2; /*if quality of serc. > 0 make sure packet idenfier */
	}
	else
	{
		UART_SendByte(UART_0,0x30); /*PACKET TYPE*/
	}
	UART_SendByte(UART_0,RemLength);
	Encode_UTF_Str(topic);
	if (QoS >0)
	{
		UART_SendByte(UART_0,(packetIdent>>8));/*packet identifier  MSB*/
	}
	
	/* Sending Bytes Cont. */
	for(counter=0; counter < MsgSize;counter++)
	{
		UART_SendByte(UART_0,pu8Msg[counter]);
	}
	
		
}
