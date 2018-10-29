#include <kilolib.h>

int new_message = 0;
int x_value;
int y_value;
int brightest_value;
int darkest_value;

message_t message;

void light_callibration()
{
    int last_changed = kilo_ticks;
    int light_total = 0;
    int count = 0;
    while(last_changed + 64 > kilo_ticks)
    {
        light_total += get_ambientlight();
        count ++;
    }
    
    brightest_value = light_total / count;
    set_color(RGB(1,0,0));
    delay(7500);
    
    last_changed = kilo_ticks;
    light_total = 0;
    count = 0;
    while(last_changed + 64 > kilo_ticks)
    {
        light_total += get_ambientlight();
        count ++;
    }
    darkest_value = light_total / count;
    set_color(RGB(0,1,0));
    delay(7500);
}

void blink_binary(int num)
{
    int c, k;
    for (c = 15; c >= 0; c--)
    {
        k = num >> c;
     
        if (k & 1)
        {
            set_color(RGB(0,1,0));
            delay(1000);
        }
        else
        {
            set_color(RGB(0,1,0));
            delay(500);
        }
        set_color(RGB(0,0,0));
        delay(1000);
  }
}

void setup()
{
    light_callibration();
}

void loop()
{
  blink_binary(5);
}

void message_rx(message_t *m, distance_measurement_t *d)
{
    new_message = 1;
    
}

message_t *message_tx()
{
    return &message;
}



int main()
{
    kilo_init();
    kilo_message_rx = message_rx;
    kilo_message_tx = message_tx;
    kilo_start(setup, loop);
    
    return 0;
}