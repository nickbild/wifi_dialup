int waveAmplitude = 0;
int offset = 150;
int offsets[6] = {50, 60, 70, 80, 90, 100};
int offsetCounter = 0;
int delayTime = 1;

void setup() {
  Serial1.begin(9600);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);

  digitalWrite(A1, LOW);
}

void loop() {
  // Read in Wi-Fi data via serial.
  if (Serial1.available()) {
    waveAmplitude = int(Serial1.read());
  }
  Serial1.println(waveAmplitude);

  // Changing offset too often yields static.
  if (offsetCounter > 250) {
    int offsetIdx = random(0, 6);
    offset = offsets[offsetIdx];
    offsetCounter = 0;

    delayTime = random(0, 2);
  }

  // Rising wave.
  for (int i=0; i<offset+waveAmplitude; i+=1) {
    analogWrite(A0, i);
    delayMicroseconds(delayTime);
  }
  // Falling wave.
  for (int i=offset+waveAmplitude; i>0; i-=1) {
    analogWrite(A0, i);
    delayMicroseconds(delayTime);
  }

  offsetCounter++;
}
