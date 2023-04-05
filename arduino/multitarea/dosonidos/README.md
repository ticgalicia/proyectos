Tom nos dijo que un Arduino solo puede generar un solo tono a la vez. Dijo que no era posible generar dos tonos simultáneos al mismo tiempo y que los intentos de alternar entre ellos daban como resultado una calidad de sonido muy mala.

En clase también habló sobre servos y cómo funcionaba el código de servo de Arduino. Su explicación me sugirió que debería haber una forma de generar dos lanzamientos simultáneos. Todas mis ideas iniciales para hacer esto que pensé durante la clase fueron fallas, pero aprendí mucho sobre Arduinos en el proceso de probar cosas. Estaba intrigado por la generación de sonido y me quedé con él. Finalmente se me ocurrió una idea viable. Ahora afirmo que puedo crear un circuito que genera dos tonos simultáneos adecuados. Hay algunas limitaciones, pero definitivamente hace lo que digo que hace.

Rápidamente me di cuenta de que la única forma en que esto podría funcionar es con una verdadera salida analógica. La analogWritefunción de Arduino utiliza modulación de ancho de pulso (PWM). Esta función hará oscilar un pin digital de ALTO a BAJO en una frecuencia establecida con el analogWritevalor utilizado para determinar la parte del tiempo que el pin está en ALTO o BAJO. El resultado final es que el voltaje promedio a lo largo del tiempo coincide con el analogWriteparámetro, pero en cualquier momento, el voltaje solo puede ser ALTO o BAJO.

Hay algunas formas de obtener una verdadera salida analógica de un Arduino. La forma en que usé eso funcionó fue construir una escalera de resistencia R-2R . Específicamente, construí un convertidor de digital a analógico de 2 bits usando un montón de resistencias que tienen la misma resistencia. El resultado final es que puedo usar dos pines digitales para fabricar un voltaje que puede estar en uno de los cuatro niveles de voltaje entre BAJO y ALTO. Puedo usar esto para lograr el resultado deseado.

El circuito completo está abajo. Hay dos botones que controlan cada uno de los dos tonos. Presionar ambos botones al mismo tiempo genera ambos tonos.

http://ixora.io/images/itp/pcomp/week4/resisitor_ladder_bb.png

arduino conectado a la placa de prueba con dos botones conectados con resistencias pull-up y un lío de resistencias conectadas a un altavoz, conectado a tierra.
El circuito por sí solo no es suficiente. El código Arduino debe escribirse con cuidado para permitirle cambiar los bits a intervalos precisos. Tuve que hacer algunas pruebas de rendimiento para medir qué tan rápido digitalWritees la función (4 microsegundos), lo cual es muy importante para esta aplicación. Nada es instantáneo con las computadoras y, a veces, eso importa.
