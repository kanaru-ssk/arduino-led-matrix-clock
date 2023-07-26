#define C0 2
#define R0 10
#define NCOL 8
#define NROW 8
unsigned long time;
int minutes_x;
int minutes_y;
int minutes_before;
byte Pattern[NROW][NCOL];

byte Pattern_01[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_02[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_03[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_04[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_05[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_06[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_07[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte Pattern_08[NROW][NCOL] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup(){
  //Serial.begin(9600);
  minutes_x = 4;
  minutes_y = 0;
  for(int i = 0; i < NCOL; i++){
    int col = C0 + i;
    pinMode(col, OUTPUT);
    digitalWrite(col, LOW);
  }

  for(int i = 0; i < NROW; i++){
    int row = R0 + i;
    pinMode(row, OUTPUT);
    digitalWrite(row, HIGH);
  }
  
}

void loop(){
  time = millis();
  
  //秒針
  int second = (abs(time)/1000)%8;
  switch(second){
    case 0:
      memcpy(Pattern, Pattern_01, sizeof(Pattern_01));
      break;
    case 1:
      memcpy(Pattern, Pattern_02, sizeof(Pattern_02));
      break;
    case 2:
      memcpy(Pattern, Pattern_03, sizeof(Pattern_03));
      break;
    case 3:
      memcpy(Pattern, Pattern_04, sizeof(Pattern_04));
      break;
    case 4:
      memcpy(Pattern, Pattern_05, sizeof(Pattern_05));
      break;
    case 5:
      memcpy(Pattern, Pattern_06, sizeof(Pattern_06));
      break;
    case 6:
      memcpy(Pattern, Pattern_07, sizeof(Pattern_07));
      break;
    case 7:
      memcpy(Pattern, Pattern_08, sizeof(Pattern_08));
      break;
  }

  //分針
  int minutes = (abs(time)/8000)%28;
  if(minutes != minutes_before){
    if(3 < minutes && minutes <= 10){
      minutes_y++;
    }else if(10 < minutes && minutes <= 17){
      minutes_x--;
    }else if(17 < minutes && minutes <= 24){
      minutes_y--;
    }else{
      minutes_x++;
    }
  }
  minutes_before = minutes;

  //描画
  for(int i = 0; i < NROW; i++){
    for(int j = 0; j < NCOL; j++){
      int col = C0 + j;
      if(Pattern[i][j] == 0){
        if(j == minutes_x && i == minutes_y){
          digitalWrite(col, HIGH);
        }else{
          digitalWrite(col, LOW);
        }
      }
      else{
        digitalWrite(col, HIGH);
      }
    }
    int row = R0 + i;
    digitalWrite(row, LOW);
    delay(1);
    digitalWrite(row, HIGH);
  }

  //デバッグ用
  Serial.print("minutes: ");
  Serial.print(minutes);
  Serial.print("\t");
  Serial.print("X: ");
  Serial.print(minutes_x);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.print(minutes_y);
  Serial.println("");
}
