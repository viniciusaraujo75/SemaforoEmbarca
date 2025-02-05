# Projeto Semáforo com LED RGB - Raspberry Pi Pico W

Este projeto simula um semáforo utilizando um LED RGB e o Raspberry Pi Pico W. A cada 3 segundos, o semáforo muda entre as cores **vermelho**, **amarelo** e **verde**.

## Componentes

- **Raspberry Pi Pico W**
- **LED RGB** (pinos GPIO 11, 12 e 13)
- **Resistores de 330 Ω**

## Como Funciona

1. O semáforo começa com o **LED vermelho** aceso.
2. Depois de 3 segundos, ele muda para **LED amarelo** (vermelho + verde).
3. Após mais 3 segundos, ele muda para **LED verde**.
4. Esse ciclo se repete.

## Como Usar

1. **Clonar o repositório**:
2. **Abrir o projeto no VS Code**.
3. **Simular no Wokwi Online pra pegar o diagram.json**:
- Crie um novo projeto de **Raspberry Pi Pico W**.
- Conecte os LEDS nos pinos GPIO 11, 12 e 13.
- Copie e cole o código no editor do Wokwi.
4. **Simule o semáforo**.

## Observação

- não usar a função set_init_all() no Wokwi online.