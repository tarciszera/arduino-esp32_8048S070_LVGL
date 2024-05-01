/*******************************************************************************
 * Touch libraries:
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 ******************************************************************************/

 #define TOUCH_GT911
 #define TOUCH_GT911_SCL 20
 #define TOUCH_GT911_SDA 19
 #define TOUCH_GT911_INT -1
 #define TOUCH_GT911_RST 38
 #define TOUCH_GT911_ROTATION ROTATION_NORMAL
 #define TOUCH_MAP_X1 800
 #define TOUCH_MAP_X2 0
 #define TOUCH_MAP_Y1 480
 #define TOUCH_MAP_Y2 0

int touch_last_x = 0, touch_last_y = 0;

#include <Wire.h>
#include <TAMC_GT911.h>
TAMC_GT911 ts = TAMC_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));

void touch_init()
{
  Wire.begin(TOUCH_GT911_SDA, TOUCH_GT911_SCL);
  ts.begin();
  ts.setRotation(TOUCH_GT911_ROTATION);
}

bool touch_has_signal()
{
  return true;
}

bool touch_touched()
{
  ts.read();
  if (ts.isTouched)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool touch_released()
{
  return true;
}
