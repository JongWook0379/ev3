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
#include <iostream>


int L[100];


class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::touch_sensor touch_s;
    ev3dev::light_sensor light_q;
    ev3dev::ultrasonic_sensor ultrasonic_q;
    ev3dev::motor a;
    ev3dev::motor b; 
    ev3dev::motor c;
    
    
public:
    // Hardware Configuration
    Crain():m_speed(0), touch_q(ev3dev::INPUT_2), touch_s(ev3dev::INPUT_3), b(ev3dev::OUTPUT_B), c(ev3dev::OUTPUT_C), a(ev3dev::OUTPUT_A), ultrasonic_q(ev3dev::INPUT_1)
    {
        
    }
    
    int m_speed;
    
    float get_distance()
    {
        return ultrasonic_q.distance_centimeters();
    }

    bool time_sp()
    {
        return 100;
    }
    
    
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();
    }

    bool start_touch_pressed()
    {
        return touch_s.is_pressed();
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
    void default_point();
};



void Crain::default_point()
{
        
//        int j = 0;
        while(get_touch_pressed()==false){
/*            a.set_speed_sp(100);        
            a.set_position_sp(10);
            a.run_to_rel_pos();
            
            b.set_speed_sp(200);        
            b.set_position_sp(50);
            b.run_to_rel_pos();
*/            
            c.set_speed_sp(300);        
            c.set_position_sp(40);
            c.run_to_rel_pos(); 
//            j++;

            
        }
        
        
       

        
        c.stop();
        a.stop();
        b.stop();
        
    
    
    
    
}




void Crain::example_code()
{
    
//        a.set_time_sp(3000);
//        b.set_time_sp(3000);
//        c.set_time_sp(3000);
//        a.run_timed();
//        b.run_timed();
//        c.run_timed();
        
        

        
    
    
    int i = 0;   
    
/*    
    
    while(c.position() != 800)
    {
//        c.set_position(800);
//        c.run_to_abs_pos();
          c.run_forever();
          
          
        if(get_distance() <= 25)
        {
            L[i] = c.position();
            i++;
            a.stop_action();
            b.reset();
            c.reset();
            b.set_position(-300);
            c.set_position(100);
            b.run_to_abs_pos();
            c.run_to_abs_pos();
            
            break;
      
        }
        
        
    }

        b.set_position(50);
        b.run_to_abs_pos();


        for(int k=0; k<30; k++)
    {
        c.set_position(L[k]);
        c.run_to_abs_pos();
//      pick up func    
        while(c.position() != 800)
        {
            c.run_forever()
        }
//      drop func        
    }  



//Scanning
        int i = 0;
        c.reset();
        while(c.position() > -300){
            c.set_speed_sp(100);        
            c.set_position_sp(-40);
            c.run_to_rel_pos();
            if (c.position() < -40*(i+1)){
                L[i] = c.position();
                std::cout << L[i] << std::endl;
                i ++;
            }
        }




*/
//        a.stop();
//        b.stop();
//        c.stop();


}



int main()
{     
    Crain crain;
    
    
    while(true){
        if(crain.start_touch_pressed()==true){ 
            
        crain.default_point();   
//        crain.example_code();
  
  
        }
    }
}