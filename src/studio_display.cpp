#include "hid.h"
#include "studio_display.h"

StudioDisplay::StudioDisplay() {
  minBrightness = 0;
  maxBrightness = 0;
  brightness = 0;
}

int StudioDisplay::init() {
  int err = hid_init();
  if (err < 0) {
    return err;
  }

  err = hid_getBrightness(&brightness);
  if (err < 0) {
    brightness = 30000;
  }

  return 0;
}

void StudioDisplay::deinit() {
  hid_deinit();
}

int StudioDisplay::setBrightness(ULONG value) {
  const int max_tries = 2;
  int err = 0;
  for (int i = 0; i < max_tries; ++i) {
    err = hid_setBrightness(value);
    if (err < 0) {
      deinit();
      init();
    } else {
      brightness = value;
      break;
    }
  }
  return err;
}

ULONG StudioDisplay::getBrightness() {
  return brightness;
}

int StudioDisplay::stepBrightness(ULONG amount) {
  ULONG target = getBrightness() + amount;
  if (target >= minBrightness && target <= maxBrightness) {
    return setBrightness(target);
  } else {
    return 0;
  }
}

void StudioDisplay::setMinBrightness(ULONG min) {
  minBrightness = min;
}

void StudioDisplay::setMaxBrightness(ULONG max) {
  maxBrightness = max;
}