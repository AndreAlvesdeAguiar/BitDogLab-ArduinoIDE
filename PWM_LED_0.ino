#define LED_PIN 12            // Pino do LED conectado
#define LED_STEP 25           // Passo de incremento/decremento para o duty cycle do LED
#define MAX_BRIGHTNESS 255    // Valor máximo do PWM (8 bits)
#define MIN_BRIGHTNESS 0      // Valor mínimo do PWM (apagado)

// Variáveis globais
int ledBrightness = 0;        // Nível inicial do PWM (duty cycle)
bool increasing = true;       // Direção do ajuste de brilho (subindo ou descendo)

void setup() {
  pinMode(LED_PIN, OUTPUT);   // Configura o pino do LED como saída
}

void loop() {
  analogWrite(LED_PIN, ledBrightness); // Define o nível atual do PWM (duty cycle)
  delay(100);                          // Aguarda 100 ms para criar o efeito de fade

  if (increasing) {
    ledBrightness += LED_STEP;         // Incrementa o nível do LED
    if (ledBrightness >= MAX_BRIGHTNESS) {
      increasing = false;              // Muda direção para diminuir
    }
  } else {
    ledBrightness -= LED_STEP;         // Decrementa o nível do LED
    if (ledBrightness <= MIN_BRIGHTNESS) {
      increasing = true;               // Muda direção para aumentar
    }
  }
}
