#include <ESP8266WiFi.h>     // Biblioteca para conectar o ESP8266 ao Wi-Fi
#include <ArduinoOTA.h>      // Biblioteca para atualizações do código via OTA (Over-the-Air)

const char* ssid = "ssid";   // Nome da rede Wi-Fi
const char* password = "password";   // Senha da rede Wi-Fi

IPAddress local_IP(192, 168, 1, 184); // Configuração do IP fixo
IPAddress gateway(192, 168, 1, 1);    // IP do roteador
IPAddress subnet(255, 255, 255, 0);   // Máscara de rede

WiFiServer server(23); // Configura o servidor Telnet na porta 23

void setup() {
  Serial.begin(9600);    // Inicia a comunicação serial
  WiFi.mode(WIFI_STA);   // Configura o ESP8266 como cliente Wi-Fi
  WiFi.begin(ssid, password); // Conecta na rede Wi-Fi

  // Espera pela conexão ao Wi-Fi
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Conexão falhou, tentando novamente...");
    WiFi.begin(ssid, password);  // Tenta conectar novamente
    delay(5000);                 // Espera 5 segundos antes de tentar de novo
  }

  // Configura o que acontece durante a atualização OTA
  ArduinoOTA.onStart([]() {
    Serial.println("Iniciando atualização OTA...");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nAtualização concluída.");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progresso: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Erro[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Erro de autenticação");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Erro ao iniciar");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Erro de conexão");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Erro ao receber");
    else if (error == OTA_END_ERROR) Serial.println("Erro ao finalizar");
  });

  ArduinoOTA.begin();             // Inicia o OTA
  Serial.println("Pronto para atualizações OTA.");
  Serial.print("Endereço IP: ");  
  Serial.println(WiFi.localIP()); // Mostra o endereço IP do ESP8266

  // Inicia o servidor Telnet
  server.begin();
  server.setNoDelay(true);        // Configura o servidor para não ter atrasos
  Serial.println("Servidor Telnet iniciado...");
}

void loop() {
  ArduinoOTA.handle();   // Verifica se tem atualização OTA disponível
}
