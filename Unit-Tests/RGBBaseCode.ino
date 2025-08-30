#define LED_PIN 5  // Cambia este número según el pin donde conectaste el LED

void setup() {
    pinMode(LED_PIN, OUTPUT); // Configurar el pin como salida
}

void loop() {
    digitalWrite(LED_PIN, HIGH); // Enciende el LED
    delay(1000);                 // Espera 1 segundo
    digitalWrite(LED_PIN, LOW);  // Apaga el LED
    delay(1000);                 // Espera 1 segundo
}
