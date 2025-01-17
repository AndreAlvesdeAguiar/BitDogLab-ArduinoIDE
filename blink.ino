// Definição dos pinos conectados ao LED RGB
#define LEDR 12 // Pino para o LED vermelho
#define LEDG 11 // Pino para o LED verde
#define LEDB 13 // Pino para o LED azul

// Função para definir o estado das cores do LED RGB
void led_rgb_put(bool r, bool g, bool b) {
  digitalWrite(LEDR, r);
  digitalWrite(LEDG, g);
  digitalWrite(LEDB, b);
}

void setup() {
  // Configura os pinos como saída
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // Inicializa os LEDs desligados
  led_rgb_put(false, false, false);
}

void loop() {
  // Liga apenas o vermelho
  led_rgb_put(true, false, false);
  delay(500);

  // Liga apenas o verde
  led_rgb_put(false, true, false);
  delay(500);

  // Liga apenas o azul
  led_rgb_put(false, false, true);
  delay(500);

  // Liga todas as cores (branco)
  led_rgb_put(true, true, true);
  delay(500);
}
