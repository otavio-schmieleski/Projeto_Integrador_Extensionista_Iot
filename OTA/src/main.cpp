#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "ssid";
const char* password = "password";

IPAddress local_IP(192, 168, 1, 184); // Definindo um IP fixo
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WiFiServer server(23); // Declara o servidor Telnet na porta 23

void setup() {

  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Aguarda conexão Wi-Fi
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Conexão falhou, tentando novamente...");
    WiFi.begin(ssid, password);
    delay(5000);
  }

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
    if (error == OTA_AUTH_ERROR) Serial.println("Falha na autenticação");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Falha no início");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Falha na conexão");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Falha no recebimento");
    else if (error == OTA_END_ERROR) Serial.println("Falha no finalização");
  });

  ArduinoOTA.begin();
  Serial.println("Pronto para atualizações OTA.");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Inicializa o servidor Telnet
  server.begin();
  server.setNoDelay(true);
  Serial.println("Servidor Telnet iniciado...");
}

void loop() {

  ArduinoOTA.handle();

}
