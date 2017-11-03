#include "h_crane.h"
#include "ev3dev.h"
#include <iostream>
int L[100]; //Location of object.    

class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::touch_sensor touch_s;    
    ev3dev::ultrasonic_sensor ultrasonic_q;
    ev3dev::motor a;
    ev3dev::motor b; 
    ev3dev::motor c;
    
public:
    // Hardware Configuration
    Crain():m_speed(100), touch_q(ev3dev::INPUT_2), touch_s(ev3dev::INPUT_4), b(ev3dev::OUTPUT_B), c(ev3dev::OUTPUT_C), a(ev3dev::OUTPUT_A), ultrasonic_q(ev3dev::INPUT_1) 
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
        return 300;
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
    void hold_m();
    void scan();
    void pick_up();
    void default_point();
    void default_point_2();
    void default_point_3();
    void m_reset();
    void drop();
};



void Crain::hold_m()
{
        b.set_speed_sp(0);
        b.run_forever();
}


void Crain::default_point()
{

        
        
        int i= 0;
        
        
        
        while(ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(500);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            
        }
        Crain::hold_m();
        
        


        
        while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters()<9)
            {
            c.set_speed_sp(0);
            c.run_forever();
            
            c.set_speed_sp(800);        
            c.set_position_sp(-50);
            c.run_to_rel_pos();
            
            pick_up();
            
            while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            }
/*            b.set_speed_sp(200);
            b.set_position_sp(-50);
            b.run_to_rel_pos();
*/        
            drop();
            }

            
        }
            
        int u=0;
        while(u<700){
        c.set_speed_sp(600);
        c.set_position_sp(-4);
        c.run_to_rel_pos();
        u++;
        }        
        
        
                    
        a.stop();
        b.stop();
        c.stop();
}
        
void Crain::default_point_2()
{

        int i= 0;

            
        while(ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(500);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
                        
        }
        Crain::hold_m();


        
        while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(-40);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters()<9)
            {
                c.set_speed_sp(0);
                c.run_forever();
            
                c.set_speed_sp(800);        
                c.set_position_sp(-50);
                c.run_to_rel_pos();
            
                pick_up();
            
                while(get_touch_pressed()==0){
                    c.set_speed_sp(500);        
                    c.set_position_sp(40);
                    c.run_to_rel_pos();
            }
            
            drop();
            }
            
        }
        
        int u=0;
        while(u<700){
        c.set_speed_sp(600);
        c.set_position_sp(-50);
        c.run_to_rel_pos();
        u++;
        }        
        
        
/*    int p=0;
    if(get_distance()<3){
        while(p<80){
            b.set_speed_sp(200);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            
            c.set_speed_sp(500);        
            c.set_position_sp(-40);
            c.run_to_rel_pos();
        
        p++;    
            
        }
    Crain::hold_m();    

*/
    }    
        
        
        
void Crain::default_point_3()
{

        int i= 0;

            
        while(ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(500);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
                        
        }
        Crain::hold_m();


        
        while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(-40);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters()<9)
            {
                c.set_speed_sp(0);
                c.run_forever();
            
                c.set_speed_sp(800);        
                c.set_position_sp(-50);
                c.run_to_rel_pos();
            
                pick_up();
            
                while(get_touch_pressed()==0){
                    c.set_speed_sp(500);        
                    c.set_position_sp(40);
                    c.run_to_rel_pos();
            }
            
            drop();
            }
            
        }
        
/*        int u=0;
        while(u<700){
        c.set_speed_sp(600);
        c.set_position_sp(-1);
        c.run_to_rel_pos();
        u++;
        }        
        
        
    int p=0;
    if(get_distance()<3){
        while(p<80){
            b.set_speed_sp(200);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            
            c.set_speed_sp(500);        
            c.set_position_sp(-40);
            c.run_to_rel_pos();
        
        p++;    
            
        }
    Crain::hold_m();    

*/
    }    
        
        
        


void Crain::pick_up()
{
        int i = 0;
        while( ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(500);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
        }
        Crain::hold_m();
        
        while( ultrasonic_q.distance_centimeters() > 4){
            b.set_speed_sp(200);
            b.set_position_sp(3);
            b.run_to_rel_pos();
        }
        Crain::hold_m();

        
        i = 0;
        while( i < 600){
            a.set_speed_sp(700);
            a.set_position_sp(-1);
            a.run_to_rel_pos();
            i ++;
        }
        b.set_speed_sp(0);
        b.run_forever();

        while( ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(500);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
        }
        Crain::hold_m();    
        
}

void Crain::drop()
{
        int i;
        while(ultrasonic_q.distance_centimeters() > 4){
            b.set_speed_sp(200);
            b.set_position_sp(3);
            b.run_to_rel_pos();
        }
        Crain::hold_m();

        i = 0;
        while( i < 600){
            a.set_speed_sp(700);
            a.set_position_sp(1);
            a.run_to_rel_pos();
            i ++;
        }
        
        while(ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(200);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
        }

        Crain::hold_m();
}




void Crain::scan()
{
        int i = 0;
        while(ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(500);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            i++;
        }
        Crain::hold_m();

        
        i = 0;
        int dis = 0;
        dis = ultrasonic_q.distance_centimeters();
        std::cout << "dis =" << dis << std::endl;
        
        c.reset();
        while(touch_q.is_pressed() != true){
            c.set_speed_sp(250);        
            c.set_position_sp(100);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters() < dis-0.7 ){
                c.set_speed_sp(0);        
                c.run_forever();
                Crain::pick_up();
                L[i] = c.position();
                std::cout << "Position :" <<L[i] << std::endl;
                i ++;
            if (touch_q.is_pressed() == true) break;
            }

        }

}



int main()
{     
    Crain crain;
    while(true){
        if(crain.start_touch_pressed()==true){ 
            
            

            crain.default_point();
            crain.default_point();
            crain.default_point();
            crain.default_point();
            
//            crain.default_point_2();
//            crain.default_point_3();
    }
}


}


