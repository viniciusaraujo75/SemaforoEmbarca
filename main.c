#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

volatile int estado = 0; // 0: vermelho, 1: amarelo, 2: verde

bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    
    // Ativa o LED correspondente ao estado atual
    switch (estado) {
        case 0:
            gpio_put(LED_VERMELHO, 1);
            break;
        case 1:
            gpio_put(LED_AMARELO, 1);
            break;
        case 2:
            gpio_put(LED_VERDE, 1);
            break;
    }
    
    estado = (estado + 1) % 3; // Alterna entre 0, 1 e 2
    return true; // Mantém o timer repetindo
}

int main() {

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (true) {
        printf("Semáforo rodando... Estado atual: %d\n", estado);
        sleep_ms(1000);
    }
}
