#include "h_crane.h"
#include "ev3dev.h"
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>





class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::light_sensor light_q;
    ev3dev::motor a;
    ev3dev::motor b; 
    ev3dev::motor c;
    
    
public:
    // Hardware Configuration
    Crain():m_speed(0), touch_q(ev3dev::INPUT_2),a(ev3dev::OUTPUT_B), b(ev3dev::OUTPUT_C), c(ev3dev::OUTPUT_A), light_q(ev3dev::INPUT_1)
    {
        
    }
    
    int m_speed;
    
    bool get_distance()
    {
        return light_q.reflected_light_intensity();
    }

    bool time_sp()
    {
        return 100;
    }
    
    
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();
    }
    
    virtual bool get_down()
    {
        return m_down;
    }

    virtual bool get_up()
    {
        return m_up;
    }

    virtual bool get_right()
    {
        return m_right;
    }

    virtual bool get_left()
    {
        return m_left;
    }

    virtual bool get_enter()
    {
        return m_enter;
    }

    virtual bool get_escape()
    {
        return m_escape;
    }

    virtual int  get_speed()
    {
        return 100;
    }

    virtual int position_sp()
    {
        return 50;
    }

    virtual void set_down(bool val)
    {
        m_down = val;
    }
    
    virtual void set_up(bool val)
    {
        m_up = val;    
    }
    
    virtual void set_right(bool val)
    {
        m_right = val;   
    }
    virtual void set_left(bool val)
    {
        m_left = val; 
    } 
    
    virtual void set_enter(bool val)
    {
        m_enter = val;    
    }
    
    virtual void set_escape(bool val)
    {
        m_escape = val;    
    }
    
    virtual void set_speed(int val)
    {
        m_speed = val;    
    }
public:
    void example_code();
    void example_code2();
};








void Crain::example_code()
{ //This function is for example, you should develop your own logics
    while(get_escape() == false)
    {
/*        set_down(ev3dev::medium_motor::medium_motor.connect());
        set_up(ev3dev::motor::OUTPUT_A.connected());
        set_down(ev3dev::motor::OUTPUT_B.connected());
        set_up(ev3dev::motor::OUTPUT_B.connected());
        set_down(ev3dev::motor::OUTPUT_C.connected());
        set_up(ev3dev::motor::OUTPUT_C.connected());
            
  */      
        
//        set_up(ev3dev::button::enter.pressed());
//        set_right(ev3dev::button::enter.pressed());
//        set_left(ev3dev::button::enter.pressed());

//        c.set_speed_sp(100);
//        c.set_position(300);
//        c.run_forever();
        
            
         

/*            b.set_speed_sp(100);
            b.set_position(50);
            b.set_position(100);


            c.set_speed_sp(100);
            c.set_position(50);
            c.set_position(100);        
            
            b.set_speed_sp(get_speed());
            b.run_to_abs_pos();
            c.set_speed_sp(get_speed());
            c.run_to_abs_pos();
            
            
            
            a.command_run_timed[200];
            a.command_stop[50];
            b.command_run_timed[-200];
            b.command_run_timed[100];



            a.command_reset[0];
            b.command_reset[0];
         
            
//            a.nxt_light(-1*get_speed());
//            a.set_speed_sp(get_speed());
//            b.set_speed_sp(get_speed());
//            b.set_speed_sp(-1* get_speed());
//            c.set_speed_sp(get_speed());
                
*/        

    }

//    a.stop();
//    b.stop();
}


void Crain::example_code2()
{

/*        a.set_speed_sp(50);
        a.set_position(-300);
        a.run_to_abs_pos();
        a.set_position(800);
        a.run_to_abs_pos();
      


        b.set_speed_sp(50);
        b.set_position(300);
        b.run_to_abs_pos();
*/        
        
        a.set_speed_sp(50);
        a.set_position(300);
        a.run_to_abs_pos();        
         
}



int main()
{     
    Crain crain;
    
    
    while(true){
        if(crain.get_touch_pressed()==true){ 
            
           
//         crain.example_code(); //This line is for example, you should erase this ex_code in your 'real code' 
        crain.example_code2();
  
  
        }
    }
}