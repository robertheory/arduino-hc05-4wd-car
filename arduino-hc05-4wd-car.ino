#define L1 7
#define L2 6
#define R1 5
#define R2 4

char buf;

void setup()
{

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
    buf = Serial.read();

    Serial.print(buf);

    if (buf == 'F')
    {
      forward();
    } else if (buf == 'B')
    {
      backward();
    } else if (buf == 'R')
    {
      right();
    } else if (buf == 'L')
    {
      left();
    } else {
      stop();
    }


  }

}


void forward() {
  digitalWrite(L1, HIGH);
  digitalWrite(R1, LOW);

  digitalWrite(L2, HIGH);
  digitalWrite(R2, LOW);
}

void backward() {
  digitalWrite(L1, LOW);
  digitalWrite(R1, HIGH);

  digitalWrite(L2, LOW);
  digitalWrite(R2, HIGH);
}

void stop() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}

void left() {
  digitalWrite(L1, LOW);
  digitalWrite(R1, HIGH);

  digitalWrite(L2, HIGH);
  digitalWrite(R2, LOW);
}

void right() {
  digitalWrite(L1, HIGH);
  digitalWrite(R1, LOW);

  digitalWrite(L2, LOW);
  digitalWrite(R2, HIGH);
}