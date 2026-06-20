# Hermes Motion Meter

For my Hermes project, I made a compact handheld motion detector based on the MPU6050 IMU, a XIAO RP2040 microcontroller, and a 0.96" OLED screen. The board reads acceleration and rotational values of the sensor and outputs it on the screen.

I decided to use the MPU6050 because I wanted to know more about IMUs and how to make a device which detects motion. Also, since the MPU6050 communicates using I²C protocol, it helped me understand such concepts as pull-up resistors, datasheets, decoupling capacitors, and PCB designing.

## Schematic

The circuit board is controlled by the XIAO RP2040. Both the MPU6050 and the OLED display are connected through the I²C bus, meaning that they use common SDA and SCL pins.

### Connections

* XIAO RP2040
* MPU6050 IMU
* 0.96" I²C OLED Display

The MPU6050 is connected as follows:

* VDD → 3.3V
* VLOGIC → 3.3V
* GND → GND
* SDA → SDA
* SCL → SCL
* AD0 → GND
* INT → GPIO D6

The OLED screen is connected to the same I²C bus:

* VCC → 3.3V
* GND → GND
* SDA → SDA
* SCL → SCL

Two 4.7kΩ pull-up resistors were used for the SDA and SCL pins in order to follow the I²C specification.

Also, the MPU6050 employs decoupling capacitors in order to stabilize the voltage and minimize noise.

![Schematic](image/schematic.png)

## PCB Design

The board was created in KiCad.

As MPU6050 is a tiny QFN device, I spent much time making sure that everything in the datasheet and footprint was checked properly. Routing the board was quite easy due to the fact that most of the connections were only four pins:

* SDA
* SCL
* 3V3
* GND

OLED and XIAO RP2040 are connected via headers, whereas MPU6050 and passives were soldered to the PCB.

Additionally, I have added silkscreen labels in order to simplify the assembly process.

![PCB](images/pcb.png)
![PCB](images/3d.png)

## Bill of Materials

| Part                | Function                       | Quantity |
| -------------------- | ------------------------------ | -------- |
| XIAO RP2040         | Microcontroller                | 1        |
| MPU6050             | Accelerometer & Gyroscope      | 1        |
| 0.96" OLED Display  | Sensor display                 | 1        |
| 4.7kΩ Resistor      | I²C Pull-up                    | 2        |
| 0.1µF Capacitor     | Decoupling capacitor           | 2        |
| 1µF Capacitor       | Filtering capacitor            | 1        |
| Custom PCB          | Board                          | 1        |

## Assembly

Upon receiving the PCB and components, I proceeded to assemble the circuit.

The MPU6050 module was the hardest part due to its tiny size; I applied flux and soldered each pin making sure there were no solder bridges. After the MPU6050 module had been soldered, all other components were much easier to solder.

Then I soldered passive components, and after that the OLED header and the XIAO RP2040 headers.

After assembling the board, I flashed the firmware and tested whether the sensor was working using I²C.


## Firmware

Firmware is used to initialize MPU6050 and OLED via the I²C bus.

Display shows:

* X axis, Y axis, and Z axis acceleration 
* X axis, Y axis, and Z axis rotation rate
* Real-time motion of the device

XIAO RP2040 is always reading data from MPU6050 and updating OLED display.

## What I Learned

From this project, I learned about:

* Datasheets reading
* Schematics designing
* PCB routing
* I²C protocol
* Pull-up resistors
* Decoupling capacitors
* Surface mount soldering
* Motion sensors usage

Overall, Hermes was an enjoyable project that provided a lot of valuable experience in developing a custom-made sensor board.