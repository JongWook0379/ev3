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
    void pick_up();
    void Do_1();
    void Do_2();
    void Do_3();
    void go_back();
    void m_reset();
    void drop();
    void robot();
    //void scan();

    
};



void Crain::hold_m()
{
        b.set_speed_sp(0);
        b.run_forever();
}


void Crain::Do_1()
{

        int i= 0;
        
        while(ultrasonic_q.distance_centimeters() < 11){
            b.set_speed_sp(800);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            
        }
        Crain::hold_m();


        
        while(get_touch_pressed()==0){
            c.set_speed_sp(600);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters()<9)
            {
            c.set_speed_sp(0);
            c.run_forever();
            
            c.set_speed_sp(800);        
            c.set_position_sp(-25);
            c.run_to_rel_pos();

            while(ultrasonic_q.distance_centimeters() < 11){
                b.set_speed_sp(800);
                b.set_position_sp(-3);
                b.run_to_rel_pos();
                
            }
            Crain::hold_m();
                        
            pick_up();
            
            while(ultrasonic_q.distance_centimeters() < 11){
                b.set_speed_sp(800);
                b.set_position_sp(-3);
                b.run_to_rel_pos();
                
            }
            Crain::hold_m();

            
            while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            }
            drop();
            }
        }
}
void Crain::Do_2()
{

        int i= 0;
        
        while(ultrasonic_q.distance_centimeters() < 11){
            b.set_speed_sp(800);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            
        }
        Crain::hold_m();


        
        while(get_touch_pressed()==0){
            c.set_speed_sp(600);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters()<9)
            {
            c.set_speed_sp(0);
            c.run_forever();
            
            c.set_speed_sp(800);        
            c.set_position_sp(-20);
            c.run_to_rel_pos();

            while(ultrasonic_q.distance_centimeters() < 11){
                b.set_speed_sp(800);
                b.set_position_sp(-3);
                b.run_to_rel_pos();
                
            }
            Crain::hold_m();
                        
            pick_up();
            
            while(ultrasonic_q.distance_centimeters() < 11){
                b.set_speed_sp(800);
                b.set_position_sp(-3);
                b.run_to_rel_pos();
                
            }
            Crain::hold_m();

            
            while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            }
            drop();
            }
        }
}
void Crain::Do_3()
{

        int i= 0;
        
        while(ultrasonic_q.distance_centimeters() < 11){
            b.set_speed_sp(800);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
            
        }
        Crain::hold_m();


        
        while(get_touch_pressed()==0){
            c.set_speed_sp(600);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            
            if(ultrasonic_q.distance_centimeters()<9)
            {
            c.set_speed_sp(0);
            c.run_forever();
            
            c.set_speed_sp(800);        
            c.set_position_sp(-10);
            c.run_to_rel_pos();

            while(ultrasonic_q.distance_centimeters() < 11){
                b.set_speed_sp(800);
                b.set_position_sp(-3);
                b.run_to_rel_pos();
                
            }
            Crain::hold_m();
                        
            pick_up();
            
            while(ultrasonic_q.distance_centimeters() < 11){
                b.set_speed_sp(800);
                b.set_position_sp(-3);
                b.run_to_rel_pos();
                
            }
            Crain::hold_m();

            
            while(get_touch_pressed()==0){
            c.set_speed_sp(500);        
            c.set_position_sp(40);
            c.run_to_rel_pos();
            }
            drop();
            }
        }
}

void Crain::go_back()
{
        int i = 0 ;
        while( i < 800){
            c.set_speed_sp(800);
            c.set_position_sp(-2);
            c.run_to_rel_pos();
            i++;
        }
}
/*
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
            
            if(ultrasonic_q.distance_centimeters()<8)
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
    } */   

void Crain::pick_up()
{
        int i = 0;
        while( ultrasonic_q.distance_centimeters() < 11){
            b.set_speed_sp(800);
            b.set_position_sp(-4);
            b.run_to_rel_pos();
        }
        Crain::hold_m();
        while( ultrasonic_q.distance_centimeters() > 5){
            b.set_speed_sp(700);
            b.set_position_sp(3);
            b.run_to_rel_pos();
        }
        Crain::hold_m();

        
        i = 0;
        while( i < 600){
            a.set_speed_sp(600);
            a.set_position_sp(-1.5);
            a.run_to_rel_pos();
            i ++;
        }
        b.set_speed_sp(0);
        b.run_forever();

        while( ultrasonic_q.distance_centimeters() < 11){
            b.set_speed_sp(800);
            b.set_position_sp(-4);
            b.run_to_rel_pos();
        }
        Crain::hold_m();    
        
}

void Crain::drop()
{
        int i;
        while(ultrasonic_q.distance_centimeters() > 5){
            b.set_speed_sp(600);
            b.set_position_sp(3);
            b.run_to_rel_pos();
        }
        Crain::hold_m();

        i = 0;
        while( i < 600){
            a.set_speed_sp(550);
            a.set_position_sp(1.5);
            a.run_to_rel_pos();
            i ++;
        }
        
        while(ultrasonic_q.distance_centimeters() < 10){
            b.set_speed_sp(800);
            b.set_position_sp(-3);
            b.run_to_rel_pos();
        }

        Crain::hold_m();
}

/*


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
*/

void Crain::robot(){
            
            Crain crain;
            
            crain.Do_1();
            crain.go_back();
            crain.Do_2();
            crain.go_back();
            crain.Do_3();

}



int main()
{     
    Crain crain;
    
    Crain* a = new Crain;
        
    
   while(true){
        if(crain.start_touch_pressed()==true){ 
        
        a->robot();
        
        
        
        break;
            
        }
        
        
        
    }


    delete a;
    exit(0);
    
}