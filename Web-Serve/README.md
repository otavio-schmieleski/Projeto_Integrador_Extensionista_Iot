# Documentação do Código ESP8266 com Web Server

## Resumo
Este código configura um ESP8266 para conectar-se a uma rede Wi-Fi com um IP fixo e inicia um servidor Web na porta 80. O servidor permite que o usuário ligue e desligue um LED através de uma interface web.

## Bibliotecas
- **ESP8266WiFi.h**: Controla a conexão Wi-Fi do ESP8266.
- **ESP8266WebServer.h**: Permite configurar e gerenciar um servidor Web no ESP8266.

## Variáveis e Constantes
- `ssid` e `password`: Credenciais da rede Wi-Fi.
- `output5`: Pino onde o LED está conectado (pino D1).
- `local_IP`, `gateway`, `subnet`: Configurações de IP fixo para a conexão Wi-Fi.
- `ESP8266WebServer server(80)`: Objeto para o servidor Web, configurado na porta 80.

## Funções

### `handleRoot()`
- Cria uma página HTML simples com botões para ligar e desligar o LED.
- Define os estilos dos botões e um script JavaScript que envia requisições HTTP para controlar o LED.

### `handleOn()`
- Liga o LED configurando o pino `output5` para HIGH.
- Envia uma resposta em texto ("LED Ligado!") para o cliente.

### `handleOff()`
- Desliga o LED configurando o pino `output5` para LOW.
- Envia uma resposta em texto ("LED Desligado!") para o cliente.

## Função `setup()`
1. **Configura o Pino do LED**: Define o pino `output5` como saída e inicia o LED desligado.
2. **Configura o Wi-Fi com IP Fixo**: Define o IP fixo, gateway e subnet. Conecta à rede com as credenciais `ssid` e `password`.
3. **Inicia o Servidor Web**: Define as rotas do servidor para os URLs:
   - `/`: Rota principal para exibir a interface de controle do LED.
   - `/5/on`: Liga o LED.
   - `/5/off`: Desliga o LED.

## Função `loop()`
- **Gerencia as Requisições Web**: Chama `server.handleClient()` para processar as requisições HTTP recebidas pelo servidor Web.

## Exemplo de Uso
- Acesse o endereço IP do ESP8266 na rede (exibido no Serial Monitor) usando um navegador.
- Na interface Web, clique nos botões:
  - **ON** para ligar o LED.
  - **OFF** para desligar o LED.
