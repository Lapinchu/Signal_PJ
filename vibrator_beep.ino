int speakerPin = 12;
int sensor = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int shake = LOW;
int cnt = 0;
int cnt_tmp = 0;
unsigned long prev_time = 0;
unsigned long count_time = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  unsigned long current_time = millis();

  if(val<500) shake = HIGH;

  if(current_time - prev_time > 1000){
    if(shake == 1){
      cnt += 1;
      cnt_tmp = cnt;
      count_time = current_time;
    }
    if((current_time - count_time > 3000) && (cnt == cnt_tmp)){
      cnt = 0;
      cnt_tmp = 0;
    }
    Serial.print(shake);
    Serial.print(" ");
    Serial.print(val);
    Serial.print(" ");
    Serial.println(cnt);
    prev_time = current_time;
    shake = LOW;
  }

  if(cnt >= 5){
    tone(speakerPin, 500, 1000);
    delay(200);
  }

}
