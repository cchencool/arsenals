
#if !defined(Counter_hpp)
#define Counter_hpp

#include <ArduinoSTL.h>
#include "Arduboy.h"
#include "arduino.h"
#include "Btn_ctrl.hpp"

extern Btn_ctrl *btn_ctrl;

// for func counter.
PROGMEM const String hello_str = "hello, my darling.";

long count = 0l;
long count_times = 1l;

const int lock_free_frame_limit = 15;
int lock_free_frame_count = 0;

boolean lock = false;
boolean lock_free = false;

void draw_square()
{
  arduboy->drawLine(0, 0, 5, 5, WHITE);
  arduboy->drawLine(5, 5, 122, 5, WHITE);
  arduboy->drawLine(5, 5, 5, 58, WHITE);
  arduboy->drawLine(122, 5, 127, 0, WHITE);
  arduboy->drawLine(122, 5, 122, 58, WHITE);
  arduboy->drawLine(122, 58, 127, 63, WHITE);
  arduboy->drawLine(5, 58, 122, 58, WHITE);
  arduboy->drawLine(5, 58, 0, 63, WHITE);
}

void do_count()
{

  // up
  if (arduboy->pressed(UP_BUTTON) == true && (!lock || lock_free))
  {
    count += count_times;
    lock = true;
    lock_free_frame_count++;
  }

  // down
  if (arduboy->pressed(DOWN_BUTTON) == true && (!lock || lock_free))
  {
    count -= count_times;
    lock = true;
  }

  // right
  if (arduboy->pressed(RIGHT_BUTTON) == true && (!lock || lock_free))
  {
    count_times *= 10;
    lock = true;
  }

  // left
  if (arduboy->pressed(LEFT_BUTTON) == true && (!lock || lock_free))
  {
    count_times *= 0.1;
    if (count_times == 0)
    {
      count_times = 1;
    }
    lock = true;
  }

  // func
  if (arduboy->pressed(A_BUTTON) == true && (!lock || lock_free))
  {
    count = 0;
    count_times = 1;
    lock = true;
  }
}

void check_lock_free_flag()
{

  if (arduboy->pressed(A_BUTTON) == true || arduboy->pressed(B_BUTTON) == true || arduboy->pressed(UP_BUTTON) == true || arduboy->pressed(DOWN_BUTTON) == true || arduboy->pressed(RIGHT_BUTTON) == true || arduboy->pressed(LEFT_BUTTON) == true)
  {
    lock_free_frame_count++;
  }

  if (lock_free_frame_count >= lock_free_frame_limit)
  {
    lock = false;
    lock_free = true;
  }
}

void check_lock_flag()
{

  if (arduboy->notPressed(A_BUTTON) == true && arduboy->notPressed(B_BUTTON) == true && arduboy->notPressed(UP_BUTTON) == true && arduboy->notPressed(DOWN_BUTTON) == true && arduboy->notPressed(RIGHT_BUTTON) == true && arduboy->notPressed(LEFT_BUTTON) == true)
  {
    lock = false;
    lock_free = false;
    lock_free_frame_count = 0;
  }
}

#endif // Counter_hpp