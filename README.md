# DungeonExplorer
Proyecto para la materia de Programacion de estructuras de datos y algoritmos fundamentales.
## Cómo compilar
 
Desde la carpeta `entrega1`:
 
```
g++ -std=c++17 -Wall *.cpp -o dungeon
```
 
## Cómo ejecutar
 
```
dungeon          # semilla aleatoria
dungeon 42       # semilla fija: la misma semilla produce la misma partida
```
 
El programa muestra la semilla al iniciar, para poder repetir cualquier partida. Después pide el nombre del jugador y su raza (1 = Elf, 2 = Human, 3 = Dwarf).
 
Los archivos `data/monsters.csv` y `data/spells.csv` deben estar en la carpeta `data/` junto al ejecutable. Se asume que ambos CSV están bien formados.
 
## Estructura
 
| Archivo | Contenido |
| --- | --- |
| `nodo.h`, `listaDoble.h` (+ `.tpp`) | Nodo y lista doblemente ligada genérica, con merge sort sobre nodos |
| `Monstruo` | TDA de una criatura |
| `Codice` | Carga `monsters.csv` y elige monstruos al azar |
| `Hechizo` | TDA de un hechizo o habilidad |
| `LibroHechizos` | Carga `spells.csv`, búsqueda y filtros |
| `Jugador` | Estado del jugador, su libro y los monstruos derrotados |
| `Cuarto`, `Mapa` | Un cuarto con su monstruo y el mapa lineal de 20 cuartos |
| `Juego` | Une todo: combate, bitácora y resumen final |
| `main.cpp` | Lee la semilla y ejecuta el juego |
 
## Reglas del combate
 
En cada turno el monstruo ataca con 1d10. Si el jugador sigue vivo, actúa con esta regla:
 
1. **Curarse:** si su HP es menor a 30, no se curó en el turno anterior y puede pagar un hechizo de curación, usa el primero que encuentre.
2. **Hechizo de daño:** si no se curó, usa el hechizo de daño con mayor promedio que pueda pagar con su MP. Reemplaza el ataque con d10.
3. **Ataque normal:** si no puede pagar ningún hechizo, ataca con 1d10.
Al vencer a un monstruo, el jugador recupera 2d20 de HP. El MP no se recupera durante la partida, así que el jugador gasta su MP en hechizos fuertes al principio y después depende de las habilidades de 0 MP.
 
## Decisiones de diseño
 
- **Una sola semilla para toda la partida:** `Juego` tiene el único generador `std::mt19937`. Por eso `Mapa::generar`, `Codice::monstruoAleatorio` y `Hechizo::tirarEfecto` lo reciben como parámetro.
- **Costo de MP:** D&D no usa MP, así que se definió cantrip = 2 MP, nivel n = 5 × n MP y habilidades = 0 MP. Inflict Wounds cuesta 15 MP en lugar de 5 porque su daño (3d10) es alto para un hechizo de nivel 1.
- **Copias de monstruos:** cada cuarto guarda su propia copia del monstruo, así que dos cuartos con la misma criatura no comparten HP.
## Fuentes de los hechizos
 
Los 15 hechizos y habilidades se tomaron del SRD 5e (System Reference Document de D&D 5e), consultado en [5esrd.com](https://www.5esrd.com/database/spell). Los dados se simplificaron: no se suman los bonos fijos del SRD (por ejemplo, Magic Missile queda como 3d4).
 
| Nombre | Tipo | Fuente |
| --- | --- | --- |
| Fire Bolt | Hechizo | SRD 5e |
| Ray of Frost | Hechizo | SRD 5e |
| Sacred Flame | Hechizo | SRD 5e |
| Magic Missile | Hechizo | SRD 5e |
| Burning Hands | Hechizo | SRD 5e |
| Guiding Bolt | Hechizo | SRD 5e |
| Cure Wounds | Hechizo | SRD 5e |
| Healing Word | Hechizo | SRD 5e |
| Shatter | Hechizo | SRD 5e |
| Prayer of Healing | Hechizo | SRD 5e |
| Inflict Wounds | Hechizo | SRD 5e |
| Fireball | Hechizo | SRD 5e |
| Mass Cure Wounds | Hechizo | SRD 5e |
| Second Wind | Habilidad (Fighter) | SRD 5e |
| Divine Smite | Habilidad (Paladin) | SRD 5e |

Este README fue realizado con apoyo de la IA para el formato de listas y detalles esteticos.