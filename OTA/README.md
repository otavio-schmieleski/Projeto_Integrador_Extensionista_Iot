Bibliotecas
ESP8266WiFi.h: Controla a conexão Wi-Fi do ESP8266.
ArduinoOTA.h: Permite atualizações OTA do firmware.
Variáveis e Constantes
ssid e password: Credenciais da rede Wi-Fi.
local_IP, gateway, subnet: Configurações de IP fixo para a conexão Wi-Fi.
WiFiServer server(23): Objeto para o servidor Telnet, configurado na porta 23.
Funções
setup()
Inicia a Conexão Wi-Fi: Configura o modo de Wi-Fi, inicia a conexão com as credenciais e aguarda a conexão. Em caso de falha, tenta reconectar.
Configura o OTA: Define mensagens de feedback durante as atualizações OTA, como início, progresso, conclusão e possíveis erros.
Inicia o Servidor Telnet: Configura e inicializa o servidor Telnet para conexões remotas.
loop()
Gerencia o OTA: Chama ArduinoOTA.handle() para verificar se há uma nova atualização OTA disponível e processá-la.