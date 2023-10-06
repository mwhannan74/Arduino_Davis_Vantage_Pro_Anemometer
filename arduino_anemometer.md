10/1/2023

We will be using the Adafruit Metro M4 board for this tutorial.

<https://learn.adafruit.com/adafruit-metro-m4-express-featuring-atsamd51>

# Setting up you IDE

## Installing the Adafruit Metro M4 Arduino board:

Adafruit provides a complete tutorial for the install here:
<https://learn.adafruit.com/add-boards-arduino-v164/setup>. Here is a
summary of the key steps.

1)  Create a "new sketch".

2)  Save the sketch. The IDE will automatically create a folder with the
    same name in the location you select. Your sketch will be in this
    folder. It is important that the folder and sketch have the same
    name and that the sketch is under this folder.

3)  Go to File/Preferences. Click on the Settings tab. Click on the icon
    next to the "Additional board managers URLs". Add the following URL:
    https://adafruit.github.io/arduino-board-index/package_adafruit_index.json

4)  Go to Tools/Board/Board Manager. This will open up the Board Manger
    browser in the left side.

    1.  Search for: SAMD Boards

    2.  INSTALL the "Adafruit SAMD Boards"

5)  Go to Tools/Board/Adafruit SAMD Boards and select the "Adafruit
    Metro M4 (SAMD51)" board

6)  You should now see "Adafruit Metro M4 (SAMD51)" under Tools/Board:

## Connecting the Adafruit Metro M4 board:

1)  Plug the board into a USB port on your computer.

2)  Go to Tools/Port and select the port that your board is connected
    to. For example, COM3 (Adafruit Metro M4 (SAMD51))

3)  Test that you are connected by clicking on Tools/Get Board Info. You
    should get a popup with the basic info about the board (BN, VID,
    PID, SN).

You are now ready to start programming and executing code on you
Arduino!

# Davis Instruments Vantage Pro2 Anemometer (Wind Sensor)

The Davis Vantage Pro2 weather station is a research-grade weather
station that provides professional-grade data for weather enthusiasts,
researchers, growers, and weather professionals. It reports wind speeds
up to 200 mph and wind direction.

<https://www.davisinstruments.com/products/anemometer-for-vantage-pro2-vantage-pro>

<https://www.amazon.com/Davis-Instruments-Anemometer-Vantage-Pro2/dp/B004GK9MFO>

Key features of the Vantage anemometer are:

1)  Wind vane with a variable resistance potentiometer that indicates
    wind direction.

2)  Wind cups and magnetic sensor with pulse output (open drain to
    ground transistor) for wind speed measurement.

3)  An integrated 4-wire, 26 AWG, 40’ cable that has a standard RJ-11
    connector.

# Interfacing the Anemometer with an Arduino

The pinout for the Adafruit Metro M4 is located here:

<https://learn.adafruit.com/adafruit-metro-m4-express-featuring-atsamd51/pinouts>.

This board uses the same basic layout as the Arduino UNO. The pin names
and locations should be the same. The Metro M4 does have a few extra
items like a NeoPixel. It is important to note that the **M4 operates at
3.3V and not 5V.**

## RJ-11 connector

You will need a RJ-11 connector breakout board to access the wire of the
anemometer. One option is the “RJ11 6P6C Connector Breakout Board Module
RA Screw terminals” from MDFLY and is available on Amazon (\$7.40).

<https://www.amazon.com/gp/product/B0BC172XGK/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1>

## Wind vane

The wind van’s shaft is connected to a potentiometer. As the wind
changes the direction of the van, the potentiometer reads 0.0 kOhms at
its “North” position (0 deg) and 10.0 kOhms at its “South” position (180
deg).

To read this sensor with an Arduino you need to use an Analog to Digital
Converter (ADC). There are 6 pins that can be used for analog inputs.
They are labeled A0-A5. Note that the Arduino returns the number of ADC
bits that are measured and not the actual voltage.

You can find the Arduino ADC tutorial here:

<https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage>

The basic steps for the Metro M4 10 bit ADC, ADC Vref=3.3Volts (5V is
not supported by Metro M4), and pin A0:

1)  **Read the voltage on the pin:** int adcBits = analogRead(A0);

2)  **Convert from bits to volts:** float voltage = adcBits \* (3.3 /
    1023.0);

Note that the ADC is 10 bits and that equates to 1024 values, which
range from 0-1023 values. Thus using the equation above, we get 1023bits
\* (3.3V / 1023bits) = 3.3V.

For the wind vane, you technically do not need the actual voltage. You
can directly convert from bits to heading angle:

> float heading_deg = ((float)adcBits / 1024.0) \* 360.0;
>
> \*Note that if you use 1024 (instead of 1023) in the conversion,
> adcBits = 1023 will give you slightly less than 360°. This ensures
> that your maximum reading doesn't roll back to North.

For the Vantage Pro, you need to hook up three wires.

- **Red wire**: Ground

- **Yellow wire**: 3.3V reference voltage for potentiometer

- **Green wire**: Voltage signal output from the potentiometer that
  determines direction

## Wind cups

The wind cups spin on a shaft that has a magnetic pickup sensor. This
sensor outputs a fixed number of pulses for every rotation of the shaft.

To read this sensor with an Arduino you need to use a digital input.
There are 13 pins that can be used for digital inputs. They are labeled
0-13.

You can find the Arduino digital GPIO tutorial here:

<https://www.electronicwings.com/arduino/digital-gpio-of-arduino>

Interfacing with the pulse output for the Vantage Pro is more advanced
than just hooking it up as a standard digital input. The interface to
the sensor is defined as an “open drain to ground.” What this means is
that the sensor acts like a switch. When it is not activated (open) the
signal line is not connected to ground and no current can flow through
the switch. The signal is in a “floating” state. When activated (closed)
the sensor closes the circuit and connects the signal line to ground and
current can flow. The signal is in a “grounded” state.

In order to use this style sensor, we need to connect the signal line to
a digital-level voltage source via a “pull-up” resistor. When the sensor
is in the open state, the signal line will now be “pulled up” to a high
value. When the sensor is in the closed state, the signal will now be
pulled low to ground. The pull-up resistor ensures that the voltage
source is not “shorted” directly to the ground in the closed state.

The basic steps for using a digital input with pull-up resistor on pin
1:

1)  **In setup(), configure the pin:** pinMode(1, INPUT_PULLUP);

2)  **In loop(), read the pin’s state:** int value = digitalRead(pin);

However, to count pulses this is not exactly the best method. The above
requires you sample the pin fast enough that you do not miss any
transitions in the signal’s state. The correct method is to use an
“**interrupt**.”

You can find the Arduino Interrupts tutorial here:

<https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/>

<https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/>

The basic steps for using an interrupt to read a digital input with
pull-up resistor on pin 1:

1)  **Define a global variable:** volatile unsigned long pulseCount = 0;

2)  **Write an interrupt function:** void countPulse() {pulseCount++;}

3)  **In setup(), configure the pin:** pinMode(1, INPUT_PULLUP);

4)  **In setup(), attach the function to the interrupt:**
    attachInterrupt(digitalPinToInterrupt(1), countPulse, RISING);

5)  **In loop(), read the value of the global variable:**

> noInterrupts(); // Disable interrupts
>
> unsigned long pulseCountCopy = pulseCount; // count since last read
>
> pulseCount = 0; // reset the count
>
> interrupts(); // Enable interrupts

You will also need to use the millis() function to compute the time
between reading the pulse count.

1)  **Define a global variable:** unsigned long timePrev_ms = 0;

2)  **In loop(), calculate how much time has passed:**

> unsigned long timeNow_ms = millis();
>
> unsigned long elapsedTime_ms = timeNow_ms - timePrev_ms;
>
> float elapsedTime_sec = (float)elapsedTime_ms / 1000.0;
>
> timePrev_ms = timeNow_ms;

Now that you can count the pulses and how much time has elapsed between
counts, you can calculate the wind speed using the following equation.

float speed_mph = (float)pulseCountCopy \* (2.25 / elapsedTime_sec);

For the Vantage Pro, you need to hook up two wires.

- **Red wire**: Ground

- **Black wire**: Pulse single output

# Serial Output

To see the values that you measured and calculated, you can use the
serial output capability of the Arduino and the Arduino IDE’s integrated
tools “Serial Monitor” and “Serial Plotter”.

You can find the Arduino Serial information here:
<https://www.arduino.cc/reference/en/language/functions/communication/serial/>

## Configuring the serial port

The basic steps to setting up the serial capability of the Arduino:

1)  **In setup(), configure the port:** Serial.begin(115200);

## Using the Serial capability

Using the Serial capability is easy, but has a few quirks. There are two
basic commands that you can call in the loop() function.

- Serial.print()

  - <https://www.arduino.cc/reference/en/language/functions/communication/serial/print/>

  - Prints data to the serial port as human-readable ASCII text.

  - It does NOT automatically append a carriage return ('\r') to the
    output.

  - It can print strings/text as well as variables, but not both at the
    same time. You will need to use multiple Serial.print() calls to
    create more complex output. Here is an example of printing a more
    complex output of a string/text and a variable.

> Serial.print(“My variable: ”); Serial.print(myVariable);
> Serial.print(“\r”);

- Serial.println()

  - <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>

  - Same as Serial.print() but it DOES automatically append a carriage
    return ('\r') to the output.

> Serial.println(“Hello World”);

## Serial Monitor

The serial monitor allows you to directly read the serial output. You
can access it by going to Tools/Serial Monitor. The only thing that you
need to do is make sure the baud rate is set to the same thing you chose
for Serial.begin().

<https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor>

## Serial Plotter

The serial plotter allows you to automatically plot data sent using
Serial. You can access it by going to Tools/Serial Plotter. Like the
serial monitor, you need to make sure the baud rate is set to the same
thing you chose for Serial.begin().

The serial plotter requires your data to formatted in a specific way for
it to work. It requires the following simple format for a single line
that is repeated for each update you want of the plotter.

- Serial.print("Variable_1:");

- Serial.print(var1);

- Serial.print(",");

- Serial.print("Variable_2:");

- Serial.print(var2);

- …. Continue for all of your variables

- Serial.println(); // terminate line using ‘/r’

The serial plotter will automatically plot and create a legend for your
data. Note that the data will all be plotted using the same Y-axis
scale. So, be sure your data is all close to the same range.

<https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-plotter>
