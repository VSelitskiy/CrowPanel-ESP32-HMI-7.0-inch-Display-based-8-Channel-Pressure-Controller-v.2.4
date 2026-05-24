#pragma once

#include <Arduino.h>

void PublishMqtt(String payload, const char* topic);
void formatTankStateTopic(char* buffer, uint8_t tankNumber);
void updateMQTTTopics();
void updateMQTTServer();
void SuscribeMqtt();
void onMqttConnect(bool sessionPresent);
void onMqttDisconnect(bool sessionPresent);
void onMqttMessage(char *topic, char *payload, int retain, int qos, bool dup);
void onMqttSubscribe(uint16_t packetId);
void onMqttPublish(uint16_t packetId);
