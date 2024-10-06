#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN PB1           // Pinul pentru LED (PIN 9 este PB1 pe ATmega)
#define BUTON_TOGGLE_PIN PD3  // Pinul pentru butonul cu retinere (PD3 este pin 3 pe ATmega)
#define BUTON_MOM_PIN PD2     // Pinul pentru butonul fara retinere (PD2 este pin 2 pe ATmega)

// Functia de initializare
void init() {
	// Seteaza LED_PIN ca iesire
	DDRB |= (1 << LED_PIN);
	
	// Seteaza BUTON_TOGGLE_PIN si BUTON_MOM_PIN ca intrari
	DDRD &= ~((1 << BUTON_TOGGLE_PIN) | (1 << BUTON_MOM_PIN));

	// Activeaza rezistentele interne de pull-up pentru butoane
	PORTD |= (1 << BUTON_TOGGLE_PIN) | (1 << BUTON_MOM_PIN);
}

// Functia de a scrie PWM pe LED
void pwm_write(uint8_t value) {
	// Timer 1 (16-bit) configurat pentru PWM
	TCCR1A |= (1 << WGM10) | (1 << WGM12) | (1 << COM1A1);  // Fast PWM, non-inverting
	TCCR1B |= (1 << CS11);  // Prescaler 8
	OCR1A = value;          // Seteaza valoarea PWM
}

int main(void) {
	init();  // Initializare

	while (1) {
		// Citeste starea butonului cu retinere
		if (!(PIND & (1 << BUTON_TOGGLE_PIN))) {  // BUTON_TOGGLE_PIN LOW
			pwm_write(40);  // LED la 15% intensitate
			// Verifica butonul fara retinere
			while (!(PIND & (1 << BUTON_MOM_PIN)));  // Asteapta pâna butonul este apasat
			pwm_write(255);  // LED la 100% intensitate
			while (!(PIND & (1 << BUTON_MOM_PIN)));  // Asteapta pâna butonul este eliberat
			} else {
			pwm_write(0);  // LED-ul este stins
		}
	}
}
