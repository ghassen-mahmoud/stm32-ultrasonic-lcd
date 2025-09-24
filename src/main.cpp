#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- LCD (adresse I2C souvent 0x27 ou 0x3F) ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Définition des broches ---
#define TRIG_PIN PA0
#define ECHO_PIN PA1

void setup() {
  // Initialisation LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("HC-SR04 + LCD");

  // Initialisation des broches
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialisation du port série
  Serial.begin(115200);
  delay(1000);
  Serial.println("Capteur Ultrason HC-SR04 - STM32 Nucleo F411RE");
}

void loop() {
  // --- Générer impulsion TRIG de 10µs ---
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // --- Mesurer durée de l’impulsion ECHO ---
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout = 30ms (~5m)

  // --- Calcul distance ---
  float distance = (duration * 0.0343) / 2.0;

  // --- Affichage ---
  lcd.clear();
  lcd.setCursor(0, 0);
  if (duration == 0) {
    lcd.print("No Signal");
    Serial.println("Pas de signal (objet trop loin ou capteur mal cablé)");
  } else {
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm");

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(100); // 0.5s avant prochaine mesure
}
