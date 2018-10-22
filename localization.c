#include <kilolib.h>

int new_message = 0;
int x_value;
int y_value;

message_t message;

void setup()
{
    
}

void loop()
{
   if(get_ambientlight() > 800)
   {
       set_color(RGB(1,0,0));
       delay(1000);
       
   } else if (get_ambientlight() > 400)
   {
       set_color(RGB(0,1,0));
       delay(1000);
   } else 
   {
        set_color(RGB(0,0,1));
       delay(1000);
   }
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