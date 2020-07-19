/*
 * MQTT.h
 *
 * Created: 7/19/2020 11:16:05 AM
 *  Author: Khalid
 */ 


#ifndef MQTT_H_
#define MQTT_H_

#ifndef F_CPU#define F_CPU	8000000UL#endif#include	"avr/io.h"#include	"data_types.h"#include	"bit_handle.h"#include	"util/delay.h"#include    "string.h"#include	"UART.h"void MQTT_Init(void);void MQTT_Connect(INT8U* pu8ID);
void Encode_UTF_Str(INT8U* str);
void MQTT_Subscribe(INT8U* topic);
void MQTT_Publish(INT8U* topic , INT8U* pu8Msg , INT16U MsgSize, INT8U QoS );


#endif /* MQTT_H_ */