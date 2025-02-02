# 🚦 Simulação de Semáforo com Raspberry Pi Pico W  

Este projeto implementa um **semáforo** utilizando o microcontrolador **Raspberry Pi Pico W** e a função `add_repeating_timer_ms()` da **Pico SDK**. A cada **3 segundos**, o semáforo altera o estado dos LEDs para representar os sinais **vermelho, amarelo e verde**, seguindo um fluxo contínuo.  

## 🎯 Objetivo  
O objetivo deste projeto é demonstrar o uso de **temporizadores periódicos** para alternar estados de saída em um sistema embarcado.  

## 🛠 Componentes Utilizados  
- **Raspberry Pi Pico W**  
- **3 LEDs:** Vermelho, Amarelo e Verde  
- **3 Resistores de 330Ω**  

## 🔄 Funcionamento  
1. O sistema inicia com o **LED vermelho ligado**.  
2. Após **3 segundos**, o LED vermelho apaga e o **LED amarelo acende**.  
3. Após mais **3 segundos**, o LED amarelo apaga e o **LED verde acende**.  
4. Após mais **3 segundos**, o LED verde apaga e o ciclo reinicia no LED vermelho.  

Além disso, a cada **1 segundo**, o sistema imprime uma mensagem via **porta serial** para indicar que está rodando corretamente.  

## 🔧 Configuração e Execução  
1. **Clone este repositório**:  
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_REPOSITORIO>
2. Compile e grave o código no Raspberry Pi Pico W utilizando o SDK da Pico.
3. Conecte os LEDs conforme os pinos especificados no código.
4. Abra um terminal serial (como minicom ou PuTTY) para visualizar as mensagens.
## 💡 Expansão

Caso esteja utilizando o BitDogLab, é possível modificar o código para acionar um LED RGB nos GPIOs 11, 12 e 13 em vez dos LEDs individuais.

## Link do video

-https://www.youtube.com/shorts/ZT1EEmmuYk8
