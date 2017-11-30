#include <stdbool.h>
#include <stdio.h>
#include "car.h"

#define MAX_ACCERATION_RATE_AIXAM 1.0
#define MAX_ACCERATION_RATE_FIAT 2.26
#define MAX_ACCERATION_RATE_JEEP 3.14
#define MIN_ACCERATION_RATE -8

#define MAX_SPEED_AIXAM 45
#define MAX_SPEED_FIAT 170
#define MAX_SPEED_JEEP 196
int round(double speed);


struct CarType{
  enum Type type;
  enum Color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool isRented;
};

static struct CarType aixam = {AIXAM, RED,  16.0, 0.0 , 0, false};
static struct CarType fiat_multiplay_Vo1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
static struct CarType fiat_multiplay_Vo2  = {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
static struct CarType fiat_multiplay_Vo3  = {FIAT_MULTIPLA, ORANGE, 65, 0 ,0, false};
static struct CarType jeep_Vo1 = {JEEP, SILVER, 80, 0, 0, false};
static struct CarType jeep_Vo2 = {JEEP, BLACK, 80, 0, 0, false};

void init(){

  aixam.fill_level = 16;
  aixam.acceleration_rate = 0;
  aixam.speed = 0;
  aixam.isRented = false;

  fiat_multiplay_Vo1.fill_level = 65;
  fiat_multiplay_Vo1.acceleration_rate = 0;
  fiat_multiplay_Vo1.speed = 0;
  fiat_multiplay_Vo1.isRented = false;

  fiat_multiplay_Vo2.fill_level = 65;
  fiat_multiplay_Vo2.acceleration_rate = 0;
  fiat_multiplay_Vo2.speed = 0;
  fiat_multiplay_Vo2.isRented = false;

  fiat_multiplay_Vo3.fill_level = 65;
  fiat_multiplay_Vo3.acceleration_rate = 0;
  fiat_multiplay_Vo3.speed = 0;
  fiat_multiplay_Vo3.isRented = false;

  jeep_Vo1.fill_level = 80;
  jeep_Vo1.acceleration_rate = 0;
  jeep_Vo1.speed = 0;
  jeep_Vo1.isRented = false;

  jeep_Vo2.fill_level = 80;
  jeep_Vo2.acceleration_rate = 0;
  jeep_Vo2.speed = 0;
  jeep_Vo2.isRented = false;
}

Car get_car(enum Type type)
{
  Car car;
  switch (type) {
    case AIXAM:
      if (aixam.isRented == false)
      {
        aixam.isRented = true;
        car = &aixam;
      }
      else
      {
        car = 0;
      }
      return car;
    case FIAT_MULTIPLA:
      if (fiat_multiplay_Vo1.isRented == false)
      {
        fiat_multiplay_Vo1.isRented = true;
        car = &fiat_multiplay_Vo1;
      }
      else if(fiat_multiplay_Vo2.isRented == false)
      {
        fiat_multiplay_Vo2.isRented = true;
        car = &fiat_multiplay_Vo2;
      }
      else if (fiat_multiplay_Vo3.isRented == false)
      {
        fiat_multiplay_Vo3.isRented = true;
        car = &fiat_multiplay_Vo3;
      }
      else
      {
        car = 0;
      }
      return car;
    case JEEP:
      if (jeep_Vo1.isRented == false)
      {
        jeep_Vo1.isRented = true;
        car = &jeep_Vo1;
      }
      else if (jeep_Vo2.isRented == false)
      {
        jeep_Vo2.isRented = true;
        car = &jeep_Vo2;
      }
      else
      {
        car = 0;
      }
      return car;
  }

}
Type get_type(Car car)
{
  return car->type;
}
Color get_color(Car car)
{
  return car->color;
}
float get_fill_level(Car car)
{
  return car->fill_level;
}
float get_acceleration_rate(Car car)
{
  return car->acceleration_rate;
}
void set_acceleration_rate(Car car,double acceleration_rate)
{
  switch (car->type)
  {
    case AIXAM:
      if(acceleration_rate < MIN_ACCERATION_RATE)
      {
        car->acceleration_rate = MIN_ACCERATION_RATE;
      }
      else if (acceleration_rate > MAX_ACCERATION_RATE_AIXAM)
      {
        car->acceleration_rate = MAX_ACCERATION_RATE_AIXAM;
      }
      else
      {
        car->acceleration_rate = acceleration_rate;
      }
      break;
    case FIAT_MULTIPLA:
      if(acceleration_rate < MIN_ACCERATION_RATE)
      {
        car->acceleration_rate = MIN_ACCERATION_RATE;
      }
      else if (acceleration_rate > MAX_ACCERATION_RATE_FIAT)
      {
        car->acceleration_rate = MAX_ACCERATION_RATE_FIAT;
      }
      else
      {
        car->acceleration_rate = acceleration_rate;
      }
      break;
    case JEEP:
      if(acceleration_rate < MIN_ACCERATION_RATE)
      {
        car->acceleration_rate = MIN_ACCERATION_RATE;
      }
      else if (acceleration_rate > MAX_ACCERATION_RATE_JEEP)
       {
         car->acceleration_rate = MAX_ACCERATION_RATE_JEEP;
       }
      else
      {
        car->acceleration_rate = acceleration_rate;
      }
      break;
  }
}
int round(double speed)
{
  int rounded = speed + 0.5;
  return rounded;
}
int get_speed(Car car)
{
  int speed = round(car->speed);
  return speed;
}
void accelerate(Car car)
{
  switch (car->type)
  {
    case AIXAM:
      if (car->speed + 3.6 * car->acceleration_rate <= MAX_SPEED_AIXAM)
      {
        car->speed = car->speed + 3.6 * car->acceleration_rate;
      }
      else
      {
        car->speed = MAX_SPEED_AIXAM;
      }
      break;
    case FIAT_MULTIPLA:
      if (car->speed + 3.6 * car->acceleration_rate <= MAX_SPEED_FIAT)
      {
      car->speed = car->speed + 3.6 * car->acceleration_rate;
      }
      else
      {
        car->speed = MAX_SPEED_FIAT;
      }
      break;
    case JEEP:
      if (car->speed + 3.6 * car->acceleration_rate <= MAX_SPEED_JEEP)
      {
        car->speed = car->speed + 3.6 * car->acceleration_rate;
      }
      else
      {
        car->speed = MAX_SPEED_JEEP;
      }
      break;
  }
}
