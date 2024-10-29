# OTA - Over the Air

## Bibliotecas <br>
* ESP8266WiFi.h: Controla a conexão Wi-Fi do ESP8266. <br>
* ArduinoOTA.h: Permite atualizações OTA do firmware. <br>
## Variáveis e Constantes <br>
* ssid e password: Credenciais da rede Wi-Fi. <br>
* local_IP, gateway, subnet: Configurações de IP fixo para a conexão Wi-Fi. <br>
* WiFiServer server(23): Objeto para o servidor Telnet, configurado na porta 23. <br>
## Funções <br>
* setup() <br>
* Inicia a Conexão Wi-Fi: Configura o modo de Wi-Fi, inicia a conexão com as credenciais e aguarda a conexão. Em caso de falha, tenta reconectar. <br>
* Configura o OTA: Define mensagens de feedback durante as atualizações OTA, como início, progresso, conclusão e possíveis erros. <br>
* Inicia o Servidor Telnet: Configura e inicializa o servidor Telnet para conexões remotas. <br>
## loop() <br>
* Gerencia o OTA : Chama ArduinoOTA.handle() para verificar se há uma nova atualização OTA disponível e processá-la.
