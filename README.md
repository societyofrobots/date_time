# date_time
Ultra-simple tracking of date and time using millis() on microcontrollers, for example Arduino and ESP32.

<br><b>Step 1:</b>
<br>Initialize current date/time variables in setup() of your code.
<p><i>example,</i>
<br>//initialize date/time
<br>month=1;
<br>day=1;
<br>year=21;
<br>hour=0;
<br>minute=0;

<br><b>Step 2:</b>
<br>Call the this function whenever you need to calculate current date/time:
<br>date_time_calculate();
<p><i>important</i>: Must be done at least once every 49 days, before the millis() timer overflows.

<br><b>Step 3:</b>
<br>//Print out date/time
<br>date_time_print();
