<<<<<<<<<<<FALTA DE COMPATIBILIDADE SSD1306>>>>>>>>>>>>>>>>>>


#include <Arduino.h>

// Definição dos pinos utilizados
const uint8_t BUZZER_A = 9; // Pino para o buzzer A
const uint8_t BUZZER_B = 10; // Pino para o buzzer B
const uint8_t BUTTON_A = 5;  // Pino para o botão A
const uint8_t BUTTON_B = 6;  // Pino para o botão B
const uint8_t LED = 11;      // Pino para o LED

// Constantes para controle de brilho do LED e buzzer
const uint8_t LED_STEP = 25; // Passo para controle de brilho do LED
const uint8_t MAX_BRIGHTNESS = 255; // Brilho máximo
const uint8_t MIN_BRIGHTNESS = 0;   // Brilho mínimo
uint8_t led_brightness = 128;       // Nível inicial de brilho do LED

// Função para tocar uma nota no buzzer
void playTone(uint8_t pin, uint16_t frequency, uint16_t duration) {
  tone(pin, frequency, duration);
  delay(duration);
  noTone(pin);
}

// Função para tocar uma música no buzzer
void playSong(uint8_t pin) {
  const uint16_t melody[] = {440, 494, 523, 440, 0, 494, 440}; // Notas em Hz
  const uint16_t durations[] = {500, 500, 500, 500, 250, 500, 500}; // Durações em ms
  
  for (size_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    if (melody[i] == 0) {
      noTone(pin);
    } else {
      playTone(pin, melody[i], durations[i]);
    }
    delay(50); // Pequena pausa entre as notas
  }
}

// Função de configuração inicial
void setup() {
  Serial.begin(9600);

  // Configura os pinos do LED e dos botões
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);

  // Configura os pinos dos buzzers
  pinMode(BUZZER_A, OUTPUT);
  pinMode(BUZZER_B, OUTPUT);

  // Mensagem inicial
  Serial.println("Sistema inicializado!");
}

// Função principal (loop)
void loop() {
  // Verifica se o botão A foi pressionado
  if (digitalRead(BUTTON_A) == LOW) {
    Serial.println("Botão A pressionado. Aumentando brilho.");
    if (led_brightness < MAX_BRIGHTNESS) {
      led_brightness += LED_STEP; // Aumenta o brilho do LED
    }
    analogWrite(LED, led_brightness); // Aplica o novo nível de brilho
    delay(200); // Debounce
  }

  // Verifica se o botão B foi pressionado
  if (digitalRead(BUTTON_B) == LOW) {
    Serial.println("Botão B pressionado. Diminuindo brilho.");
    if (led_brightness > MIN_BRIGHTNESS) {
      led_brightness -= LED_STEP; // Diminui o brilho do LED
    }
    analogWrite(LED, led_brightness); // Aplica o novo nível de brilho
    delay(200); // Debounce
  }

  // Toca a música no buzzer A
  playSong(BUZZER_A);
  delay(2000); // Intervalo entre repetições
}
