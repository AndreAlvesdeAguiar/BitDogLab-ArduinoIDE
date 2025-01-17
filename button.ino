/**
 * Embarcatech 
 * Exemplo Botão com a BitDogLab (Adaptado para Arduino IDE)
 */

#define LED_BLUE 12   // Pino conectado ao terminal azul do LED RGB
#define BUTTON_A 5    // Pino conectado ao Botão A

void setup() {
  // Configuração do pino do LED como saída
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, LOW); // Inicialmente, o LED está apagado

  // Configuração do pino do botão como entrada com pull-up interno
  pinMode(BUTTON_A, INPUT_PULLUP);
}

void loop() {
  // Lê o estado do Botão A
  bool button_a_state = digitalRead(BUTTON_A); // HIGH = solto, LOW = pressionado

  // Atualiza o estado do LED com base no estado do Botão A
  digitalWrite(LED_BLUE, !button_a_state); // Se solto (HIGH), LED acende; se pressionado (LOW), apaga

  // Pequeno delay para evitar leituras inconsistentes (debounce simples)
  delay(50);
}
