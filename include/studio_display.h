#ifndef STUDIO_DISPLAY_INCLUDED
#define STUDIO_DISPLAY_INCLUDED

#include <windows.h>

class StudioDisplay {
 public:
  StudioDisplay();

  int init();
  void deinit();
  int setBrightness(ULONG brightness);
  ULONG getBrightness();
  int stepBrightness(ULONG amount);

  void setMinBrightness(ULONG min);
  void setMaxBrightness(ULONG max);

 protected:
  ULONG minBrightness, maxBrightness;
  ULONG brightness;
};

#endif