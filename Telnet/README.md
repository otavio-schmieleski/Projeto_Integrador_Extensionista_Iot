# Documentação do Código ESP8266

## Resumo
Este código conecta um ESP8266 a uma rede Wi-Fi, habilita a atualização de firmware Over-the-Air (OTA) e inicia um servidor Telnet na porta 23 para controlar um LED.

## Bibliotecas
- **ESP8266WiFi.h**: Controla a conexão Wi-Fi do ESP8266.
- **ArduinoOTA.h**: Permite atualizações OTA do firmware.

## Variáveis e Constantes
- `ssid` e `password`: Credenciais da rede Wi-Fi.
- `LED_PIN`: Pino de controle do LED (pino D1).
- `WiFiServer server(23)`: Objeto para o servidor Telnet, configurado na porta 23.
- `WiFiClient client`: Objeto para gerenciar o cliente Telnet.

## Funções

### `setup()`
1. **Configura Wi-Fi**: Conecta o ESP8266 à rede usando o nome e senha definidos em `ssid` e `password`. Tenta novamente em caso de falha.
2. **Configura o OTA**: Define mensagens de feedback para acompanhar o status da atualização OTA (início, progresso, erros e conclusão).
3. **Inicia o Servidor Telnet**: Configura e inicia o servidor Telnet na porta 23, permitindo controle remoto do LED.

### `loop()`
- **Gerencia o OTA**: Chama `ArduinoOTA.handle()` para verificar e processar atualizações OTA.
- **Controle do LED pelo Telnet**: Verifica se o cliente Telnet envia comandos. Se o cliente digitar:
  - `'1'`: O LED liga.
  - `'0'`: O LED desliga.
  
## Exemplo de Uso
- Ao se conectar ao servidor Telnet, o cliente recebe as instruções:
  - Digite `'1'` para ligar o LED.
  - Digite `'0'` para desligar o LED.
  
---  
