#include <Adafruit_NeoPixel.h>

// Configuração da matriz de LEDs
#define LED_PIN 7        // Pino conectado à matriz NeoPixel
#define LED_COUNT 24     // Número total de LEDs na matriz (5x5)

// Inicializa o objeto NeoPixel
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Mapeamento da matriz 5x5 (índices dos LEDs)
const uint8_t LED_MATRIX[5][5] = {
  {24, 23, 22, 21, 20},
  {15, 16, 17, 18, 19},
  {14, 13, 12, 11, 10},
  {5,  6,  7,  8,  9},
  {4,  3,  2,  1,  0}
};

// Função para configurar o LED de uma posição específica
void setLED(uint8_t row, uint8_t col, uint8_t red, uint8_t green, uint8_t blue) {
  if (row < 5 && col < 5) { // Verifica se está dentro da matriz
    uint8_t index = LED_MATRIX[row][col];
    strip.setPixelColor(index, strip.Color(red, green, blue));
  }
}

// Função para apagar todos os LEDs
void clearAll() {
  for (uint8_t i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, 0); // Apaga o LED
  }
  strip.show(); // Atualiza a matriz
}

// Função para desenhar um coração
void drawHeart() {
  clearAll(); // Limpa a matriz antes de desenhar

  // LEDs que formam o coração
  uint8_t heartLEDs[] = {2, 6, 14, 15, 23, 17, 21, 19, 10, 8};

  // Acende os LEDs do coração em vermelho
  for (uint8_t i = 0; i < sizeof(heartLEDs); i++) {
    strip.setPixelColor(heartLEDs[i], strip.Color(255, 0, 0)); // Cor: vermelho
  }
  strip.show(); // Atualiza a matriz
}

// Função para desenhar uma seta para a direita
void drawArrowRight() {
  clearAll(); // Limpa a matriz antes de desenhar

  // LEDs que formam a seta
  uint8_t arrowLEDs[] = {2, 8, 14, 16, 18, 12, 6, 10};

  // Acende os LEDs da seta em amarelo
  for (uint8_t i = 0; i < sizeof(arrowLEDs); i++) {
    strip.setPixelColor(arrowLEDs[i], strip.Color(255, 255, 0)); // Cor: amarelo
  }
  strip.show(); // Atualiza a matriz
}

// Função para desenhar uma seta para a esquerda
void drawArrowLeft() {
  clearAll(); // Limpa a matriz antes de desenhar

  // LEDs que formam a seta
  uint8_t arrowLEDs[] = {2, 6, 12, 16, 18, 14, 10, 8};

  // Acende os LEDs da seta em verde
  for (uint8_t i = 0; i < sizeof(arrowLEDs); i++) {
    strip.setPixelColor(arrowLEDs[i], strip.Color(0, 255, 0)); // Cor: verde
  }
  strip.show(); // Atualiza a matriz
}

// Função para desenhar um padrão de "ondas" na matriz
void waveEffect() {
  for (int wave = 0; wave < 5; wave++) {
    for (int col = 0; col < 5; col++) {
      setLED(wave, col, 0, 0, 255); // Cor: azul
      strip.show();
      delay(100);
      setLED(wave, col, 0, 0, 0); // Apaga
    }
  }
}

// Função para desenhar um "X" na matriz
void drawX() {
  clearAll(); // Limpa a matriz antes de desenhar

  // LEDs que formam o "X"
  uint8_t xLEDs[] = {0, 4, 6, 8, 10, 14, 16, 18, 20, 24};

  // Acende os LEDs do "X" em branco
  for (uint8_t i = 0; i < sizeof(xLEDs); i++) {
    strip.setPixelColor(xLEDs[i], strip.Color(255, 255, 255)); // Cor: branco
  }
  strip.show(); // Atualiza a matriz
}

// Função de configuração
void setup() {
  strip.begin();           // Inicializa a matriz NeoPixel
  strip.show();            // Garante que os LEDs estão apagados no início
  strip.setBrightness(50); // Ajusta o brilho da matriz
}

// Loop principal
void loop() {
  drawHeart();       // Desenha um coração
  delay(2000);       // Espera 2 segundos

  drawArrowRight();  // Desenha uma seta para a direita
  delay(2000);       // Espera 2 segundos

  drawArrowLeft();   // Desenha uma seta para a esquerda
  delay(2000);       // Espera 2 segundos

  waveEffect();      // Executa o efeito de ondas
  delay(2000);       // Espera 2 segundos

  drawX();           // Desenha um "X"
  delay(2000);       // Espera 2 segundos

  clearAll();        // Apaga todos os LEDs
  delay(2000);       // Espera 2 segundos
}
