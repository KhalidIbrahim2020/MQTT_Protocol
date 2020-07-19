/*
 * MQTT.c
 *
 * Created: 7/19/2020 11:16:21 AM
 *  Author: Khalid
 */ 

#include "MQTT.h"
const INT8U PrtocolName[]="MQTT";
void MQTT_Init(void){UART_Init(UART_0 , 9600);}INT16U packetIdent=1;void MQTT_Connect(INT8U* pu8ID)	{	INT8U RemLength=(2+strlen(PrtocolName))+1+1+2+(2+strlen(pu8ID));	UART_SendByte(UART_0,0X10);     /*PACKET TYPE*/	UART_SendByte(UART_0,RemLength); /*Remaining Length*/	Encode_UTF_Str(PrtocolName);    /*Protocol Name*/	UART_SendByte(UART_0,0X04);     /*Protocol Level indicate Protocol version*/	UART_SendByte(UART_0,0X02);     /*Flags*/	UART_SendByte(UART_0,0XFF);     /*KAT MSB*/	UART_SendByte(UART_0,0XFF);     /*KAT LSB*/	Encode_UTF_Str(pu8ID);          /*Client ID*/		}void Encode_UTF_Str(INT8U* str)	{		UART_SendByte(UART_0,0X00);        /*Length high Byte*/		UART_SendByte(UART_0,strlen(str)); /*Length Low  Byte */		Uart_SendStr(UART_0,str) ;	}void MQTT_Subscribe(INT8U* topic){
	
	INT8U RemLength=2+(2+strlen(topic))+1;	UART_SendByte(UART_0,0X82);             /*PACKET TYPE*/	UART_SendByte(UART_0,RemLength);        /*Remaining Length*/	UART_SendByte(UART_0,(packetIdent>>8)); /*packet identifier Shifting to High Byte   MSB*/	UART_SendByte(UART_0,packetIdent);      /*packet identifier LSB CASTINT 2nd Byte because its 2 byte*/	packetIdent++;	Encode_UTF_Str(topic);                  /*TOPIC NAME*/	UART_SendByte(UART_0,0X00);             /*QoS Req. */	
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
		UART_SendByte(UART_0,(packetIdent>>8));/*packet identifier  MSB*/		UART_SendByte(UART_0,packetIdent);/*packet identifier MSB*/		packetIdent++;
	}
	
	/* Sending Bytes Cont. */
	for(counter=0; counter < MsgSize;counter++)
	{
		UART_SendByte(UART_0,pu8Msg[counter]);
	}
	
		
}

