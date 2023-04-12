Fuente: https://blog.eikeland.se/2015/04/24/banana-piano/

Piano banana táctil capacitivo en Clojure/Overtone.

Fabricación de un piano banana, con un poco de jazz sueco de mi compañero de trabajo Håvard Sørbø
Este fin de semana mi sobrina se queda a dormir, y para mantener mi imagen de tío científico loco he planeado hacer un piano de plátano (y muchos helados raros). En clojure hay un entorno de audio programable muy bueno llamado Overtone . Overtone presenta un piano muestreado decente, y creo que esto podría ser una gran base para un piano-banana.

Dato curioso: un piano completo requiere alrededor de 11 kg de plátanos, a $ 3 por kg, que sigue siendo mucho más barato (y más liviano) que un Steinway.

Hay un par de formas en que podemos hacer que las bananas actúen como tangentes, una de ellas es usar las bananas como sensores táctiles capacitivos. Usando un pequeño y agradable truco, es posible hacer esto usando pines digitales regulares en un microcontrolador. El truco es (afaik) originalmente de Mario Becker, Fraunhofer IGD, 2007 (sitio web muerto). Consulte el artículo sobre sensores capacitivos en arduino.cc .

Engancha un alfiler a algo.
Deshabilitar interrupciones.
Establecer pin como entrada.
Pull-up activo en el pasador.
Cuente los ciclos hasta que el pin esté alto.
Habilitar interrupciones
Establecer pin como salida, bajo.
El número de ciclos necesarios antes de que el pin suba dependerá de la capacitancia de lo que esté conectado al pin. Una banana puede requerir 8 ciclos antes de que el pin suba, mientras que una banana tocada puede requerir 15.

Podemos conectar una cantidad de bananas a un microcontrolador, iterar sobre las bananas, leer su cuenta de ciclos antes de que el pin de banana suba y luego transmitir un mensaje a través de una conexión en serie que indique el número de pin si esta cuenta de ciclos está por encima de un umbral determinado.

const int PORTS[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
const int THRESHOLDS[8] = { 13, 13, 13, 13, 13, 13, 13, 13 };

bool touched[8];

uint8_t readCapacitivePin(int pinToMeasure) {
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  byte bitmask;

  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));

  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);

  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();

  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;

  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.

  uint8_t cycles = 17;
       if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}

  // End of timing-critical section
  interrupts();

  // Discharge the pin again by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}

void setup() {
  Serial.begin(57600);
}

void handlePort(int index) {
  int cycles = readCapacitivePin(PORTS[index]);

  if (!touched[index] && cycles >= THRESHOLDS[index]) {
    touched[index] = true;
    Serial.print(index);
  }

  if (touched[index] && cycles < THRESHOLDS[index]) {
    touched[index] = false;
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    handlePort(i);
  }
  delay(30); // cheap-ass debounce..
}
Su computadora debe estar conectada a tierra para que esto funcione de manera confiable, y también ayuda agregar un plano de tierra debajo de los plátanos (ver video).

Al tocar un plátano, el microcontrolador transmitirá un carácter del 0 al 7, luego podemos recibir este valor en clojure usando una biblioteca de puerto serie, convertirlo en un int, asignar el valor a una escala para obtener una nota. Y toca esto usando un instrumento, en este caso, el excelente piano muestreado disponible en Overtone.

(ns musikk.core
  (:require [serial-port :as serial]
            [overtone.live :refer :all]
            [overtone.inst.sampled-piano :refer :all]))

(def port (serial/open "/dev/tty.usbserial-A800F185" 57600))

(defn chr->int [c]
  (-> (char c)
      (str)
      (Integer.)))

(defn banana-touch [input]
  (let [index    (chr->int input)
        my-scale (scale :C4 :major)
        note     (nth my-scale index)]
    (sampled-piano :note note :sustain 0.2)))

(serial/on-byte port banana-touch)
Ahora disfruta y experimenta con escalas y diferentes instrumentos en Overtone - tus esfuerzos no serán en vano. Tal vez haga un theremin de brócoli la próxima vez que mi sobrina me visite. :)

Actualizar:
Ya que algunas personas han preguntado, aquí hay un diagrama de cableado. Es súper fácil, solo cables y sin componentes adicionales. El plano de tierra (lámina de aluminio) es opcional. Si tiene problemas en entornos muy ruidosos, puede colocar un condensador de 1 nF en línea con el plátano. Usé un arduino nano , pero se puede usar cualquier arduino basado en atmega328 (nano, uno, etc.). (Y probablemente todos los demás con modificaciones menores). Cualquier cable que pueda conectar a un plátano y un arduino funciona. Mi arduino tenía encabezados macho, usé cables hembra-hembra de 4p dupont, que rompí en 1p macho-macho para cada banana individual. Estos vienen en todas las formas, géneros y longitudes en eBay por muy poco dinero.

Bibliotecas de Clojure utilizadas: [serial-port "1.1.2"]y[overtone "0.9.1"]
