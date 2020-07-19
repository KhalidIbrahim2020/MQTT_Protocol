/*
 * MQTT.h
 *
 * Created: 7/19/2020 11:16:05 AM
 *  Author: Khalid
 */ 


#ifndef MQTT_H_
#define MQTT_H_

#ifndef F_CPU
void Encode_UTF_Str(INT8U* str);
void MQTT_Subscribe(INT8U* topic);
void MQTT_Publish(INT8U* topic , INT8U* pu8Msg , INT16U MsgSize, INT8U QoS );


#endif /* MQTT_H_ */