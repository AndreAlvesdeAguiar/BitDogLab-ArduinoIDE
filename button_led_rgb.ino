#define BUTTON_A_PIN 5   // Botão A no pino digital 5
#define BUTTON_B_PIN 6   // Botão B no pino digital 6

#define BLUE_LED_PIN 12  // LED azul no pino digital 12
#define RED_LED_PIN 13   // LED vermelho no pino digital 13
#define GREEN_LED_PIN 11 // LED verde no pino digital 11

void setup() {
  // Configuração dos botões como entrada com pull-up
  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);

  // Configuração dos LEDs RGB como saída
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // Inicialmente, desligar os LEDs
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
}

void loop() {
  // Se o botão A for pressionado
  if (digitalRead(BUTTON_A_PIN) == LOW) {
    digitalWrite(BLUE_LED_PIN, LOW);   // Desliga o LED azul
    digitalWrite(RED_LED_PIN, HIGH);  // Liga o LED vermelho
    digitalWrite(GREEN_LED_PIN, LOW); // Desliga o LED verde
  }
  // Se o botão B for pressionado
  else if (digitalRead(BUTTON_B_PIN) == LOW) {
    digitalWrite(BLUE_LED_PIN, LOW);   // Desliga o LED azul
    digitalWrite(RED_LED_PIN, LOW);   // Desliga o LED vermelho
    digitalWrite(GREEN_LED_PIN, HIGH);// Liga o LED verde
  }
  // Se nenhum botão estiver pressionado
  else {
    digitalWrite(RED_LED_PIN, LOW);   // Desliga o LED vermelho
    digitalWrite(GREEN_LED_PIN, LOW); // Desliga o LED verde
    digitalWrite(BLUE_LED_PIN, LOW);  // Desliga o LED azul
  }

  delay(10); // Pequeno atraso para evitar debounce
}
