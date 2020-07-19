#include "MQTT.h"

int main(void) 
{
	MQTT_Init();
	MQTT_Connect("khg!22");
	_delay_ms(1000);
	MQTT_Subscribe("Dream");
	_delay_ms(1000);
	while (1)
		{
			MQTT_Publish("Dream","MsgTest",7,0); //(Channel , Msg, Size 'Byte', Qos Fire and forget)
			_delay_ms(5000)	;
		}
}