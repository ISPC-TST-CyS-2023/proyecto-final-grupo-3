const int led = 4; 
const int button = 14;

void setup() {
  // inicializa el pin digital 4 como salida.
  pinMode(led, OUTPUT);
  // inicializa el pin digital 14 como entrada 
  // con resitencia de pull-up habilitada.
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // lee el valor del pulsador (sin presionar HIGH, presionado LOW)
  int value = digitalRead(button);
  // escribe el valor leído en el led
  digitalWrite(led, value);
}
