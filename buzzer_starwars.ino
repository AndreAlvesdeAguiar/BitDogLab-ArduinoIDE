/**
 * Exemplo de acionamento do buzzer utilizando sinal PWM
 * Adaptado para Arduino IDE
 * 06/12/2024
 */

#define BUZZER_PIN 21 // Pino do buzzer conectado ao Arduino

// Notas musicais para a música tema de Star Wars
const uint16_t star_wars_notes[] = {
    330, 330, 330, 262, 392, 523, 330, 262,
    392, 523, 330, 659, 659, 659, 698, 523,
    415, 349, 330, 262, 392, 523, 330, 262,
    392, 523, 330, 659, 659, 659, 698, 523,
    415, 349, 330, 523, 494, 440, 392, 330,
    659, 784, 659, 523, 494, 440, 392, 330,
    659, 659, 330, 784, 880, 698, 784, 659,
    523, 494, 440, 392, 659, 784, 659, 523,
    494, 440, 392, 330, 659, 523, 659, 262,
    330, 294, 247, 262, 220, 262, 330, 262,
    330, 294, 247, 262, 330, 392, 523, 440,
    349, 330, 659, 784, 659, 523, 494, 440,
    392, 659, 784, 659, 523, 494, 440, 392
};

// Duração das notas em milissegundos
const uint16_t note_duration[] = {
    500, 500, 500, 350, 150, 300, 500, 350,
    150, 300, 500, 500, 500, 500, 350, 150,
    300, 500, 500, 350, 150, 300, 500, 350,
    150, 300, 650, 500, 150, 300, 500, 350,
    150, 300, 500, 150, 300, 500, 350, 150,
    300, 650, 500, 350, 150, 300, 500, 350,
    150, 300, 500, 500, 500, 500, 350, 150,
    300, 500, 500, 350, 150, 300, 500, 350,
    150, 300, 500, 350, 150, 300, 500, 500,
    350, 150, 300, 500, 500, 350, 150, 300,
};

// Toca uma nota com a frequência e duração especificadas
void play_tone(uint16_t frequency, uint16_t duration_ms) {
    if (frequency > 0) {
        tone(BUZZER_PIN, frequency, duration_ms); // Emite o som
    }
    delay(duration_ms + 50); // Pausa entre as notas
}

// Função principal para tocar a música
void play_star_wars() {
    for (int i = 0; i < sizeof(star_wars_notes) / sizeof(star_wars_notes[0]); i++) {
        play_tone(star_wars_notes[i], note_duration[i]);
    }
}

void setup() {
    // Configura o pino do buzzer como saída
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    // Toca a música tema de Star Wars em loop
    play_star_wars();
    delay(2000); // Pausa entre as repetições da música
}
