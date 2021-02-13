#include <Watchy.h> //include the Watchy library
#include "NunitoSans_Black12pt7b.h"
#include "NunitoSans_Black18pt7b.h"


class WatchFace : public Watchy { //inherit and extend Watchy class
  public:
      void drawCentered(String text, int y2) {
        int16_t  x1, y1;
        uint16_t w1, h1;
      
        display.getTextBounds(text, 0, 0, &x1, &y1, &w1, &h1);
          display.setCursor(100-w1/2,y2+h1/2);
        display.print(text);
      }
  
    void drawWatchFace() { //override this method to customize how the watch face looks
      String textstring = "";
      const char *lines [25][] = {
        {2,"Midnight","snack"},
        {1,"Sleep"},
        {1,"Sleep"},
        {1,"Sleep"},
        {1,"Sleep"},
        {1,"Sleep"},
        {2,"Almost","breakfast"},
        {1,"Breakfast"},
        {3,"Almost","second","breakfast"},
        {2,"Second","breakfast"},
        {2,"Almost","elevenses"},
        {1,"Elevenses"},
        {1,"Luncheon"},
        {3,"After","lunch","nap"},
        {2,"Afternoon","tea"},
        {1,"Three-ish"},
        {2,"Almost","dinner"},
        {1,"Dinner"},
        {2,"Almost","supper"},
        {1,"Supper"},
        {1,"Eight-ish"},
        {1,"Nine-ish"},
        {1,"Sleep"},
        {1,"Sleep"},
        {2,"Midnight","snack"}
      };

      //drawbg
      if (currentTime.Hour < 7 || currentTime.Hour > 20 || currentTime.Hour == 13) {
        display.fillScreen(GxEPD_BLACK);
        display.setTextColor(GxEPD_WHITE);
      } else {
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);
      }

      //drawtime
      display.setFont(&NunitoSans_Black12pt7b);
      textstring = currentTime.Hour;
      textstring += ":";
      textstring += currentTime.Minute;
      drawCentered(textstring,15);

      //drawlabel
      display.setFont(&NunitoSans_Black18pt7b);
      if (lines[currentTime.Hour][0]==1){
      drawCentered(lines[currentTime.Hour][1],100);
    } else if (lines[currentTime.Hour][0]==2){
      drawCentered(lines[currentTime.Hour][1],90);
      drawCentered(lines[currentTime.Hour][2],110);
    } else if (lines[currentTime.Hour][0]==3){
      drawCentered(lines[currentTime.Hour][1],80);
      drawCentered(lines[currentTime.Hour][2],100);
      drawCentered(lines[currentTime.Hour][3],120);
    }
};

WatchFace m; //instantiate your watchface

void setup() {
  m.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
