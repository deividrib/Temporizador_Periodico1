#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 13  // GPIO para o LED vermelho
#define LED_AMARELO 12   // GPIO para o LED amarelo
#define LED_VERDE 11     // GPIO para o LED verde

int estado_atual = 0;

// Função de callback do temporizador (troca o estado do semáforo)
bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    switch (estado_atual) {
        case 0:
            gpio_put(LED_VERMELHO, 1);
            printf("Semáforo: VERMELHO\n");
            break;
        case 1:
            gpio_put(LED_AMARELO, 1);
            printf("Semáforo: AMARELO\n");
            break;
        case 2:
            gpio_put(LED_VERDE, 1);
            printf("Semáforo: VERDE\n");
            break;
    }

    fflush(stdout);  
    estado_atual = (estado_atual + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();
    sleep_ms(5000);  // Aumenta o tempo para garantir que a USB UART esteja pronta

    printf("Inicializando semáforo...\n");
    fflush(stdout);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_put(LED_VERMELHO, 1);
    printf("Sistema iniciado. Semáforo começa no vermelho.\n");
    fflush(stdout);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Sistema rodando... Próxima troca de sinal em 3 segundos.\n");
        fflush(stdout);
        sleep_ms(1000);
    }
}
