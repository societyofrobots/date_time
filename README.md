# date_time
Ultra-simple tracking of date and time using millis() on microcontrollers, for example Arduino and ESP32.

Step 1:
Create and initialize your own current date/time variables.

example,
uint8_t your_month=1;
uint8_t your_day=1;
uint8_t your_year=20;
uint8_t your_hour=0;
uint8_t your_minute=0;


Step 2;
Call the this function whenever you need to calculate current date/time:
date_time_calculate()

important: Must be done at least once every 49 days, before the millis() timer overflows.


Step 3:
