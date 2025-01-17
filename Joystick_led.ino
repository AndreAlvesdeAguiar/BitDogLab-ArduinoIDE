#include <Arduino.h>

// Definição dos pinos usados para o joystick e LEDs
const int VRX = A0; // Pino de leitura do eixo X do joystick (conectado ao ADC)
const int VRY = A1; // Pino de leitura do eixo Y do joystick (conectado ao ADC)
const int SW = 22;  // Pino de leitura do botão do joystick

const int LED_B = 13; // Pino para controle do LED azul via PWM
const int LED_R = 11; // Pino para controle do LED vermelho via PWM

// Variáveis para armazenar valores lidos do joystick
int vrxValue = 0, vryValue = 0;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Configura os pinos do joystick
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Configura os pinos dos LEDs
  pinMode(LED_B, OUTPUT);
  pinMode(LED_R, OUTPUT);

  // Mensagem inicial no monitor serial
  Serial.println("Joystick e Controle PWM Inicializado!");
}

void loop() {
  // Lê os valores do joystick
  vrxValue = analogRead(VRX); // Valor do eixo X (0-1023)
  vryValue = analogRead(VRY); // Valor do eixo Y (0-1023)

  // Ajusta o brilho dos LEDs de acordo com os valores do joystick
  analogWrite(LED_B, map(vrxValue, 0, 1023, 0, 255)); // Mapeia para PWM do LED azul
  analogWrite(LED_R, map(vryValue, 0, 1023, 0, 255)); // Mapeia para PWM do LED vermelho

  // Exibe os valores no monitor serial
  Serial.print("VRX: ");
  Serial.print(vrxValue);
  Serial.print(" | VRY: ");
  Serial.println(vryValue);

  // Verifica o botão do joystick
  if (digitalRead(SW) == LOW) {
    Serial.println("Botão pressionado!");
    delay(200); // Debounce
  }

  delay(100); // Aguarda antes de atualizar
}
