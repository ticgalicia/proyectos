Fuente:https://playground.arduino.cc/Code/CapacitiveSensor/

Sensores capacitivos nativos sin hardware adicional
Puede crear una entrada sensible al tacto en cualquiera de los pines de Arduino. No requiere hardware especial, sin embargo se recomienda un capacitor de 1nF en línea con el pin para desacoplar ruidos de 50Hz.

Conecte un cable o alguna placa metálica a un pin.


El código funciona poniendo el pin a tierra, activando la resistencia pull-up interna y midiendo el tiempo que tarda el pin en volver al estado ALTO. Si no se toca, readCapacitivePin devuelve un valor bajo, por ejemplo, "1"; cuando se toca, se eleva a aproximadamente 5. Al agregar alguna comparación con un umbral, puede convertirlo en una entrada clave booleana.

¡NO CONECTE NINGÚN CONDUCTOR ACTIVO AL PIN UTILIZADO!
el pin se cambia al modo de salida para descargar el puerto, y si está conectado a una fuente de voltaje, provocará un cortocircuito en el pin, lo que podría dañar el Arduino y cualquier hardware conectado al pin.

Historial de código
Código original de Mario Becker, Fraunhofer IGD, 2007 http://www.igd.fhg.de/igd-a4

Actualizado por: Alan Chatham http://unojoy.tumblr.com

Actualizado por Paul Stoffregen: se reemplazó el código específico '328 con portOutputRegister, etc. para compatibilidad con Arduino Mega, Teensy, Sanguino y otras placas

Optimización gratuita para mejorar la sensibilidad por Casey Rodarmor.

Actualizado por Martin Renold: deshabilite las interrupciones durante la medición. Esto corrige los resultados demasiado bajos ocasionales.

Actualizado por InvScribe para Arduino Due.

Código no debido actualizado por Gabriel Staples ( www.ElectricRCAircraftGuy.com ), 15 de noviembre de 2014: se reemplazó "interrupts();" con "SREG = SREG_antiguo;" para evitar interrupciones anidadas en caso de que utilice esta función dentro de una rutina de servicio de interrupción (ISR).

Código:
Con esta función, puede llamar a readCapacitivePin(pinNumber) y obtener un número del 0 al 17 correspondiente al nivel de capacitancia en el pin; el número será mayor cuando toque el pin.
