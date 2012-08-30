/* 
  Arduino_LED_CUBE  2012.08.29
*/

int pattern[][16] = {
{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0}, //0
{0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4 a
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},//5 b
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},//6 c
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},//7 d
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //9 a
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}, //13 a
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, //17 a
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}, //21 b
{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
{0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1}

};

int times = 0;

void setup() {
  for(int i=0; i<=19; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void floors(int chosen_floor) {
  switch(chosen_floor) {
    case 0:
      digitalWrite(16, HIGH);
      digitalWrite(17, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      break;
    case 1:
      digitalWrite(16, LOW);
      digitalWrite(17, HIGH);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      break;
    case 2:
      digitalWrite(16, LOW);
      digitalWrite(17, LOW);
      digitalWrite(18, HIGH);
      digitalWrite(19, LOW);
      break;
    case 3:
      digitalWrite(16, LOW);
      digitalWrite(17, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, HIGH);  
      break;
  }
}  

void patterns(int pattern_num) {
  for(int l=0; l<=15; l++) {
    if(pattern[pattern_num][l] == 0) {
      digitalWrite(l, HIGH);
    }
    if(pattern[pattern_num][l] == 1) {
      digitalWrite(l, LOW);
    } 
  }
}

void cube_patterns(int begin_number, int delay_time) {
  for(int m=begin_number; m <= begin_number+3; m++) {
    patterns(m);
    floors(m - begin_number);
    delay(delay_time);
  }
}

void surface(int pat, int flo) {
  patterns(pat);
  floors(flo);
  delay(50);
}


void turn_light(int s) {
  surface(s,0);
  surface(s,1);
  surface(s,2);
  surface(s,3);
  surface(s+1,3);
  surface(s+2,3);
  surface(s+3,3);
  surface(s+3,2);
  surface(s+3,1);
  surface(s+3,0);
  surface(s+2,0);
  surface(s+2,0);
}


void wipe_plate(int delay_time){
  patterns(8);
  floors(0);
  delay(delay_time);
  patterns(8);
  floors(1);
  delay(delay_time);
  patterns(8);
  floors(2);
  delay(delay_time);
  patterns(8);
  floors(3);
  delay(delay_time);
}

void loop() {
  cube_patterns(0, 100);
  cube_patterns(0, 100);
  cube_patterns(0, 100);
  
  for(times = 0; times <= 50; times++){
    cube_patterns(21, 1);
  }
  
  
  turn_light(4);
  turn_light(4);
  turn_light(9);
  turn_light(9);
  turn_light(13);
  turn_light(13);
  turn_light(17);
  turn_light(17);
  
  wipe_plate(50);
  wipe_plate(100);
  wipe_plate(200);
}
