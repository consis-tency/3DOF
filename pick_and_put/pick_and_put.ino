#include <Servo.h>
Servo base, joint, claw;
int base_pin = 6, joint_pin = 7, claw_pin = 9, delta, micro_movement_delay = 15;
int base_curr_pos = 10, base_pick_pos = 30, base_drop_pos = 120;
int joint_curr_pos = 10,joint_up_pos = 120, joint_down_pos = 50;
int claw_curr_pos = 10, claw_open_pos = 180, claw_close_pos = 180;


void setup() {
  // put your setup code here, to run once:
  base.attach(base_pin);
  joint.attach(joint_pin);
  claw.attach(claw_pin);

// setting initial positions for
//base
  base.write(base_curr_pos);
  delay(1000);
//joint
  joint_curr_pos = joint_up_pos;
  joint.write(joint_curr_pos);
  delay(1000);
// claw
  claw.write(claw_curr_pos);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
//  base come to pick up point
  delta = calculate_delta(base_curr_pos, base_pick_pos);
  
  for (base_curr_pos; base_curr_pos != base_pick_pos; base_curr_pos += delta){
    base.write(base_curr_pos);
    delay(micro_movement_delay);
  }

//  joint is at up position
  // This has been set already in void setup
  
//  claw opens from being closed
  delta = calculate_delta(claw_curr_pos, claw_open_pos);
  
  for (claw_curr_pos; claw_curr_pos != claw_open_pos; claw_curr_pos += delta){
    base.write(claw_curr_pos);
    delay(micro_movement_delay);
  }
    
//  joint goes to down position
  delta = calculate_delta(joint_curr_pos, joint_down_pos);
  
  for (joint_curr_pos; joint_curr_pos != joint_down_pos; joint_curr_pos += delta){
    base.write(joint_curr_pos);
    delay(micro_movement_delay);
  }
  
//  claw closes to grab the object
  delta = calculate_delta(claw_curr_pos, claw_close_pos);
  
  for (claw_curr_pos; claw_curr_pos != claw_close_pos; claw_curr_pos += delta){
    base.write(claw_curr_pos);
    delay(micro_movement_delay);
  }
  
//  joint goes up: picking up the object
  delta = calculate_delta(joint_curr_pos, joint_up_pos);
  
  for (joint_curr_pos; joint_curr_pos != joint_up_pos; joint_curr_pos += delta){
    base.write(joint_curr_pos);
    delay(micro_movement_delay);
  }

//  base rotates to drop off point
  delta = calculate_delta(base_curr_pos, base_drop_pos);
  
  for (base_curr_pos; base_curr_pos != base_drop_pos; base_curr_pos += delta){
    base.write(base_curr_pos);
    delay(micro_movement_delay);
  }

//  joint goes down
  delta = calculate_delta(joint_curr_pos, joint_down_pos);
  
  for (joint_curr_pos; joint_curr_pos != joint_down_pos; joint_curr_pos += delta){
    base.write(joint_curr_pos);
    delay(micro_movement_delay);
  }
  
//  claw opens: putting down the object
  delta = calculate_delta(claw_curr_pos, claw_open_pos);
  
  for (claw_curr_pos; claw_curr_pos != claw_open_pos; claw_curr_pos += delta){
    base.write(claw_curr_pos);
    delay(micro_movement_delay);
  }

//  joint goes up
  delta = calculate_delta(joint_curr_pos, joint_up_pos);
  
  for (joint_curr_pos; joint_curr_pos != joint_up_pos; joint_curr_pos += delta){
    base.write(joint_curr_pos);
    delay(micro_movement_delay);
  }
}

int calculate_delta(int curr_pos, int end_pos){
  if (curr_pos > end_pos) {
    return -1;}
  return 1;
}  
