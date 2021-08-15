
/*
 * creator: John Palmisano
 * https://github.com/societyofrobots/date_time/
 * 
 * tracks date/time... doesn't do daylight savings time or leap year
 * 
 * call date_time_print() whenever you need an update
 * also call it at least once before every millis() overflow (every 49.7 days)
*/

uint8_t minute=0;
uint8_t hour=0;
uint8_t day=1;
uint8_t month=1;
uint8_t year=21;

int64_t last_time=0;
int64_t time_elapsed;//milliseconds

void date_time_print(void)
  {
  Serial.print("\nDate/Time:");
  Serial.print(month); Serial.print("/"); Serial.print(day); Serial.print("/"); Serial.print(year);
  Serial.print(" "); Serial.print(hour); Serial.print(":"); Serial.println(minute);
  }

void date_time_calculate(void)
  {
  //get time elapsed
  time_elapsed = millis()-last_time;
  
  if(time_elapsed < 0)//if overflow
    time_elapsed+=4294967296;

  while(time_elapsed >= 60000)//one minute passed
    {
    last_time = millis()-(time_elapsed-60000);//includes any time over 1 minute, could be negative on overflow
    
    if(last_time < 0)//if overflow
      time_elapsed+=4294967296;
      
    time_elapsed = millis()-last_time;//will be negative on overflow
    
    if(time_elapsed < 0)//if overflow
      time_elapsed+=4294967296;
  
//    Serial.println(time_elapsed); Serial.println(last_time); Serial.println(millis());
    
    if(minute < 59)
      minute++;
    else
      {
      minute=0;

      if(hour <23)
        hour++;
      else
        {
        hour=0;
/*
#   Month     Days
01  January   31
02  February  28
03  March     31
04  April     30
05  May       31
06  June      30
07  July      31
08  August    31
09  September 30
10  October   31
11  November  30
12  December  31
*/
        if(month==1 && day<31)
          day++;
        else if(month==2 && day<28)
          day++;
        else if(month==3 && day<31)
          day++;
        else if(month==4 && day<30)
          day++;
        else if(month==5 && day<31)
          day++;
        else if(month==6 && day<30)
          day++;
        else if(month==7 && day<31)
          day++;
        else if(month==8 && day<31)
          day++;
        else if(month==9 && day<30)
          day++;
        else if(month==10 && day<31)
          day++;
        else if(month==11 && day<30)
          day++;
        else if(month==12 && day<31)
          day++;
        else
          {
          day=1;

          if(month<12)
            month++;
          else
            {
            month=1;
            year++;
            }
          }
        }
      }
    //date_time_print();
    }
  }
