#include "esp32_8048S070_lvgl.h"
#include <examples\get_started\lv_example_get_started.h>

void setup()
{
  lvgl_setup(lv_example_get_started_3);
}

void loop()
{
  lvgl_loop();
}
