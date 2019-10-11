
int statusLed = 0;

// Pino do arduino ligado ao A0 do sensor(analogico)
int pino_a_reservatorio = A5;
int pino_a_umidade = A4;

// variavel que guarda valor do pino analogico no arduino(do sensor)
int valorares = 0;
int valoraumi = 0;

// Portas ligadas ao motor
int pino_bomba = 13;


// Variavel tempo regando
int regando = 2000;
int dado = 0;
void setup()
{
  // Pino como entrada
  pinMode(pino_a_reservatorio, INPUT);
  pinMode(pino_a_umidade, INPUT);
  // Pino ligando a bomba
  pinMode(pino_bomba, OUTPUT);
  //monitorar dados
  Serial.begin(9600);
    digitalWrite(pino_bomba, LOW);
}

void loop()
{
  //Recebe e guarda o valor do pino analogico
  valorares = analogRead(pino_a_reservatorio);
  valoraumi = analogRead(pino_a_umidade);
  //Envia as informacoes para o monitor
  Serial.print("Valor do reservatorio : ");
  Serial.println(valorares);
  Serial.print("Valor do solo : ");
  Serial.println(valoraumi);
  

   
  // Horario ou antihorario
  while(dado == 0)
{  
  if ( valorares < 500 && valoraumi > 400 && valoraumi < 800)
  {
    digitalWrite(pino_bomba, HIGH);
    delay(2000);
    digitalWrite(pino_bomba, LOW);
  }
  if ( valorares < 500 && valoraumi > 800)
  {
    digitalWrite(pino_bomba, HIGH);
    delay(5000);
    digitalWrite(pino_bomba, LOW);
  }
}
  delay(5000);

   if (Serial.available() > 0){
    statusLed = Serial.read();
    if(statusLed == '0'){
      digitalWrite(pino_bomba, LOW);
    }else if (statusLed == '1'){
      digitalWrite(pino_bomba, HIGH);

    } }
  }
