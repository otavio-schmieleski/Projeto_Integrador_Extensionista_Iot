# Integração Alexa

## Componentes
NodeMCU (ESP8266): Microcontrolador que gerencia o sistema, conecta-se à internet e ao SinricPro para controle remoto. <br>
Relé: Ativado ou desativado pelo NodeMCU para controlar dispositivos de alta tensão, como uma lâmpada. <br>
Botão: Permite ligar/desligar a lâmpada manualmente. <br>

## Fluxo de Funcionamento
Conexão Wi-Fi: O NodeMCU conecta-se à rede Wi-Fi configurada para acesso à internet. <br>
SinricPro: Integração com a plataforma permite controle remoto via app ou assistentes virtuais, como Alexa. <br>
Controle Manual: Ao pressionar o botão, o estado do relé é alternado (liga/desliga) e sincronizado com o servidor SinricPro. <br>
Controle Remoto: Comandos enviados pelo SinricPro atualizam o estado do relé e, consequentemente, da lâmpada.<br>

## Arquitetura do Projeto
![integracao-alexa](https://github.com/user-attachments/assets/9f8712ee-7845-42f9-96b7-feb5576641aa)



## Video da Integração com a Alexa em funcionamento
https://github.com/user-attachments/assets/a3111bd8-044c-4733-96a3-0b37862b0f87


