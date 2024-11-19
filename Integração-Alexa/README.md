# Integração Alexa

## Componentes
NodeMCU (ESP8266): Microcontrolador que gerencia o sistema, conecta-se à internet e ao SinricPro para controle remoto. \n
Relé: Ativado ou desativado pelo NodeMCU para controlar dispositivos de alta tensão, como uma lâmpada. \n
Botão: Permite ligar/desligar a lâmpada manualmente. \n
Fluxo de Funcionamento:

Conexão Wi-Fi: O NodeMCU conecta-se à rede Wi-Fi configurada para acesso à internet.
SinricPro: Integração com a plataforma permite controle remoto via app ou assistentes virtuais, como Alexa.
Controle Manual: Ao pressionar o botão, o estado do relé é alternado (liga/desliga) e sincronizado com o servidor SinricPro.
Controle Remoto: Comandos enviados pelo SinricPro atualizam o estado do relé e, consequentemente, da lâmpada.