#include <Watchy.h> //include the Watchy library
#include "NunitoSans_Black12pt7b.h"
#include "NunitoSans_Black18pt7b.h"


class WatchFace : public Watchy { //inherit and extend Watchy class
  public:
      void drawCentered(String text, int y2) {
        int16_t  x1, y1;
        uint16_t w1, h1;
      
        display.getTextBounds(text, 0, 0, &x1, &y1, &w1, &h1);
        if (y2 == -10 ) {
          display.setCursor(100-w1/2,100-h1/2);
        } else {
          display.setCursor(100-w1/2,y2+h1);
        }
        display.print(text);
      }
  
    void drawWatchFace() { //override this method to customize how the watch face looks
      String textstring = "";
      const char *lines [25] = {
        "Midnight snack",
        "Sleep",
        "Sleep",
        "Sleep",
        "Sleep",
        "Sleep",
        "breakfast",
        "Breakfast",
        "second breakfast",
        "Second breakfast",
        "elevenses",
        "Elevenses",
        "Luncheon",
        "After lunch nap",
        "Afternoon tea",
        "three-ish",
        "dinner",
        "Dinner",
        "Supper",
        "Supper",
        "Eight-ish",
        "Nine-ish",
        "Sleep",
        "Sleep",
        "Midnight snack"
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
      drawCentered(textstring,5);

      //drawlabel
      display.setFont(&NunitoSans_Black18pt7b);
      if(currentTime.Hour == 6 || currentTime.Hour == 8 || currentTime.Hour == 10 | currentTime.Hour == 16 || currentTime.Hour == 18){
        drawCentered("Almost",80);
        drawCentered(lines[currentTime.Hour],102);
      }
      drawCentered(lines[currentTime.Hour],-10);
    }
};

WatchFace m; //instantiate your watchface

void setup() {
  m.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
