#ifndef HOBBIT_TIME_H
#define HOBBIT_TIME_H

#include <Watchy.h>
#include "NunitoSans_Black12pt7b.h"
#include "NunitoSans_Black18pt7b.h"

class HobbitTime : public Watchy {
  using Watchy::Watchy;
  private:
    void drawCentered(String text, int y2);  
  public:
    void drawWatchFace();
};

#endif
