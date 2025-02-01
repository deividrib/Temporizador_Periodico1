#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 20 // GPIO para o LED vermelho
#define LED_AMARELO 19  // GPIO para o LED amarelo
#define LED_VERDE 18     // GPIO para o LED verde

// Variável para armazenar o estado atual do semáforo
int estado_atual = 0;

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desligar todos os LEDs
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    
    // Alternar entre os estados do semáforo
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
    
    // Atualizar estado
    estado_atual = (estado_atual + 1) % 3;
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    
    // Configuração dos pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    // Inicializar o semáforo no vermelho
    gpio_put(LED_VERMELHO, 1);
    printf("Sistema iniciado. Semáforo começa no vermelho.\n");
    
    // Criar o temporizador periódico de 3 segundos (3000ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    // Loop principal (executa mensagens a cada 1 segundo)
    while (true) {
        printf("Sistema rodando...\n");
        sleep_ms(1000);
    }
}
