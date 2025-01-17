

#define BUZZER_PIN 21 // Pino do buzzer conectado ao Arduino

void setup() {
  // Configura o pino do buzzer como saída
  pinMode(BUZZER_PIN, OUTPUT);
}

void beep(int frequency, int duration_ms) {
  // Gera o tom no buzzer com a frequência e duração especificadas
  tone(BUZZER_PIN, frequency, duration_ms);

  // Aguarda o término da duração do beep
  delay(duration_ms);

  // Desliga o tom após o beep
  noTone(BUZZER_PIN);

  // Pausa entre os beeps
  delay(100); // Pausa de 100ms
}

void loop() {
  // Emite um beep de 500ms com frequência de 100Hz
  beep(100, 500);
}
