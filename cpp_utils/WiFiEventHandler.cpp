/*
 * WiFiEventHandler.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: kolban
 */

#include <iostream>
#include "esp_event_cxx.hpp"
#include "esp_event.h"
#include "esp_err.h"
#include "WiFiEventHandler.h"
#include <esp_log.h>
#include "sdkconfig.h"

static const char* LOG_TAG = "WiFiEventHandler";

void WiFiEventHandler::callback_debug(const ESPEvent &event, void *data) {
	cout << "received event: " << event.base << "/" << event.id;
	if (data) {
		cout << "; data: " << *(static_cast<int*>(data));
	}
	cout << endl;
}

void WiFiEventHandler::callback_WIFI_EVENT_AP_START(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	this->apStart();
}

void WiFiEventHandler::callback_WIFI_EVENT_AP_STOP(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	this->apStop();
}

void WiFiEventHandler::callback_WIFI_EVENT_AP_STACONNECTED(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	wifi_event_ap_staconnected_t* event_data = (wifi_event_ap_staconnected_t*) data;
	this->apStaConnected(event_data);
}

void WiFiEventHandler::callback_WIFI_EVENT_AP_STADISCONNECTED(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	wifi_event_ap_stadisconnected_t* event_data = (wifi_event_ap_stadisconnected_t*) data;
	this->apStaDisconnected(event_data);
}

void WiFiEventHandler::callback_WIFI_EVENT_SCAN_DONE(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	wifi_event_sta_scan_done_t* event_data = (wifi_event_sta_scan_done_t*) data;
	this->staScanDone(event_data);
}

void WiFiEventHandler::callback_WIFI_EVENT_STA_AUTHMODE_CHANGE(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	wifi_event_sta_authmode_change_t* event_data = (wifi_event_sta_authmode_change_t*) data;
	this->staAuthChange(event_data);
}

void WiFiEventHandler::callback_WIFI_EVENT_STA_CONNECTED(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	wifi_event_sta_connected_t* event_data = (wifi_event_sta_connected_t*) data;
	this->staConnected(event_data);
}

void WiFiEventHandler::callback_WIFI_EVENT_STA_DISCONNECTED(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	wifi_event_sta_disconnected_t* event_data = (wifi_event_sta_disconnected_t*) data;
	this->staDisconnected(event_data);
}

void WiFiEventHandler::callback_IP_EVENT_STA_GOT_IP(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
    ip_event_got_ip_t* event_data = (ip_event_got_ip_t*) data;
	this->staGotIp(event_data);
}

void WiFiEventHandler::callback_WIFI_EVENT_STA_START(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	this->staStart();
}

void WiFiEventHandler::callback_WIFI_EVENT_STA_STOP(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	this->staStop();
}

void WiFiEventHandler::callback_WIFI_EVENT_WIFI_READY(const ESPEvent &event, void *data)
{
	callback_debug(event, data);
	this->wifiReady();
}




/**
 * @brief Constructor
 */
WiFiEventHandler::WiFiEventHandler() {
	m_nextHandler = nullptr;
} // WiFiEventHandler


/**
 * @brief Handle the Station Got IP event.
 * Handle having received/assigned an IP address when we are a station.
 * @param [in] event_sta_got_ip The Station Got IP event.
 */
void WiFiEventHandler::staGotIp(ip_event_got_ip_t* info) {
	ESP_LOGD(LOG_TAG, "default staGotIp");
} // staGotIp


/**
 * @brief Handle the Access Point started event.
 * Handle an indication that the ESP32 has started being an access point.
 */
void WiFiEventHandler::apStart() {
	ESP_LOGD(LOG_TAG, "default apStart");
} // apStart


/**
 * @brief Handle the Access Point stop event.
 * Handle an indication that the ESP32 has stopped being an access point.
 */
void WiFiEventHandler::apStop() {
	ESP_LOGD(LOG_TAG, "default apStop");
} // apStop


void WiFiEventHandler::wifiReady() {
	ESP_LOGD(LOG_TAG, "default wifiReady");
} // wifiReady


void WiFiEventHandler::staStart() {
	ESP_LOGD(LOG_TAG, "default staStart");
} // staStart


void WiFiEventHandler::staStop() {
	ESP_LOGD(LOG_TAG, "default staStop");
} // staStop


/**
 * @brief Handle the Station Connected event.
 * Handle having connected to remote AP.
 * @param [in] event_connected wifi_event_sta_connected_t.
 */
void WiFiEventHandler::staConnected(wifi_event_sta_connected_t* info) {
	ESP_LOGD(LOG_TAG, "default staConnected");
} // staConnected


/**
 * @brief Handle the Station Disconnected event.
 * Handle having disconnected from remote AP.
 * @param [in] event_disconnected wifi_event_sta_disconnected_t.
 */
void WiFiEventHandler::staDisconnected(wifi_event_sta_disconnected_t* info) {
	ESP_LOGD(LOG_TAG, "default staDisconnected");
} // staDisconnected


/**
 * @brief Handle a Station Connected to AP event.
 * Handle having a station connected to ESP32 soft-AP.
 * @param [in] event_sta_connected wifi_event_ap_staconnected_t.
 */
void WiFiEventHandler::apStaConnected(wifi_event_ap_staconnected_t* info) {
	ESP_LOGD(LOG_TAG, "default apStaConnected");
} // apStaConnected


/**
 * @brief Handle a Station Disconnected from AP event.
 * Handle having a station disconnected from ESP32 soft-AP.
 * @param [in] event_sta_disconnected wifi_event_ap_stadisconnected_t.
 */
void WiFiEventHandler::apStaDisconnected(wifi_event_ap_stadisconnected_t* info) {
	ESP_LOGD(LOG_TAG, "default apStaDisconnected");
} // apStaDisconnected


/**
 * @brief Handle a Scan for APs done event.
 * Handle having an ESP32 station scan (APs) done.
 * @param [in] event_scan_done wifi_event_sta_scan_done_t.
 */
void WiFiEventHandler::staScanDone(wifi_event_sta_scan_done_t* info) {
	ESP_LOGD(LOG_TAG, "default staScanDone");
} // staScanDone


/**
 * @brief Handle the auth mode of APs change event.
 * Handle having the auth mode of AP ESP32 station connected to changed.
 * @param [in] event_auth_change wifi_event_sta_authmode_change_t.
 */
void WiFiEventHandler::staAuthChange(wifi_event_sta_authmode_change_t* info) {
	ESP_LOGD(LOG_TAG, "default staAuthChange");
} // staAuthChange


WiFiEventHandler::~WiFiEventHandler() {
} // ~WiFiEventHandler
